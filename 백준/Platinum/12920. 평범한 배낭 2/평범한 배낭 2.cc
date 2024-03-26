#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
vector < pair <int, int> > bag;
int dp[2020][10001];
int main()
{
    cin >> N >> M;
    for (int i = 1 ; i <= N ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = c ; j > 0 ; j >>= 1)
        {
            int num = j - (j >> 1);
            bag.push_back(make_pair(a * num, b * num));
        }
    }
    for (int i = 0 ; i < bag.size() ; i++)
    {
        for (int j = 1 ; j < bag[i].first ; j++)
            dp[i+1][j] = dp[i][j];
        for (int j = bag[i].first ; j <= M ; j++)
            dp[i+1][j] = max(dp[i][j], bag[i].second + dp[i][j - bag[i].first]);
    }
    int ans = 0;
    for (int i = 1 ; i <= M ; i++)
        ans = max(ans, dp[bag.size()][i]);
    cout << ans;
    return 0;
}
