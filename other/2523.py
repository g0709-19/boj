n = int(input()) + 1
for i in range(1, n):
    print('*' * i)
line = list(range(1, n-1))
line.reverse()
for i in line:
    print('*' * i)