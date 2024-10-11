#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> maps(n+1, vector<int>(m+1, 0));
    for (int i = 0 ; i < puddles.size() ; i++){
        maps[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            if (i == 1 && j == 1) continue;
            if (maps[i][j] == -1) continue;
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000007;
            
        }
    }
    return dp[n][m];
}