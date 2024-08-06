#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int maxx = 0, n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> visits;
vector<vector<int>> maps;
vector<int> ans;
vector<int> check;
void bfs(int x, int y){
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visits[x][y] = 1;
    check[y] = 1;
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(!maps[nx][ny])
                continue;
            if (visits[nx][ny])
                continue;
            if(!check[ny])
                check[ny] = 1;
            q.push(make_pair(nx, ny));
            cnt++;
            visits[nx][ny] = 1;
        }
    }
    for (int i = 0 ; i < m ; i++){
        if (check[i]){
            check[i] = 0;
            ans[i] += cnt;
        }
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    maps = land;
    ans.assign(m, 0);
    check.assign(m, 0);
    visits.assign(n, vector<int>(m, 0));
    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            if (visits[j][i] || !maps[j][i])
                continue;
            bfs(j, i);
        }
    }
    for (int i = 0 ; i < m ; i++){
        answer = max(answer, ans[i]);
    }
    return answer;
}