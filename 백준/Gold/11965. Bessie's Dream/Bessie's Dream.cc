#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<vector<int> > > visits;
vector<vector<int> > maps;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Point{
    int x, y, smell, dist;
    Point(int x, int y, int smell, int dist) : x(x), y(y), smell(smell), dist(dist) {}
    bool operator<(Point o) const {
        return dist > o.dist;
    }
};
void dijkstra(){
    priority_queue<Point> q;
    q.push(Point(0, 0, 0, 0));
    visits[0][0][0] = 0;
    while(!q.empty()){
        Point p = q.top();
        q.pop();
        if (p.dist > visits[p.x][p.y][p.smell]) continue;
        for (int i = 0 ; i < 4 ; i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int smell = p.smell;
            int dist = 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0) continue;
            else if (maps[nx][ny] == 3 && smell == 0) continue;
            else if (maps[nx][ny] == 4){
                while(1){
                    if (nx + dx[i] < 0 || nx + dx[i] >= n || ny + dy[i] < 0 || ny + dy[i] >= m) break;
                    if (maps[nx + dx[i]][ny + dy[i]] == 3 && smell == 0) break;
                    if (maps[nx + dx[i]][ny + dy[i]] == 0) break;
                    nx += dx[i];
                    ny += dy[i];
                    dist++;
                    if (maps[nx][ny] != 4) break;
                }
            }
            if (maps[nx][ny] == 2) smell = 1;
            if (p.dist + dist >= visits[nx][ny][smell]) continue;
            visits[nx][ny][smell] = p.dist + dist;
            q.push(Point(nx, ny, smell, visits[nx][ny][smell]));
        }
    }
}
int main() {
    cin >> n >> m;
    maps.assign(n, vector<int>(m, 0));
    visits.assign(n, vector<vector<int> >(m, vector<int>(2, 987654321)));
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> maps[i][j];
        }
    }
    dijkstra();
    int answer = min(visits[n-1][m-1][0], visits[n-1][m-1][1]);
    if (answer == 987654321) answer = -1;
    cout << answer;
    return 0;
}