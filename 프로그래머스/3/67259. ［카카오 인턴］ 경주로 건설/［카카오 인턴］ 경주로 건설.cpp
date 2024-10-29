#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<vector<int>>> visits;
vector<vector<int>> maps;
int n, answer = 987654321;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Q {
    int m, x, y, idx;
    
    bool operator<(const Q &other) const{
        return m > other.m;
    }
};
void bfs(){
    priority_queue<Q> q;
    q.push({0, 0, 0, -1});
    visits[0][0][0] = 0;
    while(!q.empty()){
        Q cur = q.top();
        q.pop();
        if (cur.m > visits[cur.x][cur.y][cur.idx]) continue;
        for (int i = 0 ; i < 4 ; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (maps[nx][ny]) continue;
            int t_sum = (cur.idx == i || cur.idx == -1 ? cur.m + 100 : cur.m + 600);
            if (t_sum >= visits[nx][ny][i]) continue;
            visits[nx][ny][i] = t_sum;
            q.push({t_sum, nx, ny, i});
        }
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    visits.assign(n, vector<vector<int>>(n, vector<int>(4, 987654321)));
    maps = board;
    bfs();
    return min(min(visits[n-1][n-1][0], visits[n-1][n-1][1]), min(visits[n-1][n-1][2], visits[n-1][n-1][3]));
}