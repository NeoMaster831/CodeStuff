from z3 import *

v2 = Int('v2')
v3 = Int('v3')

s = Solver()
s.add(And(v2 >= 0, v2 < 0x80000000))
s.add(And(v3 >= 0, v3 < 0x80000000))
s.add((v2 ** 4) - 3 * (v2 ** 2) * v3 + (v3 ** 2) == 208398105)

print(s.check())
print(s.model())

#123 456 c0m0r1bb