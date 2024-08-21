#include <string>
#include <vector>
#include <queue>
using namespace std;
pair<long long, queue<int>> q1, q2;

int solution(vector<int> queue1, vector<int> queue2) {
    for (int i = 0 ; i < queue1.size() ; i++){
        q1.second.push(queue1[i]);
        q1.first += queue1[i];
        q2.second.push(queue2[i]);
        q2.first += queue2[i];
    }
    int cnt = 0;
    if ((q1.first + q2.first) % 2)
        return -1;
    while(q1.first != q2.first && !q1.second.empty() && !q2.second.empty() && cnt < queue1.size() * 4) {
        if (q1.first < q2.first){
            q1.second.push(q2.second.front());
            q1.first += q2.second.front();
            q2.first -= q2.second.front();
            q2.second.pop();
        } else {
            q2.second.push(q1.second.front());
            q2.first += q1.second.front();
            q1.first -= q1.second.front();
            q1.second.pop();
        }
        cnt++;
    }
    if (q1.second.empty() || q2.second.empty() || cnt == queue1.size() * 4)
        return -1;
    return cnt;
}