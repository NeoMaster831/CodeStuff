def circle_relation(x1, y1, r1, x2, y2, r2):
    # 두 원의 중심 간의 거리를 계산
    d = ((x2 - x1)**2 + (y2 - y1)**2)**0.5
    
    # 두 원의 위치 관계를 판단
    if d == 0:
        if r1 == r2:
            return "-1"
        return "0"
    elif abs(r1 - r2) < d < r1 + r2:
        return "2"
    elif d == r1 + r2 or d == abs(r1 - r2):
        return "1"
    elif d < abs(r1 - r2):
        return "0"
    else:
        return "0"


t = int(input())
for i in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    print(circle_relation(x1, y1, r1, x2, y2, r2))  # 예시: 한 원이 다른 원 안에 있습니다.
