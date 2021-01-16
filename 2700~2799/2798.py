# 첫째 줄 N(카드수), M(한계)
line1 = input().split(' ')
# 둘째 줄 N1, N2, N3, ...
line2 = input().split(' ')

N = int(line1[0])
M = int(line1[1])

# 입력받은 카드들
cards = [int(i) for i in line2]

# 최대값
maximum = 0

for i in cards:
    for j in cards:
        if j == i:
            continue
        for k in cards:
            if j == k or k == i:
                continue
            hap = i+j+k
            # 세 장의 합이 M을 넘지 않는다면 저장
            if hap <= M and hap > maximum:
                maximum = hap

# 결과 출력
print(maximum)
