unk2020 = [
    0x83, 0x9C, 0x89, 0x82, 0x93, 0x9F, 0x89, 0x9F, 0x8D, 0x81, 0x89
]

for i in unk2020:
    print(chr(i ^ 0xcc), end='')

#OPEN_SESAME