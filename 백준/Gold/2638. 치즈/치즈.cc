#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;
int n, m;
int maps[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int has_cheeze(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (maps[i][j])
                return 1;
        }
    }
    return 0;
}
void bfs(){
    queue< pair<int, int> > q;
    int visited[100][100] = {0, };
    int temp_maps[100][100] = {0, };
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
                continue;
            if (!maps[nx][ny]){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
            else {
                temp_maps[nx][ny]++;
            }

        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (temp_maps[i][j] > 1)
                maps[i][j] = 0;
        }
    }
}
int main(int argc, char** argv)
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> maps[i][j];
        }
    }
    int count = 0;
    while(has_cheeze()){
        bfs();
        count++;
    }
    cout << count;
    return 0;
}