#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    priority_queue<int> pq;
    for (int i = 0 ; i < priorities.size() ; i++){
        dq.push_back(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    int idx = 1;
    while(!dq.empty()){
        if (dq.front().first == pq.top()){
            pq.pop();
            if (dq.front().second == location){
                return idx;
            }
            idx++;
        } else{
            dq.push_back(dq.front());
        }
        dq.pop_front();
    }
    return answer;
}