#include <string>
#include <vector>

using namespace std;
vector<long long> dp; 
int solution(int n) {
    int answer = 0;
    dp.assign(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2 ; i <= n ; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    return dp[n];
}