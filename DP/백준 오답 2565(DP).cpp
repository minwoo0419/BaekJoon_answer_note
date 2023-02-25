#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int x, y;
    int cnt = 0;
    cin >> n;
    vector <int> dp(n, 0);
    vector < pair <int, int> > a;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> x;
        cin >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    for (int i = 0 ; i < n ; i++)
    {
        dp[i] = 1;
        for (int j = 0 ; j < i ; j++)
        {
            if (a[i].second > a[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        cnt = max(dp[i], cnt);
        cout << dp[i] << " " << a[i].second << "\n";
    }
    cout << (n - cnt);
    return (0);
}