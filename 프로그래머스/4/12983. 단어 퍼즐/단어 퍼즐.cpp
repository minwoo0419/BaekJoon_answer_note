#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    set<int> sizes;
    set<string> sset;
    vector<int> dp(t.length() + 1, 987654321);
    for (int i = 0 ; i < strs.size() ; i++){
        sizes.insert(strs[i].length());
        sset.insert(strs[i]);
    }
    dp[0] = 0;
    for (int i = 1 ; i <= t.length() ; i++){
        for (auto s : sizes){
            if (i < s) continue;
            if (sset.count(t.substr(i - s, s))){
                dp[i] = min(dp[i], dp[i - s] + 1);
            }
        }
    }
    return dp[t.length()] == 987654321 ? -1 : dp[t.length()];
}