#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[200001];
int solution(int n, vector<int> tops) {
    dp[0] = 1;
    tops[0] == 1 ? dp[1] = 3 : dp[1] = 2;
    for (int i = 2 ; i <= n * 2 ; i++){
        if (i % 2 == 1 && tops[i / 2]){
            dp[i]  = 2 * dp[i-1] + dp[i-2];
        } else {
            dp[i] = dp[i-1] + dp[i-2];
        }
        dp[i] %= 10007;
    }
    return dp[n*2];
}