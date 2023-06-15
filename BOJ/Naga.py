INF = 1234567890

N = int(input())
lines = []
for i in range(N):
    inp = input()
    k = [ 0, 0, 0 ]
    found = False
    for j in inp.split():
        if j == 'A': k[0] += 1 - 2 * int(found)
        elif j == 'B': k[1] += 1 - 2 * int(found)
        elif j == '1': k[2] += 1 - 2 * int(found)
        elif j == '<': 
            for l in range(len(k)): k[l] = -k[l]
        elif j == '>': found = True
        else: break
    lines.append(k)
N += 2
lines.append([0, 1, 0]); lines.append([1, 0, 0])

dots = []
valid = [True for i in range(0, N)]
for i in lines:
    tmp = INF * i[0] - i[2]
    if i[1] != 0: tmp /= -i[1]
    else:
        dots.append((0, -INF, 0, INF))
        continue
    dots.append((-INF, -tmp, INF, tmp))

for i in range(0, len(lines)):
    for j in lines:
        # Case 1. 일치
        if lines[i] == j: continue
        # Case 2. 평행
        elif lines[i][0] == j[0] and lines[i][1] == j[1] and lines[i][2] != j[2]:
            judge = lines[i][2] > j[2] # i(x)가 j(x) 보다 위에 있음
            judge ^= j[3]
            if not judge:
                valid[i] = False
            continue
        # Case 3. 교차
        else:
            a, b, c = lines[i][0], lines[i][1], lines[i][2]
            if b != 0:
                a1 = -a / b; b1 = -c / b
            else:
                a1 = -INF; b1 = -INF
            ap, bp, cp = j[0], j[1], j[2]
            if bp != 0:
                a2 = -ap / bp; b2 = -cp / bp
            else:
                a2 = -INF; b2 = -INF
            turning_point = (-(b1 - b2) / (a1 - a2), a1 * (-(b1 - b2) / (a1 - a2)) + b1)
            if bp < 0 and dots[i][2] > turning_point[0]:
                dots[i] = (dots[i][0], dots[i][1], turning_point[0], turning_point[1])
            elif bp > 0 and dots[i][0] < turning_point[0]:
                dots[i] = (turning_point[0], turning_point[1], dots[i][2], dots[i][3])

for i in range(5):
    inp = input()
    k = [ 0, 0, 0 ]
    found = False
    for j in inp.split():
        if j == 'A': k[0] += 1 - 2 * int(found)
        elif j == 'B': k[1] += 1 - 2 * int(found)
        elif j == '1': k[2] += 1 - 2 * int(found)
        elif j == '|': found = True
        else: break
    
    preresult = -1
    for i in range(len(dots)):
        if not valid[i]: continue
        if dots[i][0] * k[0] + dots[i][1] * k[1] + k[2] > 0:
            if preresult != 0 or preresult != -1:
                preresult = 2
            preresult = 0
        elif dots[i][0] * k[0] + dots[i][1] * k[1] + k[2] < 0:
            if preresult != 1 or preresult != -1:
                preresult = 2
            preresult = 1
    if preresult == 0: print('<')
    elif preresult == 1: print('>')
    else: print('?')
    
print(lines, dots, valid)