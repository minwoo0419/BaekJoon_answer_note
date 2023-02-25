#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int x = n.length();
    int sum = 0;
    vector <int> dp(x+1, 0);
    vector <int> a(x+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    if (n[0] == '0' && x == 1)
    {
        cout << "0";
        return (0);
    }
    for (int i = 1 ; i <= x ; i++)
        a[i] = n[i-1] - '0';
    for (int i = 2 ; i <= x ; i++)
    {
        if (a[i] > 0)
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        sum = a[i] + a[i-1] * 10;
        if (sum > 0 && sum < 27)
            dp[i] = (dp[i] + dp[i-2]);
    }
    cout << dp[x];
    return (0);
}