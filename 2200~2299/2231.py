# 입력
N = int(input())

# 분해합 구하는 함수
def decompose(int_val):
    str_val = str(int_val)
    sum = 0
    for s in str_val:
        sum += int(s)
    return sum + int_val

# 생성자 구하는 함수
def constructor(int_val):
    for i in range(int_val):
        # 0부터 입력받은 수까지 분해합 구해서 같아지는 순간을 구함
        if decompose(i) == int_val:
            return i
    return 0

# 결과 출력
print(constructor(N))