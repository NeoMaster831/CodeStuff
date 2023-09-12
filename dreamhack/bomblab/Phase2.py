
start = 0
for i in range(1, 7):
    print(start)
    start = ((i * (i + 1)) >> 1) + start
# 0 1 4 10 20 35