def up(p):
    p = p.replace(' ', '').replace('\n', '').replace('?', '')
    sb = []
    for i in range(len(p)//2):
        sb.append(int(p[i*2:i*2+2], 16))
    return sb

encpw = """
22 30 33 38 61 68 74 7E  83 94 B3 BC D1 E0 EB FC
"""
id = "_Adm!nIsTr4T0r_!"
id_l = []
for i in id:
    id_l.append(ord(i))
table = """
63 7C 77 7B F2 6B 6F C5  30 01 67 2B FE D7 AB 76
CA 82 C9 7D FA 59 47 F0  AD D4 A2 AF 9C A4 72 C0
B7 FD 93 26 36 3F F7 CC  34 A5 E5 F1 71 D8 31 15
04 C7 23 C3 18 96 05 9A  07 12 80 E2 EB 27 B2 75
09 83 2C 1A 1B 6E 5A A0  52 3B D6 B3 29 E3 2F 84
53 D1 00 ED 20 FC B1 5B  6A CB BE 39 4A 4C 58 CF
D0 EF AA FB 43 4D 33 85  45 F9 02 7F 50 3C 9F A8
51 A3 40 8F 92 9D 38 F5  BC B6 DA 21 10 FF F3 D2
CD 0C 13 EC 5F 97 44 17  C4 A7 7E 3D 64 5D 19 73
60 81 4F DC 22 2A 90 88  46 EE B8 14 DE 5E 0B DB
E0 32 3A 0A 49 06 24 5C  C2 D3 AC 62 91 95 E4 79
E7 C8 37 6D 8D D5 4E A9  6C 56 F4 EA 65 7A AE 08
BA 78 25 2E 1C A6 B4 C6  E8 DD 74 1F 4B BD 8B 8A
70 3E B5 66 48 03 F6 0E  61 35 57 B9 86 C1 1D 9E
E1 F8 98 11 69 D9 8E 94  9B 1E 87 E9 CE 55 28 DF
8C A1 89 0D BF E6 42 68  41 99 2D 0F B0 54 BB 16
"""

smalltable = """
F8 8E E7 DF A2 99 CE 9A  FD 64 64 4D 4D 17 40 6D
"""

encpw_up = up(encpw)
table_up = up(table)
st = up(smalltable)

avail = []

def dfs(idx, last, bs: list, ret: list):

    if idx == 16:
        for i in range(0, len(ret)):
            print(chr(ret[i] ^ id_l[i] ^ st[i]), end='')
        print()
    for i in range(0, len(encpw_up)):
        if i in bs: continue
        for j in range(0, last+1):
            if (j + table_up[idx ^ (~j & 0xff)]) & 0xff == encpw_up[i]:
                bscp = bs.copy(); retcp = ret.copy()
                bscp.append(i); retcp.append(j)
                dfs(idx + 1, j, bscp, retcp)
dfs(0, 255, [], [])

# guess some shits
"X1~Nx/P?|i?w/4Os"
"^-^p4S$w0r1D._.@"