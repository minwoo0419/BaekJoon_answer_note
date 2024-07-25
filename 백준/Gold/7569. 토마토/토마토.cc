#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, h;
int tomato[101][101][101];
int visits[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int main(int argc, char** argv)
{
    queue< pair< pair<int, int>, int> > q;
    cin >> n >> m >> h;
    for (int i = 0 ; i < h ; i++){
        for (int j = 0 ; j < m ; j++){
            for (int k = 0 ; k < n ; k++){
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push(make_pair(make_pair(i, j), k));
                    visits[i][j][k] = 1;
                }
            }
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 6 ; i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nz < 0 || nz >= h || nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visits[nz][nx][ny] || tomato[nz][nx][ny] != 0)
                continue;
            q.push(make_pair(make_pair(nz, nx), ny));
            visits[nz][nx][ny] = visits[z][x][y] + 1;
        }
    }
    for (int i = 0 ; i < h ; i++){
        for (int j = 0 ; j < m ; j++){
            for (int k = 0 ; k < n ; k++){
                if (visits[i][j][k] == 0 && tomato[i][j][k] != -1){
                    cout << -1;
                    return 0;
                } else if (visits[i][j][k])
                    cnt = max(cnt, visits[i][j][k] - 1);
            }
        }
    }
    cout << cnt;
    return 0;
}
