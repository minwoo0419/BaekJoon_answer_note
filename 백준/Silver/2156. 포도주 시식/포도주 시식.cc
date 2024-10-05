#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> a;
    vector <int> dp;
    int n;
    int sum = 0;
    cin >> n;
    a.assign(n+1, 0);
    dp.assign(n+1, 0);
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i = 3 ; i <= n ; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i-1] + a[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n];
    return (0);
}