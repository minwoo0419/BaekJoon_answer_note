#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long> sums;
int cnt = 0;
void find(int n){
    int s = 0;
    int e = 0;
    while(s <= e){
        if (sums[e] - sums[s] > n) {
            s++;
        } else {
            if (sums[e] - sums[s] == n)
                cnt++;
            e++;
            if (e == sums.size())
                break;
        }
    }
}
int solution(int n) {
    int answer = 0;
    int sum = 0;
    for (int i = 0 ; i <= n ; i++){
        sum += i;
        sums.push_back(sum);
    }
    find(n);
    return cnt;
}