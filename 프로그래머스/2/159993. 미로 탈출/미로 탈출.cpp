#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<string> v;
int bfs(int sx, int sy, int ex, int ey){
    vector<vector<int>> visits(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visits[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == ex && y == ey)
            break;
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visits[nx][ny] || v[nx][ny] == 'X')
                continue;
            visits[nx][ny] = visits[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return visits[ex][ey];
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    v = maps;
    int sx = 0, sy = 0, lx = 0, ly = 0, ex = 0, ey = 0;
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[i].size() ; j++){
            if (maps[i][j] == 'S'){
                sx = i;
                sy = j;
            } else if (maps[i][j] == 'L'){
                lx = i;
                ly = j;
            } else if (maps[i][j] == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    int a = bfs(sx, sy, lx, ly);
    int b = bfs(lx, ly, ex, ey);
    if (a == 0 || b == 0)
        return -1;
    return a + b - 2;
}