#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    vector<int> dp(n - 1, 0);
    vector<int> dp2(n, 0);
    if (n == 1) return sticker[0];
    else if (n == 2) return max(sticker[0], sticker[1]);
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for (int i = 2 ; i < n - 1 ; i++){
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    dp2[1] = sticker[1];
    for (int i = 2 ; i < n ; i++){
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i]);
    }
    return max(dp[n-2], dp2[n-1]);
}