
str2 = """
2B 44 1B 52 2B 5E 1B 05  01 6E 19 5E 0F 63 01 01
2B 74 20 4E 15 46 3C 77  7C 43
"""

str2 = str2.replace(' ', '').replace('\n', '')
sb = []
for i in range(len(str2)//2):
    sb.append(int(str2[i*2:i*2+2], 16))

for i in range(0, 0x1A):
    sb[i] ^= sb[ & 0x19]

for i in sb:
    print(chr(i),end='')