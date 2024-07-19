#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
int dp[1001][1001];
int maps[1001][1001];

int main(int argc, char** argv)
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            char a;
            cin >> a;
            maps[i][j] = a - '0';
            dp[i][j] = maps[i][j];
        }
    }
    int maxx = 0;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            if (dp[i][j]){
                if (dp[i-1][j] && dp[i][j-1] && dp[i-1][j-1])
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxx = max(maxx, dp[i][j]);
            }
        }
    }
    cout << maxx * maxx;
    return 0;
}
