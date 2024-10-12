#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int map[1000][1000];
int crush[1000][1000];
int nocrush[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue < pair <int, int> > q;
void bfs(void)
{
    q.push(make_pair(0, 0));
    nocrush[0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0 ; i < 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (crush[x][y])
                {
                    if (!map[nx][ny] && !crush[nx][ny])
                    {
                        crush[nx][ny] = crush[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
                if (nocrush[x][y])
                {
                    if (map[nx][ny])
                    {
                        crush[nx][ny] = nocrush[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                    else if (!map[nx][ny] && !nocrush[nx][ny])
                    {
                        nocrush[nx][ny] = nocrush[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;
        for (int j = 0 ; j < m ; j++)
            map[i][j] = s[j] - '0';
    }
    bfs();
    if (!crush[n-1][m-1] || !nocrush[n-1][m-1])
    {
        if (!max(crush[n-1][m-1], nocrush[n-1][m-1]))
            cout << "-1";
        else
            cout << max(crush[n-1][m-1], nocrush[n-1][m-1]);
    }
    else
        cout << min(crush[n-1][m-1], nocrush[n-1][m-1]);
    return (0);
}