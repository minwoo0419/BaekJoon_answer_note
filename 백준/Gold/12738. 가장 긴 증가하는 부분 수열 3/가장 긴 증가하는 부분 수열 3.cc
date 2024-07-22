#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
vector<long long> ans;
int find_idx(long long t){
    int s = 0, e = ans.size() - 1;
    while(s < e) {
        int mid = (s + e) / 2;
        if (ans[mid] >= t)
            e = mid;
        else
            s = mid + 1;
    }
    return s;
}
int main(int argc, char** argv)
{
    cin >> n;
    long long t;
    for (int i = 0 ; i < n ; i++){
        cin >> t;
        if (i == 0 || ans.back() < t)
            ans.push_back(t);
        else {
            ans[find_idx(t)] = t;
        }
    }
    cout << ans.size();
    return 0;
}
