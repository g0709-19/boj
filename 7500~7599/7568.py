line = int(input())
li = list()
for i in range(line):
    val = input().split(' ')
    x = int(val[0])
    y = int(val[1])
    li.append((x, y))

result = list()
for x, y in li:
    k = 1
    for p, q in li:
        if x < p and y < q:
            k += 1
    result.append(str(k))

print(" ".join(result))