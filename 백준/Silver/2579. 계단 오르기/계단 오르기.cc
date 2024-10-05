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
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max(a[0], a[1]) + a[2];
    for (int i = 3 ; i < n ; i++)
    {
        dp[i] = max(a[i] + dp[i-3] + a[i-1], a[i] + dp[i-2]);
    }
    cout << dp[n-1];
    return (0);
}