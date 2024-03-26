#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> dp;
    int n;
    cin >> n;
    int sum = 0;
    dp.assign(n+1, 0);
    dp[1] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = dp[i-1] + 1;
        for(int j = 2 ; j * j <= i ; j++)
        {
            if (dp[i - j*j]+1 < dp[i])
                dp[i] = dp[i - j*j] + 1;
        }
    }
    cout << dp[n];
    return (0);
}