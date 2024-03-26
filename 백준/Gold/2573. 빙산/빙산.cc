#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
using namespace std;
int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, -1, 0, 1};
int n, m;
void bfs(vector< vector<int> > map, vector< vector<int> > &visit, int i, int j){
    queue< pair<int, int> > q;
    q.push(make_pair(i, j));
    visit[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
            int dx = x + nx[k];
            int dy = y + ny[k];
            if (map[dx][dy] > 0 && visit[dx][dy] == 0){
                visit[dx][dy] = 1;
                q.push(make_pair(dx, dy));
            }
        }
    }
}
int check_ice(vector< vector<int> > map, vector< pair<int, int> > ice){
    vector< vector<int> > visit (n, vector<int>(m, 0));
    bfs(map, visit, ice[0].first, ice[0].second);
    for (int i = 0 ; i < ice.size() ; i++){
        if (visit[ice[i].first][ice[i].second] == 0)
            return 0;
    }
    return 1;
}
void melt(vector< vector<int> > &map, vector< pair<int, int> > &ice){
    vector< vector<int> > temp_map = map;
    for (int i = 0 ; i < ice.size() ; i++){
        int x = ice[i].first;
        int y = ice[i].second;
        int cnt = 0;
        for (int j = 0 ; j < 4 ; j++){
            int dx = x + nx[j];
            int dy = y + ny[j];
            if(temp_map[dx][dy] == 0)
                cnt++;
        }
        if (map[x][y] <= cnt){
            map[x][y] = 0;
            ice.erase(ice.begin() + i);
            i--;
        } else{
            map[x][y] -= cnt;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector< vector<int> > map;
    vector< pair<int, int> > ice;
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        map.push_back(vector<int>());
        for(int j = 0 ; j < m ; j++){
            int n;
            cin >> n;
            map[i].push_back(n);
            if (n > 0){
                ice.push_back(make_pair(i, j));
            }
        }
    }
    while(check_ice(map, ice)){
        melt(map, ice);
        cnt++;
        if (ice.empty()){
            cnt = 0;
            break;
        }
    }
    cout << cnt;
    return 0;
}
