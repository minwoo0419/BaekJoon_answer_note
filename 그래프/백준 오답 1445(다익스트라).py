import heapq
n, m = map(int, input().split())
map = [list(input()) for _ in range(n)]
visit = [list(0 for _ in range(m)) for _ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
x, y = 0, 0
for i in range(n):
    for j in range(m):
        if map[i][j] == 'S':
            x, y = i, j
        elif map[i][j] == 'g':
            for k in range(4):
                if i+dx[k] < 0 or i+dx[k] >= n or j+dy[k] < 0 or j+dy[k] >= m:
                    continue
                if map[i+dx[k]][j+dy[k]] == '.':
                    map[i+dx[k]][j+dy[k]] = 'n'

def bfs(a, b):
    que = [(0, 0, a, b)]    #쓰레기를 가장 적게 지나간 길부터 탐색하기 위해 우선순위 큐 사용
    visit[a][b] = 1
    while que:
        pre_di, pre_in, x, y = heapq.heappop(que)
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            di, indi = pre_di, pre_in
            if nx < 0 or nx >= n or ny < 0 or ny >= m or visit[nx][ny] == 1:
                continue
            visit[nx][ny] = 1
            if map[nx][ny] == 'g':
                di += 1
            elif map[nx][ny] == 'n':
                indi += 1
            elif map[nx][ny] == 'F':
                print(pre_di, pre_in)
                break
            heapq.heappush(que, (di, indi, nx, ny))
bfs(x, y)
