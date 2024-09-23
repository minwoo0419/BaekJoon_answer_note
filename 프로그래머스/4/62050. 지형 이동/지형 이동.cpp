#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> land;
vector<vector<int>> visited;
int ans = 0, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int height){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[x][y])
            continue;
        visited[x][y] = 1;
        ans += cost;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            int diff = abs(land[x][y] - land[nx][ny]);
            diff = (diff <= height) ? 0 : diff;
            pq.push(make_pair(diff, make_pair(nx, ny)));
        }
    }
}
int solution(vector<vector<int>> lands, int height) {
    int answer = 0;
    n = lands.size();
    land = lands;
    visited.assign(n, vector<int>(n, 0));
    bfs(height);
    return ans;
}