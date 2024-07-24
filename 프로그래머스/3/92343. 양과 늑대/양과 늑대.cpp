#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> maps(17);
vector<int> infos;
int ans = 0;
void dfs(int idx, int wolves, int sheeps, queue<int> q){
    if (infos[idx])
        wolves++;
    else
        sheeps++;
    if (wolves >= sheeps)
        return ;
    if (ans < sheeps)
        ans = sheeps;
    for (int i = 0 ; i < maps[idx].size() ; i++){
        q.push(maps[idx][i]);
    }
    for (int i = 0 ; i < q.size() ; i++){
        int temp = q.front();
        q.pop();
        dfs(temp, wolves, sheeps, q);
        //완탐을 위해 다시 넣어줌
        q.push(temp);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    infos = info;
    int answer = 0;
    for (int i = 0 ; i < edges.size() ; i++){
        maps[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    dfs(0, 0, 0, q);
    return ans;
}