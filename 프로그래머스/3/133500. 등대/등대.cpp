#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
vector<int> visits(100001, 0);

void dfs(int n, int s, int p, vector<vector<int>> &map){ //자식노드들 중 안켜진 것이 있으면 켜주기
    for (int i = 0 ; i < map[s].size() ; i++){
        if (map[s][i] != p){
            dfs(n, map[s][i], s, map);
            if (!visits[map[s][i]] && !visits[s]){
                visits[s] = 1;
                answer++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> map(n+1);
    for (int i = 0 ; i < lighthouse.size() ; i++){
        map[lighthouse[i][0]].push_back(lighthouse[i][1]);
        map[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    dfs(n, 1, 1, map);
    return answer;
}