#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> maps;
int n, m;
int dfs(vector<int> mine, vector<int> oppo){
    int mx = mine[0];
    int my = mine[1];
    if (!maps[mx][my])
        return 0;
    int ans = 0;
    for (int i = 0 ; i < 4 ; i++){
        int nx = mx + dx[i];
        int ny = my + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (!maps[nx][ny])
            continue;
        maps[mx][my] = 0;
        int count = dfs(oppo, {nx, ny}) + 1;
        maps[mx][my] = 1;
        if (count % 2 == 1 && ans % 2 == 0){//게속 지다가 이길 경우
            ans = count;
        } else if (count % 2 == 1 && ans % 2 == 1){//계속 이기고 있을 경우
            ans = min(ans, count);
        } else if (count % 2 == 0 && ans % 2 == 0){//계속 지고 있을 경우
            ans = max(ans, count);
        }
    }
    return ans;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    maps = board;
    n = board.size();
    m = board[0].size();
    return dfs(aloc, bloc);
}