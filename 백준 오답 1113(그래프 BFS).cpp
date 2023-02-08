#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int pool[52][52];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
queue < pair <int, int> > q;
void bfs(int h) //h보다 낮은 높이의 땅에 물 채우기
{
    int chk[52][52] = { 0 };
    q.push(make_pair(0, 0));
    chk[0][0] = 1;
    pool[0][0] = h;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        for (int k = 0 ; k < 4 ; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx <= n+1 && ny <= m+1 && pool[nx][ny] < h && !chk[nx][ny])
            {
                pool[nx][ny] = h;
                q.push(make_pair(nx, ny));
                chk[nx][ny] = 1;
            }
        }
        q.pop();
    }
}
int main(void)
{
    cin >> n >> m;
    int ma = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        for (int j = 1 ; j <= m ; j++)
        {
            pool[i][j] = s[j-1] - '0';
            ma = max(pool[i][j], ma);
        }
    }
    int sum = 0;
    for (int h = 1 ; h <= ma ; h++)
    {
        bfs(h);
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                if (pool[i][j] < h) //h보다 크거나 같은 땅 사이에 있는 땅들
                {
                    sum = sum + (h - pool[i][j]);
                    pool[i][j] = h; 
                }
            }
        }
    }
    cout << sum;
}