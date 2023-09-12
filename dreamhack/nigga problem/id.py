def up(p):
    p = p.replace(' ', '').replace('\n', '').replace('?', '')
    sb = []
    for i in range(len(p)//2):
        sb.append(int(p[i*2:i*2+2], 16))
    return sb

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

enc = """
68 F0 6E 0E 82 69 88 96  5A F7 83 1B 63 3F BF CA
"""

tablel = up(table)
encl = up(enc)
encsibal = encl.copy()

encl[0] = tablel.index(encl[0])
encl[0] &= 0b11111100
for i in range(encl[0], encl[0]+4):
    _4bit_reverse = lambda x: (x >> 4) | ((x * 16) & 0xFF)
    preres = _4bit_reverse(i)
    last = preres
    should_last = preres
    l = [ chr(preres) ]
    encr = encl.copy()

    unav = False
    for j in range(1, len(encr)):
        encr[j] = tablel.index(encr[j])
        encr[j] &= 0b11111100

        cant = True
        for k in range(encr[j],encr[j]+4):
            res = _4bit_reverse(k)
            # guess what?
            if j == 7 and chr(res) == 'c': continue
            if j == 8 and chr(res) == 'D': continue
            if j == 9 and chr(res) == 'b': continue
            if j == 10 and chr(res) == '$': continue
            if j == 11 and chr(res) == 'D': continue
            if j == 12 and chr(res) == ' ': continue
            if j == 13 and chr(res) == 'b': continue
            if j == 14 and chr(res) == 'O': continue
            xored = _4bit_reverse(last) ^ ((res & 0b01100000) >> 5)
            if tablel[_4bit_reverse(last) ^ ((res & 0b01100000) >> 5)] == encsibal[j - 1]:
                l.append(chr(res))
                print(l)
                last = res
                cant = False
                break
        if cant:
            unav = True
            break
    if unav:
        continue
    for q in l:
        print(q, end='')

# _Adm!nIsTr4T0r_!