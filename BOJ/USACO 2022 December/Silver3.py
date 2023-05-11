N = int(input())
 
difs = [list(map(int, input().split())) for _ in range(N)]
 
ans = [0]*N
for i in reversed(range(N-1)):
	def ok():
		mx = -float('inf')
		mn = float('inf')
		for j in range(i,N):
			mx = max(mx, ans[j])
			mn = min(mn, ans[j])
			if mx-mn != difs[i][j-i]:
				return False
		return True
	ans[i] = ans[i+1] + difs[i][1]
	if not ok():
		ans[i] = ans[i+1] - difs[i][1]
		assert ok()
 
print(" ".join(map(str, ans)))