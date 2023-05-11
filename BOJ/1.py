n = int(input())

cnt = 0; t = n
while t != n or cnt == 0:
    fir = t // 10
    sec = t % 10
    thir = fir + sec
    four = thir % 10
    
    t = sec * 10 + four
    cnt += 1

print(cnt)