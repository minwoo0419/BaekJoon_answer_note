#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int dp[1000001][2];
int n;
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        dp[i][0] = dp[i-1][0] + 1;
        dp[i][1] = i - 1;
        if (i % 2 == 0)
        {
            if (dp[i][0] > dp[i/2][0] + 1){
                dp[i][0] = dp[i/2][0] + 1;
                dp[i][1] = i / 2;
            }
        }
        if (i % 3 == 0){
            if (dp[i][0] > dp[i/3][0] + 1){
                dp[i][0] = dp[i/3][0] + 1;
                dp[i][1] = i / 3;
            }
        }
    }
    cout << dp[n][0] - 1 << "\n";
    while(n >= 1){
        cout << n << " ";
        n = dp[n][1];
    }
    return 0;
}