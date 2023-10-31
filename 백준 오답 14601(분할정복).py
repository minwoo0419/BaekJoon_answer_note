k = int(input())
a, b = map(int, input().split())
size = 2**k
map = [list(0 for i in range(size)) for i in range(size)]
x = size - b
y = a - 1
map[x][y] = -1
def check(x, y, size):
    for i in range(x, x+size):
        for j in range(y, y+size):
            if map[i][j] != 0:
                return False
    return True
cnt = 1
def fill(x, y, i):
    if (i > 0):
        global cnt
        size = 2 ** (i-1)
        if (check(x, y, size)):
            map[x+size-1][y+size-1] = cnt
        if (check(x+size, y, size)):
            map[x+size][y+size-1] = cnt
        if (check(x, y+size, size)):
            map[x+size-1][y+size] = cnt
        if (check(x+size, y+size, size)):
            map[x+size][y+size] = cnt
        cnt += 1
        fill(x, y, i-1)
        fill(x+size, y, i-1)
        fill(x+size, y+size, i-1)
        fill(x, y+size, i-1)
fill(0, 0, k)
        
for row in map:
    print(*row)