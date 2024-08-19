#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> maps, int sx, int sy, int ex, int ey){
    vector<vector<int>> visits(maps.size(), vector<int>(maps[0].size(), -1));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue< pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visits[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size())
                continue;
            if (visits[nx][ny] != -1 || !maps[nx][ny])
                continue;
            visits[nx][ny] = visits[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return visits[ex][ey];
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    return bfs(maps, 0, 0, maps.size()-1, maps[0].size()-1);
}