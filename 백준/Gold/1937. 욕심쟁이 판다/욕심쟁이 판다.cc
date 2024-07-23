#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int maps[502][502];
int dp[502][502];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dfs(int x, int y){
    if (dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (maps[nx][ny] > maps[x][y])
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}
int main(int argc, char** argv)
{
    int ans = 0;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> maps[i][j];
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            dfs(i, j);
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
