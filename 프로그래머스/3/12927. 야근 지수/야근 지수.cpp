#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    for (int i = 0 ; i < works.size() ; i++){
        pq.push(works[i]);
    }
    for (int i = 0 ; i < n ; i++){
        if (pq.empty()) break;
        int t = pq.top() - 1;
        pq.pop();
        if (t == 0) continue;
        pq.push(t);
    }
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}