#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    int x, y;
    cin >> n >> m;
    vector < vector <int> > dp(n + 1, vector <int> (m + 1, 0));
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y;
        for (int j = 1 ; j < x ; j++)
            dp[i][j] = dp[i-1][j];
        for (int j = x ; j <= m ; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-x] + y);
    }
    cout << dp[n][m];
    return (0);
}