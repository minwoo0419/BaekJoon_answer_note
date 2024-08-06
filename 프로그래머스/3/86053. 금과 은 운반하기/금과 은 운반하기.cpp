#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = LLONG_MAX;
    n = g.size();
    long long start = 0;
    long long end = 10e5 * 2 * 2 * 10e9;//도시 수 * 재화 수 * 왕복 * 재화 량
    while(start <= end){
        long long mid = (start + end) / 2;
        long long gold = 0;
        long long silver = 0;
        long long weight = 0;
        
        for (int i = 0 ; i < n ; i++){
            //i 번째 도시의 왕복 횟수 계산(총 걸리는 시간 / 왕복)
            long long cnt = (mid + t[i]) / (t[i] * 2);
            gold += min(g[i] * 1LL, w[i] * cnt);
            silver += min(s[i] * 1LL, w[i] * cnt);
            weight += min((g[i] + s[i]) * 1LL, w[i] * cnt);
        }
        
        if (weight >= a + b && gold >= a && silver >= b){
            answer = min(answer, mid);
            end = mid - 1;
        } else{
            start = mid + 1;
        }
    }
    return answer;
}