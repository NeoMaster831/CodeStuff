import math

# 1. 제곱수의 리스트 생성하기
def generate_squares(limit):
    squares = []
    i = 2
    while i**2 <= limit:
        squares.append(i**2)
        i += 1
    return squares

# 2. 포함-배제의 원리를 사용한 계산 함수
def count_non_squarefree_up_to(m, squares):
    total = 0
    visited = set()
    
    # 주어진 숫자들의 조합에 대해 포함-배제 원리 적용
    def dfs(index, lcm, depth):
        nonlocal total
        
        # 제한을 초과하는 경우 제외
        if lcm > m:
            return
        
        # 이미 방문한 숫자는 제외
        if (index, lcm) in visited:
            return
        visited.add((index, lcm))
        
        # 숫자의 개수 계산
        count = m // lcm
        
        # depth가 홀수인 경우 더하고, 짝수인 경우 뺌
        if depth % 2:
            total += count
        else:
            total -= count
            
        # 다음 조합에 대해 재귀 호출
        for i in range(index + 1, len(squares)):
            dfs(i, math.lcm(lcm, squares[i]), depth + 1)
    
    for i, square in enumerate(squares):
        dfs(i, square, 1)
        
    return total

# 3. 이분 탐색 함수
def find_nth_non_squarefree(n, squares):
    low, high = 1, 10**10
    while low <= high:
        mid = (low + high) // 2
        count = count_non_squarefree_up_to(mid, squares)
        
        if count < n:
            low = mid + 1
        else:
            high = mid - 1
            
    return low

# 제곱수 리스트 생성 및 n-th non-squarefree 숫자 찾기
def solution(n):
    squares = generate_squares(10**10)
    return find_nth_non_squarefree(n, squares)

# 예제로 n=10일 때의 결과 테스트
print(solution(10))
