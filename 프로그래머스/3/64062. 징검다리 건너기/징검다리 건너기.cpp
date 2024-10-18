#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isPoss(int k, int num, vector<int> &stones){
    int cnt = 0;
    for (int i = 0 ; i < stones.size() ; i++){
        if (stones[i] < num) cnt++;
        else cnt = 0;
        if (cnt == k) return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int s = 987654321, e = 0;
    for (int i = 0 ; i < stones.size() ; i++){
        s = min(s, stones[i]);
        e = max(e, stones[i]);
    }
    while (s <= e){
        int mid = (s + e) / 2;
        if (isPoss(k, mid, stones)){
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return e;
}