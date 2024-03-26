n, m = map(int, input().split())
cheese = [list(map(int, input().split())) for i in range(n)]
visit = [list(0 for i in range(m)) for i in range(n)]
melt = [(0,0)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(melt, time):
    count = len(melt)
    find = []
    while melt:
        x, y = melt.pop(0)
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx >= 0 and nx < n) and (ny >= 0 and ny < m):
                if visit[nx][ny] == 0:
                    visit[nx][ny] = 1
                    if cheese[nx][ny] == 0:
                        melt.append((nx, ny))
                    elif cheese[nx][ny] == 1:
                        find.append((nx, ny))
    if find:
        return bfs(find, time + 1)
    else:
        return time, count
time, count = bfs(melt, 0)
print(time)
print(count)