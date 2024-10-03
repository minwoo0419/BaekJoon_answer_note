#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    vector<int> dp(n, 0);
    vector<int> dp2(n, 0);
    dp[0] = money[0];
    dp2[1] = money[1];
    dp[1] = money[0];
    for (int i = 2 ; i < n - 1 ; i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    }
    dp2[n-1] = max(dp2[n-2], dp2[n-3] + money[n-1]);
    answer = max(dp2[n-1], dp[n-2]);
    return answer;
}