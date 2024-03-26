n = int(input())
board = [0 for i in range(n+1)]
visit = [0 for i in range(n+1)]
count = 0
def check(cnt):
    for i in range(1, cnt):
        if (abs(board[cnt] - board[i]) == cnt - i):
            return False
    return True
def find(cnt):
    if (cnt == n+1):
        global count
        count += 1
        return
    for i in range(1, n+1):
        if (visit[i]):
            continue
        board[cnt] = i
        visit[i] = 1
        if (check(cnt)):
            find(cnt + 1)
        visit[i] = 0
find(1)
print(count)