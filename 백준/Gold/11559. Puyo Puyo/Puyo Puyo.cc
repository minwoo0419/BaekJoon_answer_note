#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char maps[13][7];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void gravity(){
    for (int i = 0 ; i < 6 ; i++){
        for (int j = 11 ; j >= 0 ; j--){
            if (maps[j][i] != '.'){
                int t = j;
                while(t < 11){
                    if (maps[t+1][i] != '.')
                        break;
                    maps[t+1][i] = maps[t][i];
                    maps[t][i] = '.';
                    t++;
                }
            }
        }
    }
}
bool bfs(int a, int b){
    char target = maps[a][b];
    int visits[13][7] = {0, };
    int num = 1;
    queue< pair<int, int> > q;
    q.push(make_pair(a, b));
    visits[a][b] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                continue;
            if (visits[nx][ny])
                continue;
            if (maps[nx][ny] != target)
                continue;
            num++;
            visits[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    if (num >= 4){
        for (int i = 0 ; i < 12 ; i++){
            for (int j = 0 ; j < 6 ; j++){
                if (visits[i][j])
                    maps[i][j] = '.';
            }
        }
        return true;
    }
    return false;
}
int main(int argc, char** argv) {
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 6 ; j++){
            cin >> maps[i][j];
        }
    }
    int cnt = 0;
    while(1){
        bool flag = false;
        for (int i = 0 ; i < 12 ; i++){
            for (int j = 0 ; j < 6 ; j++){
                if(maps[i][j] == '.')
                    continue;
                if(bfs(i, j)){
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
        gravity();
        cnt++;
    }
    cout << cnt;
    return 0;
}
