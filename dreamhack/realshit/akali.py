with open('./multipoint', 'rb') as f:
    data = f.read()

unk = data[0x1020:0x1BD1C]
byte1bd20 = data[0x1bd20:0x1bd20+38]
enc_v6 = data[0x1bd60:0x1bd60+38]

# f[x][y] = v6, buf
f = [ [0 for _ in range(38)] for _ in range(38) ]
for i in range(len(unk) // 4):
    _20, _21, _22, _23 = unk[i*4], unk[i*4+1], unk[i*4+2], unk[i*4+3]
    f[_20][_21] += byte1bd20[_22] * _23

from sympy import Matrix, mod_inverse

# 모듈로 251의 행렬식을 계산하는 함수
def mod_determinant(matrix, modulus):
    det = matrix.det()  # sympy의 det 함수 사용
    return det % modulus  # 모듈로 연산 적용

# 모듈로 251에서 역원을 계산하는 함수
def mod_inverse_251(value):
    return mod_inverse(value, 251)

# 크라메르 법칙을 이용해 해를 구하는 함수
def solve_cramer(mat, consts, modulus):
    det = mod_determinant(mat, modulus)  # 원본 행렬의 행렬식 계산
    if det == 0:
        return None  # 행렬식이 0이면 해가 없거나 여러 개 있음
    
    det_inv = mod_inverse_251(det)  # 행렬식의 모듈로 251에 대한 역원
    solutions = []
    
    for i in range(len(consts)):
        mat_copy = mat.copy()  # 원본 행렬 복사
        mat_copy[:, i] = consts  # i번째 열을 상수 벡터로 대체
        det_i = mod_determinant(mat_copy, modulus)  # 변경된 행렬의 행렬식 계산
        solution_i = (det_i * det_inv) % modulus  # 해 계산
        solutions.append(solution_i)
    
    return solutions

matrix = Matrix(f)
consts = enc_v6

solutions = solve_cramer(matrix, consts, 251)

print(solutions)

# [68, 72, 123, 80, 111, 108, 121, 95, 109, 48, 108, 121, 95, 109, 117, 108, 116, 49, 112, 108, 49, 99, 52, 116, 49, 111, 110, 95, 109, 48, 100, 117, 108, 97, 114, 126, 33, 125]