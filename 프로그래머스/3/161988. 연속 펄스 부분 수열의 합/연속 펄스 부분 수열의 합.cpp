#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long dp[500001][2];
long long solution(vector<int> sequence) {
    long long answer = 0;
    for (int i = 0 ; i < sequence.size() ; i++){
        int inc = i % 2 == 0 ? 1 : -1;
        int dec = i % 2 == 0 ? -1 : 1;
        dp[i+1][0] = max(dp[i][0] + (long long)sequence[i] * inc, (long long)sequence[i] * inc);
        dp[i+1][1] = max(dp[i][1] + (long long)sequence[i] * dec, (long long)sequence[i] * dec);
        answer = max(dp[i+1][0], answer);
        answer = max(dp[i+1][1], answer);
    }
    return answer;
}