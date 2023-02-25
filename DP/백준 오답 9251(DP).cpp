#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    vector <vector <int> > dp(a.length() + 1, vector <int> (b.length()+1, 0));
    for (int i = 0 ; i < a.length() ; i++)
    {
        for (int j = 0 ; j < b.length() ; j++)
        {
            if (a[i] == b[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            cout << dp[i+1][j+1] << " ";
        }
        cout << "\n";
    }
    cout << dp[a.length()][b.length()];
    return (0);
}