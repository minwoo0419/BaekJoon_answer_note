#include <iostream>
#include <vector>

using namespace std;
vector < vector <int> > map(50, vector <int> (50, 0));
vector < vector <int> > visited(50, vector <int> (50, 0));
int lx[4] = {-1, 0, 1, 0};
int ly[4] = {0, 1, 0, -1};
int n, m, x, y, k, cnt = 0;

void check_left(int a, int b, int look)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        int t = (look + 3 - i) % 4;
        int nx = a + lx[t];
        int ny = b + ly[t];
        if (!map[nx][ny] && !visited[nx][ny])
        {
            visited[nx][ny] = 1;
            cnt++;
            check_left(nx, ny, t);
        }
    }
    int blook = look - 2 >= 0 ? look-2 : look+2;
    int bx = a + lx[blook];
    int by = b + ly[blook];
    if (!map[bx][by])
        check_left(bx, by, look);
    else
    {
        cout << cnt;
        exit(0);
    }

}
int main()
{
    cin >> n >> m;
    cin >> x >> y >> k;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
            cin >> map[i][j];
    }
    visited[x][y] = 1;
    cnt++;
    check_left(x, y, k);
    cout << cnt;
    return 0;
}
