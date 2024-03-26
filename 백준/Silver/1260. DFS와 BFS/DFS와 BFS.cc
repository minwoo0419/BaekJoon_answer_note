#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int a[2];
int chk[1001][1001];
int visit[1001];
int n, m, k;
void dfs(int x)
{
    cout << x << " ";
    visit[x] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        if (visit[i] != 1 && chk[x][i])
            dfs(i);
    }
}
void bfs(int x)
{
    queue <int> q;
    q.push(x);
    while (!q.empty())
    {
        int t = q.front();
        visit[t] = 0;
        cout << t << " ";
        q.pop();
        for (int i = 1 ; i <= n ; i++)
        {
            if (visit[i] && chk[t][i])
            {
                q.push(i);
                visit[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> a[0] >> a[1];
        chk[a[0]][a[1]] = 1;
        chk[a[1]][a[0]] = 1;
    }
    dfs(k);
    cout << "\n";
    bfs(k);
    return (0);
}