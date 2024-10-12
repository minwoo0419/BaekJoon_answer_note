#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
struct cmp{
    bool operator ()(pii a, pii b){
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pii, vector<pii>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    int i = 0, time = 0;
    while(i < jobs.size() || !pq.empty()){
        for (; i < jobs.size() ; i++){
            if (time >= jobs[i][0])
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
            else
                break;
        }
        if (!pq.empty()){
            time += pq.top().second;
            answer += time - pq.top().first;
            pq.pop();
        } else
            time = jobs[i][0];
    }
    return answer / jobs.size();
}