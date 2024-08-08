#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> fruits;
    priority_queue<int> pq;
    int answer = 0;
    for (int i = 0 ; i < tangerine.size() ; i++) {
        fruits[tangerine[i]]++;
    }
    for (pair<int, int> itr : fruits){
        pq.push(itr.second);
    }
    int cnt = 0;
    while(k > cnt){
        cnt += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}