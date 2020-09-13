n = int(input())
spaces = list(range(n))
stars = [2*i-1 for i in range(1, n+1)]
stars.reverse()
for i in range(len(stars)):
    print(f"{' '*spaces[i]}{'*'*stars[i]}")
stars.reverse()
spaces.reverse()
for i in range(1, len(stars)):
    print(f"{' '*spaces[i]}{'*'*stars[i]}")