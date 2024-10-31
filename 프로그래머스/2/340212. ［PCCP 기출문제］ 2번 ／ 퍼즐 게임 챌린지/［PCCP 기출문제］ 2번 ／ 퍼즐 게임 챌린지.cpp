#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long calc(vector<int> &diffs, vector<int> &times, int lev){
    long long ans = 0;
    for (int i = 0 ; i < diffs.size() ; i++){
        if (i == 0 || lev >= diffs[i]) ans += times[i];
        else ans += (diffs[i] - lev) * (times[i] + times[i-1]) + times[i];
    }
    return ans;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int s = 1, e = 1;
    for (auto d : diffs) e = max(e, d);
    while(s <= e){
        int mid = (s + e) / 2;
        long long temp = calc(diffs, times, mid);
        if (temp > limit){
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return s;
}