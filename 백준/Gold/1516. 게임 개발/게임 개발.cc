#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int dp[502];
int nums[502];
vector< vector<int> > pre(502);
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> nums[i];
        int a;
        cin >> a;
        while(a != -1){
            pre[i].push_back(a - 1);
            cin >> a;
        }
        if (pre[i].size() == 0)
            dp[i] = nums[i];
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            int maxx = 0;
            for (int k = 0 ; k < pre[j].size() ; k++){
                if (dp[pre[j][k]] == 0){
                    maxx = 0;
                    break;
                } else {
                    maxx = max(maxx, dp[pre[j][k]]);
                }
            }
            if (maxx != 0)
                dp[j] = maxx + nums[j];
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << dp[i] << "\n";
    }
    return 0;
}
