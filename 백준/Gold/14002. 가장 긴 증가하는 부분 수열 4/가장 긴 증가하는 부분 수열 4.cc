#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
#include<deque>
using namespace std;
int dp[1001];
int num[1001];
vector<int> ans;
deque<int> result;
int n;
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    ans.push_back(num[0]);
    for (int i = 1 ; i < n ; i++){
        if (ans.back() < num[i])
        {
            ans.push_back(num[i]);
            dp[i] = ans.size() - 1;
        }
        else {
            int idx = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
            ans[idx] = num[i];
            dp[i] = idx;
        }
    }
    int idx = ans.size() - 1;
    cout << ans.size() << "\n";
    for (int i = n - 1 ; i >= 0 ; i--){
        if (dp[i] == idx){
            result.push_front(num[i]);
            idx--;
        }
    }
    for (int i = 0 ; i < ans.size() ; i++){
        cout << result[i] << " ";
    }
    return 0;
}