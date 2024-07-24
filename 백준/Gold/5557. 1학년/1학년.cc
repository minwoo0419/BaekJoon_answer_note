#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int num[101];
long long dp[101][21];
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    dp[0][num[0]] = 1;
    for (int i = 1 ; i < n - 1; i++){
        for (int j = 0 ; j <= 20 ; j++){
            if (j + num[i] <= 20)
                dp[i][j + num[i]] += dp[i-1][j];
            if (j - num[i] >= 0)
                dp[i][j - num[i]] += dp[i-1][j];
        }
    }
    cout << dp[n-2][num[n-1]];
    return 0;
}
