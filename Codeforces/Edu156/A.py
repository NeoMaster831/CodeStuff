def find_triplet(n):
    # When n is 1, 2, or 3, there is no solution
    if n <= 3:
        return "NO", []
    
    # remainder 0
    if n % 3 == 0:
        if n <= 9:
            return "NO", []
        return "YES", [1, 4, n - 5]
    
    # remainder 1
    if n % 3 == 1:
        if n < 7:
            return "NO", []
        return "YES", [1, 2, n - 3]
    
    # remainder 2
    if n % 3 == 2:
        if n < 8:
            return "NO", []
        return "YES", [1, 2, n - 3]

def solve():
    n = int(input())
    res = find_triplet(n)
    print(res[0])
    if len(res[1]) != 0:
        print(res[1][0],res[1][1],res[1][2])

T = int(input())
while T > 0:
    solve()
    T -= 1