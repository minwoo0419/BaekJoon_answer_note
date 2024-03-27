#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int N;
int second = 0;
int check = 10000;
vector < vector <int> > map(20, vector <int>(20, 0));
queue < pair <int, int> > q;
vector < vector <int> > visited(20, vector <int>(20, 0));
queue < pair <int, int> > possible;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int BFS(int x, int y){
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++)
            visited[i][j] = 0;
    }
    check = 10000;
    q.push(pair<int, int>(x, y));
    visited[x][y] = 1;
    int tmp = 0;
    while (!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++){
            if (nx+dx[i] >= 0 && nx+dx[i] < N && ny+dy[i] < N && ny+dy[i] >= 0)
            {
                if (visited[nx+dx[i]][ny+dy[i]] == 0 && map[nx+dx[i]][ny+dy[i]] <= map[x][y]){
                    q.push(pair<int, int>(nx+dx[i], ny+dy[i]));
                    visited[nx+dx[i]][ny+dy[i]] += visited[nx][ny] +1;
                    if (map[nx+dx[i]][ny+dy[i]] < map[x][y] && map[nx+dx[i]][ny+dy[i]] != 0){
                        tmp = 1;
                        if (check > visited[nx+dx[i]][ny+dy[i]] - 1)
                        {
                            check = visited[nx+dx[i]][ny+dy[i]] - 1;
                            while (!possible.empty())
                                possible.pop();
                        }
                        if (check == visited[nx+dx[i]][ny+dy[i]] - 1)
                            possible.push(pair<int, int>(nx+dx[i], ny+dy[i]));
                    }
                }
            }
        }
    }
    return tmp;
}
int main()
{
    cin >> N;
    int n, x, y;
    int ispos = 0;
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            cin >> n;
            if (n == 9){
                x = i;
                y = j;
                n = 2;
            }
            else if (n == 1)
                ispos = 1;
            map[i][j] = n;
        }
    }
    if (ispos == 0)
    {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    while (1){
        int tmp = BFS(x, y);
        if (!tmp)
            break;
        second += check;
        int nx = possible.front().first;
        int ny = possible.front().second;
        possible.pop();
        while (!possible.empty()){
            if (nx > possible.front().first){
                nx = possible.front().first;
                ny = possible.front().second;
            }
            else if (nx == possible.front().first){
                if (ny >possible.front().second){
                    nx = possible.front().first;
                    ny = possible.front().second;
                }
            }
            possible.pop();
        }
        cnt += 1;
        map[nx][ny] = map[x][y];
        map[x][y] = 0;
        if (cnt == map[nx][ny]){
            cnt = 0;
            map[nx][ny] += 1;
        }
        x = nx;
        y = ny;
    }
    cout << second;
    return 0;
}
