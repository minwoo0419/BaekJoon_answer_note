#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> a;
    vector <int> dp;
    int n;
    int x;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> x;
        a.push_back(x);
        dp.push_back(0);
    }
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (i == 0)
            dp[i] = a[i];
        else if (i == 1)
            dp[i] = a[i] + dp[0];
        else if (i == 2)
        {
            dp[i] = max(a[i]+a[i-1], a[i]+a[i-2]);
        }
        else
            dp[i] = max(dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]);
    }
    cout << dp[n-1];
    return (0);
}