#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<pair<int, int>>> mountain(50001);
vector<int> dest(50001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> intensity(50001, -1);
vector<pair<int, int>> ans;
void bfs(){
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost > intensity[now])
            continue;
        if (dest[now]){
            ans.push_back(make_pair(cost, now));
            continue;
        }
        for (int i = 0 ; i < mountain[now].size() ; i++){
            int c = mountain[now][i].first;
            int next = mountain[now][i].second;
            if (intensity[next] == -1 || intensity[next] > max(cost, c)){
                intensity[next] = max(cost, c);
                pq.push(make_pair(intensity[next], next));
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for (int i = 0 ; i < paths.size() ; i++){
        mountain[paths[i][0]].push_back(make_pair(paths[i][2], paths[i][1]));
        mountain[paths[i][1]].push_back(make_pair(paths[i][2], paths[i][0]));
    }
    for (int i = 0 ; i < summits.size() ; i++){
        dest[summits[i]] = 1;
    }
    for (int i = 0 ; i < gates.size() ; i++){
        pq.push(make_pair(0, gates[i]));
        intensity[gates[i]] = 0;
    }
    bfs();
    sort(ans.begin(), ans.end());
    answer.push_back(ans[0].second);
    answer.push_back(ans[0].first);
    return answer;
}