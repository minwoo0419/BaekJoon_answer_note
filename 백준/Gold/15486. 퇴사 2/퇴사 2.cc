#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int dp[1500001];
int main(int argc, char** argv)
{
    cin >> n;
    int ans = 0, temp = 0;
    for (int i = 0 ; i < n ; i++){
        int day, money;
        cin >> day >> money;
        temp = max(dp[i], temp);
        if (i + day > n)
            continue;
        dp[i + day] = max(dp[i + day], temp + money);
        ans = max(ans, dp[i + day]);
    }
    cout << ans;
    return 0;
}
