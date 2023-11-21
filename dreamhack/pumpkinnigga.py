"""
AAAAAAAAAAAAAA: 0x07    0x07    0x0a    0x05    0x0f    0x0d    0x08    0x06
0x7fffffffdd68: 0x0e    0x0b    0x10    0x0a    0x09    0x00    0x0c    0x0d
0x7fffffffdd70: 0x05    0x07    0x0a    0x08    0x10    0x0b
"""

v6 = [ 7, 7, 10, 5, 15, 13, 8, 6, 
      14, 11, 16, 10, 9, 0, 12, 13, 
      5, 7, 10, 8, 16, 11, 17 ]

v8 = [
    52, 50, 99 ,104 ,127 ,127 ,120 ,89 ,122, 84 ,121 ,107 ,124 ,115 ,52 ,102 ,104 ,63 ,99 
]

s = [
    102, 111, 62, 107, 104, 52 ,100, 96, 103, 104, 79, 61 ,126 ,111, 88 ,57 ,90 ,60 ,108, 61 ,127 
]

def yuk1(a):
    b = []
    for i in range(len(a)):
        b.append(a[i] ^ v6[i % 0xd])
    return b

v8 = yuk1(v8)
s = yuk1(s)

hellonigger = "_this_is_sample_flag_"
hel = []
for i in hellonigger:
    hel.append(ord(i))

def yuk2(a: list):
    b = a.copy()
    for i in range(0xc, -1, -1):
        tmp = b[0]
        b[0] = b[v6[i]]
        b[v6[i]] = tmp
    return b

hely = yuk2(hel)
for i in hely:
    print(chr(i), end='')
print('\n')

v8 = yuk2(v8)
s = yuk2(s)

for i in (s + v8):
    print(chr(i), end='')