from pwn import *
import hashlib

regex = "0123456789abcdef"

v8 = [
    0xFE5D3A093968D02B,
    0xBA0AA367C2862EAE,
    0x8BEA2ADA9E26604F,
    0x2E6F41C96DCF5224,
    0x7FD91BD2949B75F3,
    0x5B1ED8E6072F3A6,
    0xC94045C6D4887611,
    0x9D43DF6DF6B94D95,
    0xB9A8A83C8AC08D80,
    0x6D78E80376518464,
    0xE81A20F2023C2D0,
    0x2E41EAE69D89F186,
    0x425C831DD2A3E5FD,
    0x82788DBBDC4100EC,
    0x6D0FEE8D3901DD20,
    0xEBE82A0A41E5D783,
    0x2AFA26414B72E506,
    0xD1848E9C21D114D
]

ran = range(0x20, 0x7f)
ans = ""

for i in range(0, len(v8)//2):
    tm_raw = p64(v8[i*2]) + p64(v8[i*2+1])
    tm_str = ""
    for b in tm_raw:
        tm_str += regex[(b >> 4) & 0xf]
        tm_str += regex[b & 0xf]
    
    found = False
    for j in ran:
        for k in ran:
            for l in ran:
                to_chk = chr(j) + chr(k) + chr(l)
                if hashlib.md5(to_chk.encode()).hexdigest() == tm_str:
                    ans += to_chk
                    found = True
                    break
            if found: break
        if found: break
    print(ans)

print("I guess this is the flag:", ans)
