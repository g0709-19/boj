inp = input().split(' ')
N = int(inp[0])
M = int(inp[1])
li = list()

# 키보드 입력
for i in range(N):
    li.append(input())

# 파일 입력
# file = '1018.dat'
# with open(file, 'r') as f:
#     while True:
#         line = f.readline()
#         if not line: break
#         li.append(line)

# x, y 기점으로 8x8 체스칸 검사
def getCount(li, x, y):
    count_w = 0
    count_b = 0
    for i in range(x, x+8):
        for j in range(y, y+8):
            if (i+j)%2 == 0:
                if 'B' == li[i][j]:
                    count_w += 1
                else:
                    count_b += 1
            else:
                if 'B' == li[i][j]:
                    count_b += 1
                else:
                    count_w += 1
    return min(count_b, count_w)

# 모든 경우 회수 저장
counts = list()
for i in range(N-8+1):
    for j in range(M-8+1):
        count = getCount(li, i, j)
        counts.append(count)

# 최소값 출력
print(min(counts))
