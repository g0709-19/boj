N = int(input())
temp = 666 - 1
i = 0

def count(number):
    count = 0
    string = str(number)
    limit = len(string) - 3 + 1
    for i in range(limit):
        if string[i:i+3] == '666':
            count += 1
    return count

while i < N:
    temp += 1
    if count(temp) >= 1:
        i += 1

print(temp)