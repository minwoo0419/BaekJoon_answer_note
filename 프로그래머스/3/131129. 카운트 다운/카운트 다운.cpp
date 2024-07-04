#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[100001][2];

void find_ans(vector<vector<int>> &dp, int n){
    if (dp[n-50][0] == dp[n-60][0]){
        dp[n][0] = dp[n-50][0] + 1;
        dp[n][1] = max(dp[n-50][1] + 1, dp[n-60][1]);
    } else if (dp[n-50][0] < dp[n-60][0]){
        dp[n][0] = dp[n-50][0] + 1;
        dp[n][1] = dp[n-50][1] + 1;
    } else {
        dp[n][0] = dp[n-60][0] + 1;
        dp[n][1] = dp[n-60][1];
    }
}

vector<int> solution(int target) {
    vector<int> answer;
    vector<vector<int>> dp(target + 1, vector<int>(2, 0));
    for (int i = 1 ; i <= target ; i++){
        if (i == 50 || i <= 20){
            dp[i][0] = 1;
            dp[i][1] = 1;
        } else if (i <= 60 && i % 3 == 0){
            dp[i][0] = 1;
            dp[i][1] = 0;
        } else if (i <= 40 && i % 2 == 0){
            dp[i][0] = 1;
            dp[i][1] = 0;
        } else if (i > 50 && i <= 70){
            dp[i][0] = 2;
            dp[i][1] = 2;
        } else if (i < 70){
            if (i < 40){
                dp[i][0] = 2;
                dp[i][1] = 2;
            } else{
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        } else{
            find_ans(dp, i);
        }
    }
    return dp[target];
}