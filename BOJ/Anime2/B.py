N, M = map(int, input().split())
A = list(set(map(int, input().split())))

todo = []
for i in range(1, N+1):
    if A.count(i) == 0: todo.append(i)

#print(todo)
ans = 0
for i in range(0, len(todo)):
    if i == 0:
        ans += 7
        continue
    if todo[i] - todo[i - 1] > 3:
        ans += 7
    else:
        ans += 2 * (todo[i] - todo[i - 1])

print(ans)