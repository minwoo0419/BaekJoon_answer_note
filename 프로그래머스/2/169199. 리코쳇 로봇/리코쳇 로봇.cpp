#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<string> maps;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, ans = 0;
int sx = 0, sy = 0, ex = 0, ey = 0;
bool can_stop(int x, int y, int idx){
    int nx = x + dx[idx];
    int ny = y + dy[idx];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] == 'D')
        return true;
    return false;
}

void bfs(){
    queue<pair<int, int>> q;
    vector<vector<int>> visits(n, vector<int>(m, 0));
    q.push(make_pair(sx, sy));
    visits[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int tx = x;
            int ty = y;
            while(!can_stop(tx, ty, i)){
                tx += dx[i];
                ty += dy[i];
            }
            if (!visits[tx][ty]){
                visits[tx][ty] = visits[x][y] + 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
    ans = visits[ex][ey] - 1;
}
int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].length();
    maps = board;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (maps[i][j] == 'R'){
                sx = i;
                sy = j;
            } else if (maps[i][j] == 'G'){
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    return ans;
}