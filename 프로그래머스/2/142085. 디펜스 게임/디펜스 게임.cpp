#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0, sum = 0;
    int i = 0;
    for ( ; i < enemy.size() ; i++){
        pq.push(enemy[i]);
        if (pq.size() > k){
            sum += pq.top();
            pq.pop();
        }
        if (sum > n)
            break;
    }
    
    return i;
}