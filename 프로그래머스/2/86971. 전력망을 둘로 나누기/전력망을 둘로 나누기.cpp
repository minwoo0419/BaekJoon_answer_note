#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> maps;
int bfs(int x){
    int cnt = 1;
    vector<int> visits(101, 0);
    queue<int> q;
    q.push(x);
    visits[x] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = 0 ; i < maps[t].size() ; i++){
            if (!maps[t][i])
                continue;
            if (visits[i])
                continue;
            q.push(i);
            visits[i] = 1;
            cnt++;
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    maps.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0 ; i < wires.size() ; i++){
        maps[wires[i][0]][wires[i][1]] = 1;
        maps[wires[i][1]][wires[i][0]] = 1;
    }
    int tot = bfs(1);
    int ans = tot;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n  ; j++){
            if(maps[i][j]){
                maps[i][j] = 0;
                ans = min(ans, abs(tot - 2 * bfs(i)));
                maps[i][j] = 1;
            }
        }
    }
    return ans;
}