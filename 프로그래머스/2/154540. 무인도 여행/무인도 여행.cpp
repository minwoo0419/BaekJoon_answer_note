#include <string>
#include <vector>
#include <queue>
#include <algorithm>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
using namespace std;
vector<vector<int>> islands;
vector<vector<int>> visits;
int bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visits[sx][sy] = 1;
    int sum = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        sum += islands[x][y];
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= islands.size() || ny < 0 || ny >= islands[0].size())
                continue;
            if (visits[nx][ny] || !islands[nx][ny])
                continue;
            visits[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    islands.assign(maps.size(), vector<int>(maps[0].size(), 0));
    visits.assign(maps.size(), vector<int>(maps[0].size(), 0));
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[i].size() ; j++){
            if (maps[i][j] == 'X')
                continue;
            islands[i][j] = maps[i][j] - '0';
        }
    }
    for (int i = 0 ; i < islands.size() ; i++){
        for (int j = 0 ; j < islands[i].size() ; j++){
            if (!islands[i][j] || visits[i][j])
                continue;
            answer.push_back(bfs(i, j));
        }
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}