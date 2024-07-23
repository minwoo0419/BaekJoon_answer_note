#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int dp[1000][3];
int nums[1000][3];
vector< vector<int> > pre(502);
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < 3 ; j++){
            cin >> nums[i][j];
        }
    }
    int minn = 987654321;
    //첫 집 확인
    for (int i = 0 ; i <= 2 ; i++){
        for (int j = 0 ; j <= 2 ; j++){
            if (j == i)
                dp[0][j] = nums[0][j];
            else
                dp[0][j] = 987654321;
        }
        for (int j = 1 ; j < n ; j++){
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + nums[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + nums[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + nums[j][2];
        }
        for (int j = 0 ; j <= 2 ; j++){
            if (i != j)
                minn = min(minn, dp[n-1][j]);
        }
    }
    cout << minn;
    return 0;
}
