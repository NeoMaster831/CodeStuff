def up(p):
    p = p.replace(' ', '').replace('\n', '').replace('?', '')

unk = """
66 0C 4C 86 A6 2C 1C 9C  1C 66 1C 2C 9C 6C A6 CC
A6 6C 6C AC A6 A6 86 4C  2C 46 EC 8C EC 46 8C 9C
4C EC C6 66 4C 46 86 4C  D2 04 ?? ?? ?? ?? ?? ??
"""

up(unk)