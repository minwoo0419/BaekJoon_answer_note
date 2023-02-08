#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector < vector <int> > tomato(1002, vector <int>(1002, -1));
vector < vector <int> > visit(1001, vector <int>(1001, 0));
int n, m, cnt = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue <int> x;
queue <int> y;
void dfs(void)
{
    while (!x.empty())
    {
        for (int i = 0 ; i < 4 ; i++)
        {
            int nx, ny;
            nx = x.front()+dx[i];
            ny = y.front()+dy[i];
            if (tomato[nx][ny] == 0)
            {
                tomato[nx][ny] = tomato[x.front()][y.front()] + 1;
                x.push(nx);
                y.push(ny);
            }
        }
        x.pop();
        y.pop();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            {
                x.push(i);
                y.push(j);
            }
        }
    }
    dfs();
    int tot = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (tomato[i][j] == 0)
            {
                cout << "-1";
                return (0);
            }
            tot = max(tomato[i][j], tot);
        }
    }
    cout << tot - 1;
    return (0);
}