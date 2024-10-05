#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n, k;
vector<map<char, int> > smaps;
vector<string> strs;
int find_max(vector<int> &alphas, int idx, int cnt){
    int ans = 0;
    if (cnt == k){
        for (int i = 0 ; i < n ; i++){
            int can = 1;
            for (int j = 0 ; j < strs[i].length() ; j++){
                if (!alphas[strs[i][j] - 'a']) {
                    can = 0;
                    break;
                }
            }
            if (can) ans++;
        }
        return ans;
    }
    int tmp = 0;
    for (int i = idx ; i < 26 ; i++){
        if (alphas[i]) continue;
        alphas[i] = 1;
        ans = max(find_max(alphas, i + 1, cnt + 1), ans);
        alphas[i] = 0;
    }
    return ans;
}
int main(int argc, char** argv)
{
    cin >> n >> k;
    map<char, int> ms;
    smaps.assign(n, ms);
    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        strs.push_back(s);
        for (int j = 0 ; j < s.size() ; j++){
            smaps[i][s[j]]++;
        }
    }
    vector<int> alphas(26, 0);
    alphas[0] = 1;
    alphas['n' - 'a'] = 1;
    alphas['t' - 'a'] = 1;
    alphas['i' - 'a'] = 1;
    alphas['c' - 'a'] = 1;
    if (k < 5) {
        cout << 0;
        return 0;
    } else {
        cout << find_max(alphas, 0, 5);
    }
    return 0;
}