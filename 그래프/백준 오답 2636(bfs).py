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
                    if cheese[nx][ny] == 0: #공기일 경우
                        melt.append((nx, ny))   #현재 큐에 추가해서 bfs
                    elif cheese[nx][ny] == 1:   #공기와 인접한 치즈일 경우
                        find.append((nx, ny))   #다음 함수에서 사용하기 위해 다음 큐(find)에 추가 @@현재 큐에 넣으면 공기에 안 닿는 치즈도 탐색할 수 있으므로
    if find:
        return bfs(find, time + 1)  #공기에 닫는 치즈로 bfs
    else:
        return time, count
visit[0][0] = 1
time, count = bfs(melt, 0)
print(time)
print(count)