#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int n, m, cnt = 0;
int map[500][500];
vector < vector <int> > visited(500, vector <int> (500, -1));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return 1;
    if (visited[x][y] != -1)
        return visited[x][y];
    visited[x][y] = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (map[x][y] > map[nx][ny])
                visited[x][y] = visited[x][y] + dfs(nx, ny);
        }
    }
    return visited[x][y];
}
int main()
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
            cin >> map[i][j];
    }
    cout << dfs(0, 0);
    return 0;
}