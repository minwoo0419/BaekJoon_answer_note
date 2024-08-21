#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int bridge_weight = 0;
    queue<pair<int, int>> bridge;
    int idx = 0;

    while (idx < truck_weights.size() || !bridge.empty()) {
        time++;
        
        if (!bridge.empty() && bridge.front().second == time) {
            bridge_weight -= bridge.front().first;
            bridge.pop();
        }
        
        if (idx < truck_weights.size() && bridge_weight + truck_weights[idx] <= weight) {
            bridge_weight += truck_weights[idx];
            bridge.push({truck_weights[idx], time + bridge_length});
            idx++;
        }
    }
    
    return time;
}
