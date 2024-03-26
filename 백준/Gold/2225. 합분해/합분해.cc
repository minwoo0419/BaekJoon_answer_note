#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int x;
    cin >> n;
    cin >> x;
    vector <vector <int> > dp(n+1, vector <int>(x+1, 0));
    for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= x ; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else if (j == 1)
                dp[i][j] = 1;
            else if (j == 2)
                dp[i][j] = i + 1;
            else
            {
                for (int k = 0 ; k <= i ; k++)
                {
                    dp[i][j] = (dp[i][j] + dp[k][j-1]) % 1000000000;
                }
            }
        }
    }
    cout << dp[n][x];
    return (0);
}