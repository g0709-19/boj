n = int(input())
row = n*2
column = n
for x in range(row):
    for y in range(column):
        if x%2 is y%2:
            print('*', end='')
        else:
            print(' ', end='')
    print()