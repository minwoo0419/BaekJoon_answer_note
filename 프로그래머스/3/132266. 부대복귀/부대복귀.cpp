#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, int n, vector<vector<int>> map){
    vector<int> visits(n+1, 0);
    queue<int> q;
    q.push(start);
    visits[start] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0 ; i < map[x].size() ; i++){
            if (!visits[map[x][i]]){
                q.push(map[x][i]);
                visits[map[x][i]] = visits[x] + 1;
            }
        }
    }
    return visits;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> map(n+1);
    for (int i = 0 ; i < roads.size() ; i++){
        map[roads[i][0]].push_back(roads[i][1]);
        map[roads[i][1]].push_back(roads[i][0]);
    }
    vector<int> visits = bfs(destination, n, map);
    for (int i = 0 ; i < sources.size() ; i++){
        answer.push_back(visits[sources[i]] - 1);
    }
    return answer;
}