#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
int n;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<vector<pair<int, int> > > maps(4, vector<pair<int, int> >(4, make_pair(0, 0)));
vector<int> alive(17, 1);
bool can_go(int idx, int x, int y){
    int nx = x + dx[idx];
    int ny = y + dy[idx];
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return false;
    if (maps[nx][ny].first == 17) return false;
    return true;
}
void move_fish() {
    for (int fish_num = 1; fish_num <= 16; fish_num++) {
        if (!alive[fish_num]) continue; // 죽은 물고기는 이동하지 않음
        int fx = -1, fy = -1;
        // 현재 물고기의 위치 찾기
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (maps[i][j].first == fish_num) {
                    fx = i;
                    fy = j;
                }
            }
        }
        if (fx == -1 && fy == -1) continue; // 물고기를 찾지 못한 경우

        int direction = maps[fx][fy].second;
        for (int t = 0; t < 8; ++t) { // 8방향 모두 시도
            int new_direction = (direction + t) % 8;
            int nx = fx + dx[new_direction];
            int ny = fy + dy[new_direction];
            if (can_go(new_direction, fx, fy)) {
                swap(maps[fx][fy], maps[nx][ny]);
                maps[nx][ny].second = new_direction; // 물고기의 새로운 방향 저장
                break;
            }
        }
    }
}
vector<int> can_shark(int x, int y, int idx){
    int cnt = 0;
    vector<int> ans;
    while(x + dx[idx] >= 0 && x + dx[idx] < 4 && y + dy[idx] >= 0 && y + dy[idx] < 4){
        x += dx[idx];
        y += dy[idx];
        cnt++;
        if (maps[x][y].first != 0)
            ans.push_back(cnt);
    }
    return ans;
}

int simul(int x, int y, int cnt){
    int maxx = cnt;
    int idx = maps[x][y].second;
    vector<vector<pair<int, int> > > temp_maps = maps;
    move_fish();
    vector<int> temp = can_shark(x, y, maps[x][y].second);
    maps[x][y].first = 0;
    for (int i = 0 ; i < temp.size() ; i++){
        int nx = x + dx[idx] * temp[i];
        int ny = y + dy[idx] * temp[i];
        int die = maps[nx][ny].first;
        alive[die] = 0;
        maps[nx][ny].first = 17;
        maxx = max(maxx, simul(nx, ny, cnt + die));
        alive[die] = 1;
        maps[nx][ny].first = die;
    }
    maps[x][y].first = 17;
    maps = temp_maps;
    return maxx;
}

int main()
{  
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            cin >> maps[i][j].first >> maps[i][j].second;
            maps[i][j].second -= 1;
        }
    }
    alive[maps[0][0].first] = 0;
    int answer = maps[0][0].first;
    maps[0][0].first = 17;
    cout << simul(0, 0, answer);
    return (0);
}