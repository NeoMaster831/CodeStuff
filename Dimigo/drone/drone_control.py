import threading
import socket
import time

# Tello IP Control Variables
# ----------------------------------------------
host = ''
port = 9000
locaddr = (host,port)

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# constants for drones list
DRONES_IP_ADDRESS   = 0
DRONES_IP_PORT      = 1
DRONES_TIMEOUT      = 2
DRONES_OK_STATUS    = 3
DRONES_CURR_CMD     = 4
DRONES_CURR_TIMEOUT = 5

# drones list
drones = [
    # IP address       port, timeout, ok status
    [ '192.168.10.1', 8889, 0, 0, '', 0 ],    # drone 1
                                              # drone 2
                                              # drone 3
                                              # ...
                                              # drone n
]

sock.bind(locaddr)

def recv():
    print ('\nReceive Tread started.\n')
    while True:
        try:
            data, server = sock.recvfrom(1518)

            # if OK status received, stored the status to drone which have same IP address
            for j in range(len(drones)):
                if server[0] == drones[j][DRONES_IP_ADDRESS] and data.decode(encoding="utf-8")=='ok':
                    drones[j][DRONES_OK_STATUS] = 1
                    print("ok")

                    # Once valid response is received by one drone, make expect rest of the drones response to be soon (i.e. timeout 500msec sooner)
                    curr_milli_sec = int(round(time.time() * 1000))
                    for i in range(len(drones)):
                        drones[i][DRONES_TIMEOUT] = curr_milli_sec + 500

        except Exception:
            print ('\nReceive Thread Exception.\n')
            break

# --------------------------------------------------------------------------------------------------------------------------
# Send commands to 2 Tello EDU and checks whether it execute the commands by looking for the 'ok' reply from each IP address.
# If not, the command at timeout will re-send to the drone.
#
# Only for commands that reply OK status.
#
# cmd - the command to do
# timeout - the timeout in milli seconds.
# --------------------------------------------------------------------------------------------------------------------------
def sendCommand2AllNEnsureDo(cmd, timeout):

    cmd = cmd.encode(encoding="utf-8")

    # Reset all OK status and force timeout: ensure commands are send out at 1st entry of the while loop
    for i in range(len(drones)):
        drones[i][DRONES_OK_STATUS] = 0
        drones[i][DRONES_TIMEOUT] = 0

    while True:

        # Send Command to Drones which have not receive OK and did timeout
        current_milli_sec = int(round(time.time() * 1000))
        for i in range(len(drones)):
            if drones[i][DRONES_OK_STATUS] == 0 and drones[i][DRONES_TIMEOUT] < current_milli_sec:
                tello_address = (drones[i][DRONES_IP_ADDRESS], drones[i][DRONES_IP_PORT])
                sent = sock.sendto(cmd, tello_address)
                drones[i][DRONES_TIMEOUT] = current_milli_sec + timeout

        # Check whether all drones receive OK status
        exit_count = 0
        for k in range(len(drones)):
            if drones[k][DRONES_OK_STATUS] == 1:
                exit_count = exit_count + 1

        if exit_count >= len(drones): # break if all drones receive OK status
            break

    return

# --------------------------------------------------------------------------------------------------------------------------
# Send commands to 2 Tello EDU and checks whether it execute the commands by looking for the 'ok' reply from each IP address.
# If not, the command at timeout will re-send to the drone.
#
# Only for commands that reply OK status.
#
# cmd - the command to do
# timeout - the timeout in milli seconds.
# --------------------------------------------------------------------------------------------------------------------------
def sendCommand2All(cmd, timeout):

    cmd = cmd.encode(encoding="utf-8")

    # Reset all OK status and force timeout: ensure commands are send out at 1st entry of the while loop
    for i in range(len(drones)):
        drones[i][DRONES_OK_STATUS] = 0
        drones[i][DRONES_TIMEOUT] = 0


    # Send Command to Drones which have not receive OK and did timeout
    current_milli_sec = int(round(time.time() * 1000))
    for i in range(len(drones)):
        if drones[i][DRONES_OK_STATUS] == 0 and drones[i][DRONES_TIMEOUT] < current_milli_sec:
            tello_address = (drones[i][DRONES_IP_ADDRESS], drones[i][DRONES_IP_PORT])
            sent = sock.sendto(cmd, tello_address)
            drones[i][DRONES_CURR_CMD] = cmd
            drones[i][DRONES_CURR_TIMEOUT] = timeout
            drones[i][DRONES_TIMEOUT] = current_milli_sec + timeout

    return

def main():

    # recvThread create
    recvThread = threading.Thread(target=recv)
    recvThread.start()
    
    sendCommand2AllNEnsureDo('command', 500)
    
    while True:
        key = input()
        if key == "s":
            print("stream on")
            sendCommand2AllNEnsureDo('streamon',500)
        elif key == "f":
            print("forward")
            sendCommand2All('forward 20',4000)
        elif key == 't':
            print("takeoff")
            sendCommand2All("takeoff",7000)
        elif key == 'land':
            print("land")
            sendCommand2All('land',3000)
            sock.close()
            break


if __name__ == '__main__':
    main()