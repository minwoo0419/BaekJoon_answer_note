#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> comb_mens;

void comb(int cnt, int idx, vector<int> mentos, int k){
    if (cnt == 0)
    {
        comb_mens.push_back(mentos);
        return;
    }
    for (int i = idx; i < mentos.size() ; i++){
        mentos[i]++;
        comb(cnt-1, i, mentos, k);
        mentos[i]--;
    }
}
int simul(vector<int> mentos, vector<vector<int>> reqs){
    vector<priority_queue<int, vector<int>, greater<int>>> pq(mentos.size());
    int ans = 0;
    for (int i = 1 ; i < mentos.size() ; i++){
        for (int j = 0 ; j < mentos[i] ; j++){
            pq[i].push(0);
        }
    }
    for (int i = 0 ; i < reqs.size() ; i++){
        int st = reqs[i][0];
        int et = reqs[i][1];
        int type = reqs[i][2];
        int tmp = pq[type].top();
        pq[type].pop();
        if (tmp > st){
            ans += (tmp - st);
            pq[type].push(tmp + et);
        }
        else if (tmp <= st){
            pq[type].push(st + et);
        }
    }
    return ans;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 987654321;
    vector<int> mentos(k + 1, 1);
    comb(n - k, 1, mentos, k);
    for (int i = 0 ; i < comb_mens.size() ; i++){
        int tmp = simul(comb_mens[i], reqs);
        if (answer > tmp)
            answer = tmp;
    }
    return answer;
}