#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool bfs(int x, int y, vector<string> &p){
    queue<pair<int, int>> q;
    vector<vector<int>> visits(p.size(), vector<int>(p[0].length(), 0));
    q.push(make_pair(x, y));
    visits[x][y] = 1;
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || nx >= p.size() || ny < 0 || ny >= p[0].length())
                continue;
            if (visits[nx][ny] || p[nx][ny] == 'X')
                continue;
            if (p[nx][ny] == 'P'){
                if (visits[tx][ty] <= visits[x][y] + 1){
                    return false;
                }
            }
            visits[nx][ny] = visits[tx][ty] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0 ; i < places.size() ; i++){
        vector<string> p = places[i];
        vector<vector<int>> visits(p.size(), vector<int>(p[0].length(), 0));
        int flag = 0;
        for (int i = 0 ; i < p.size() ; i++){
            if (flag){
                break;
            }
            for (int j = 0 ; j < p[i].length() ; j++){
                if (p[i][j] != 'P')
                    continue;
                if (!bfs(i, j, p)){
                    flag = 1;
                    break;
                }
            }
        }
        flag == 1 ? answer.push_back(0) : answer.push_back(1);
    }
    return answer;
}