#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> dp(k+1, 0);
    vector <int> c(n, 0);
    dp[0] = 1;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> c[i];
        for (int j = c[i] ; j <= k ; j++)
            dp[j] = dp[j] + dp[j - c[i]];
    }
    cout << dp[k];
    return (0);
}