temp = input().split(' ')
while '' in temp:
    temp.remove('')
print(len(temp))