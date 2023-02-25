#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int num[100][100];
int n, cnt = 0, mi = 201;
queue < pair <int,int> > q;
vector < pair <int, int> > v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void island(int a, int b) //BFS 이용하여 섬마다 번호 붙이기
{
    q.push(make_pair(a, b));
    num[a][b] = ++cnt;
    while (!q.empty())
    {
        int edge = 0;
        int i = q.front().first;
        int j = q.front().second;
        for (int t = 0 ; t < 4 ; t++)
        {
            int nx = i + dx[t];
            int ny = j + dy[t];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (num[nx][ny] < 0)
                {
                    q.push(make_pair(nx, ny));
                    num[nx][ny] = num[i][j];
                }
                if (num[nx][ny] == 0)
                    edge = 1;
            }
        }
        if (edge) //가장자리 좌표 저장
            v.push_back(make_pair(i, j));
        q.pop();
    }
}
void calr(void)
{
    for (int i = 0 ; i < v.size() - 1 ; i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        for (int j = i + 1 ; j < v.size() ; j++)
        {
            int xx = v[j].first;
            int yy = v[j].second;
            if (num[x][y] != num[xx][yy])
                mi = min(mi, (abs(x - xx) + abs(y - yy) - 1));
        }
    }   
}
int main()
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            cin >> num[i][j];
            if (num[i][j])
                num[i][j] = -1;
        }
    }
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (num[i][j] < 0)
                island(i, j);
        }
    }
    calr();
    cout << mi;
    return (0);
}