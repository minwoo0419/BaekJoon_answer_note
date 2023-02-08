#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[2];
vector <int> chk[20001]; //행렬을 이용한 양방향 트리 구현
int visit[20001];
void dfs(int y, int t)
{
    visit[y] = t;
    for (int i = 0 ; i < chk[y].size() ; i++)
    {
        if (!visit[chk[y][i]])
        {
            if (t == 2)
                dfs(chk[y][i], 3);
            else
                dfs(chk[y][i], 2);
        }
    }
}
int check(int x)
{
    for (int i = 1 ; i <= x ; i++)
    {
        for (int j = 0 ; j < chk[i].size() ; j++)
        {
            if (visit[i] == visit[chk[i][j]])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 1 ; j <= y ; j++)
        {
            cin >> a[0] >> a[1];
            chk[a[0]].push_back(a[1]);
            chk[a[1]].push_back(a[0]);
        }
        for (int j = 1 ; j <= x ; j++)
        {
            if (!visit[j])
                dfs(j, 2);
        }
        for (int j = 1 ; j <= x ; j++)
            cout << visit[j] << " ";
        if (!check(x))
            cout << "NO\n";
        else
            cout << "YES\n";
        for (int j = 1 ; j <= x ; j++)
            chk[j].clear();
        memset(visit, 0, sizeof(visit));
    }
    return (0);
}