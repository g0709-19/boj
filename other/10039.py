sum = 0
STUDENT = 5
BOCHUNG = 40
for i in range(STUDENT):
    temp = int(input())
    if temp < BOCHUNG:
        temp = BOCHUNG
    sum += temp
print(int(sum/STUDENT))