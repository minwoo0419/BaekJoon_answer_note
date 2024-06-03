#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
using namespace std;
int dp[101][101][101];
int main(int argc, char** argv)
{
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 1 ; i <= a.length() ; i++){
        for (int j = 1 ; j <= b.length() ; j++){
            for (int k = 1 ; k <= c.length() ; k++){
                if (a[i-1] == b[j-1] && b[j-1] == c[k-1] && a[i-1] == c[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else {
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
                if (ans < dp[i][j][k])
                    ans = dp[i][j][k];
            }
        }
    }
    cout << ans;
    return 0;
}