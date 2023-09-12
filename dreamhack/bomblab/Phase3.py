from z3 import *

v2 = BitVec('v2', 64)
v3 = BitVec('v3', 64)
v5 = BitVec('v5', 64)

s = Solver()
s.add(v5 == v2 * 450357013)
s.add(v2 > 0xDEADBEEE)
s.add((v2 - v3) / 0x3D == 327871 * (v5 >> 53))
s.add(And(v2 >= 0, v2 <= 0xFFFFFFFF))
s.add(And(v3 >= 0, v3 <= 0xFFFFFFFF))
print(s.check())
print(s.model())

#3982024845 1998765