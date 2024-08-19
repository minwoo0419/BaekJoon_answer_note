#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    for (int i = 0 ; i < scoville.size() ; i++){
        pq.push(scoville[i]);
    }
    while (pq.size() >= 2){
        int a = pq.top();
        if (a >= K)
            return answer;
        pq.pop();
        int b = pq.top() * 2;
        pq.pop();
        answer++;
        pq.push(a + b);
    }
    if (pq.top() >= K)
        return answer;
    return -1;
}