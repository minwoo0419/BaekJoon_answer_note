#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int maps[101][101];
int visits[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ex, ey;
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visits[x][y] = 1;
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (visits[nx][ny] || !maps[nx][ny])
                continue;
            q.push(make_pair(nx, ny));
            visits[nx][ny] = visits[tx][ty] + 1;
        }
    }
}
//겹치는 것 위해 모두 *2 해주어야 함
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    ex = itemY * 2, ey = itemX * 2;
    for (int i = 0 ; i < rectangle.size() ; i++){
        int x1 = rectangle[i][1] * 2, x2 = rectangle[i][3] * 2;
        int y1 = rectangle[i][0] * 2, y2 = rectangle[i][2] * 2;
        for (int i = x1 ; i <= x2 ; i++){
            for (int j = y1 ; j <= y2 ; j++){
                maps[i][j] = 1;
            }
        }
    }
    for (int i = 0 ; i < rectangle.size() ; i++){
        int x1 = rectangle[i][1] * 2, x2 = rectangle[i][3] * 2;
        int y1 = rectangle[i][0] * 2, y2 = rectangle[i][2] * 2;
        for (int i = x1 + 1 ; i < x2 ; i++){
            for (int j = y1 + 1 ; j < y2 ; j++){
                maps[i][j] = 0;
            }
        }
    }
    visits[characterY * 2][characterX * 2] = 1;
    bfs(characterY * 2, characterX * 2);
    return (visits[ex][ey] - 1) / 2;
}