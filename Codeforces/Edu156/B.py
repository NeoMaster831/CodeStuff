def dist(x1, x2, y1, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def solve():
    px, py = map(int, input().split())
    if px == 0 and py == 0:
        print(0)
        return
    ax, ay = map(int, input().split())
    bx, by = map(int, input().split())
    p2aorb = min(dist(px, ax, py, ay), dist(px, bx, py, by))
    zero2aorb = min(dist(0, ax, 0, ay), dist(0, bx, 0, by))
    a2b = dist(ax, bx, ay, by)
    zeroa = max(dist(0, ax, 0, ay), dist(px, ax, py, ay))
    zerob = max(dist(0, bx, 0, by), dist(px, bx, py, by))
    print(min(max(a2b / 2, max(p2aorb, zero2aorb)), min(zeroa, zerob)))

T = int(input())
while T > 0:
    solve()
    T -= 1