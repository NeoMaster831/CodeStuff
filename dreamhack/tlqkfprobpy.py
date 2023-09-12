from z3 import *

s = [Int('s_%d' % i) for i in range(29)]

constraints = [And(char > 0x2F, char <= 0x7F) for char in s]

constraints.append(s[2] + s[4] - s[5] * s[1] - s[0] - s[6] * s[3] == -9063)
constraints.append(s[7] - s[2] + s[6] * s[4] * s[3] - s[5] - s[1] == 680034)
constraints.append(s[6] + s[7] + s[4] + s[3] - s[2] * s[5] + s[8] == -3777)
constraints.append(s[5] + s[7] + s[6] - s[3] * s[4] - s[9] - s[8] == -8577)
constraints.append(s[8] + s[7] + s[5] - s[4] * s[10] + s[9] + s[6] == -10622)
constraints.append(s[9] + s[5] + s[6] - s[11] + s[10] * s[7] + s[8] == 4676)
constraints.append(s[9] + s[7] + s[12] + s[11] + s[9] - s[10] - s[6] == 236)
constraints.append(s[8] + s[7] - s[9] + s[10] * s[11] - s[12] - s[13] == 4150)
constraints.append(s[11] + s[14] + s[8] + s[9] * s[13] - s[12] + s[10] == 9859)
constraints.append(s[14] + s[11] - s[12] + s[9] * s[15] - s[10] + s[13] == 10872)
constraints.append(s[16] + s[14] + s[12] + s[10] - s[11] - s[13] - s[15] == 82)
constraints.append(s[14] - s[11] - s[12] + s[17] - s[15] * s[13] + s[16] == -11601)
constraints.append(s[17] + s[12] * s[13] - s[14] + s[15] * s[16] - s[18] == 17039)
constraints.append(s[13] + s[14] - s[15] * s[16] + s[17] * s[18] - s[19] == 188)
constraints.append(s[17] * s[18] + s[16] + s[14] - s[15] - s[20] * s[19] == -5953)
constraints.append(s[18] + s[16] + s[15] - s[17] - s[19] + s[20] * s[21] == 11455)
constraints.append(s[17] * s[18] + s[16] + s[19] * s[20] - s[21] + s[22] == 17158)
constraints.append(s[17] - s[18] - s[19] * s[20] - s[21] * s[22] - s[23] == -21455)
constraints.append(s[19] * s[20] + s[18] + s[21] * s[22] - s[23] + s[24] == 21494)
constraints.append(s[19] + s[20] - s[25] * s[24] * s[23] * s[22] * s[21] == -7105589)
constraints.append(s[23] + s[20] - s[21] * s[22] - s[24] * s[25] + s[26] == -17967)
constraints.append(s[21] * s[26] - s[24] - s[25] + s[22] * s[23] * s[27] == 431149)
constraints.append(s[27] + s[23] * s[22] + s[24] - s[25] * s[26] - s[28] == -4884)

solver = Solver()
solver.add(constraints)

print("go")
# 문제 해결
if solver.check() == sat:
    model = solver.model()
    result = ''.join([chr(model[char].as_long()) for char in s])
    print("Found string:", result)
else:
    print("No solution found")