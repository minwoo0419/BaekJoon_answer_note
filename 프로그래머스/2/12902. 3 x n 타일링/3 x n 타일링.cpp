#include <string>
#include <vector>

using namespace std;
vector<long long> dp, dp2;
int solution(int n) {
    int answer = 0;
    dp.assign(n / 2, 0);
    dp2.assign(n / 2, 0);
    dp[0] = 3;
    dp[1] = 11;
    dp2[1] = 6;
    for (int i = 2; i < n / 2 ; i++){
        dp[i] = (dp[i-1] * 3 + dp2[i-1] + 2) % 1000000007;
        dp2[i] = (dp2[i-1] + dp[i-1] * 2) % 1000000007;
    }
    return dp[n / 2 - 1];
}