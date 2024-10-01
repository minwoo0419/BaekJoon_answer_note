#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector< vector<int> > visits;
vector<string> maps;
queue<pii> pre_water, pre_swan;
pii swan;
int r, c;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool swan_bfs(){
    queue<pii> nq;
    while(!pre_swan.empty()){
        int tx = pre_swan.front().first;
        int ty = pre_swan.front().second;
        pre_swan.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visits[nx][ny]) continue;
            if (maps[nx][ny] == '.'){
                visits[nx][ny] = 1;
                pre_swan.push(make_pair(nx, ny));
            } else if (maps[nx][ny] == 'L'){
                return true;
            } else {
                visits[nx][ny] = 1;
                nq.push(make_pair(nx, ny));
            }
        }
    }
    pre_swan = nq;
    return false;
}
void water_bfs(){
    queue<pii> tmp_water;
    while(!pre_water.empty()){
        int x = pre_water.front().first;
        int y = pre_water.front().second;
        pre_water.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (maps[nx][ny] != 'X') continue;
            maps[nx][ny] = '.';
            tmp_water.push(make_pair(nx, ny));
        }
    }
    pre_water = tmp_water;
}
int main(){
    int answer = 0;
    cin >> r >> c;
    visits.assign(r, vector<int>(c, 0));
    maps.assign(r, "");
    for (int i = 0 ; i < r ; i++){
        cin >> maps[i];
    }
    int cnt = 0;
    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            if (maps[i][j] == 'L') swan = make_pair(i, j);
            if (maps[i][j] != 'X') pre_water.push(make_pair(i, j));
        }
    }
    pre_swan.push(swan);
    visits[swan.first][swan.second] = 1;
    while(!swan_bfs()) {
        water_bfs();
        cnt++;
    }
    cout << cnt;
    return 0;
}