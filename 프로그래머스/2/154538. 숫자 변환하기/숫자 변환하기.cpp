#include <string>
#include <vector>

using namespace std;
vector<int> dp;
int solution(int x, int y, int n) {
    dp.assign(y+1, 987654321);
    int answer = 0;
    dp[x] = 0;
    for (int i = x ; i <= y ; i++){
        if (i + n <= y){
            dp[i + n] = min(dp[i] + 1, dp[i + n]);
        } if (i * 2 <= y){
            dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        } if (i * 3 <= y){
            dp[i * 3] = min(dp[i] + 1, dp[i * 3]);
        }
    }
    return dp[y] == 987654321 ? -1 : dp[y]; 
}