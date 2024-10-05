#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
vector<string> maps;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(int a, int b){
    int maxx = 0;
    queue<pair<int, int> > q;
    vector<vector<int> > visits(n, vector<int>(m, 0));
    q.push(make_pair(a, b));
    visits[a][b] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visits[nx][ny]) continue;
            if (maps[nx][ny] == 'W') continue;
            visits[nx][ny] = visits[x][y] + 1;
            maxx = max(maxx, visits[nx][ny]);
            q.push(make_pair(nx, ny));
        }
    }
    return maxx - 1;
}
int main(int argc, char** argv)
{
    int answer = 0;
    cin >> n >> m;
    maps.assign(n, "");
    for (int i = 0 ; i < n ; i++){
        cin >> maps[i];
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (maps[i][j] == 'W') continue;
            answer = max(bfs(i, j), answer);
        }
    }
    cout << answer;
    return 0;
}