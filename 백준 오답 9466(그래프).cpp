#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int num[100001];
int visit[100001];
int done[100001];
int k, cnt;
void dfs(int n)
{
    visit[n] = 1;
    if (!visit[num[n]])
        dfs(num[n]);
    else if (!done[num[n]])
    {
        for (int i = num[n] ; i != n ; i = num[i])
            cnt++;
        cnt++;
    }
    done[n] = 1;
}
int main()
{
    int n;
    cin >> n;
    for (int j = 0 ; j < n ; j++)
    {
        cnt = 0;
        cin >> k;
        for (int i = 1 ; i <= k ; i++)
            cin >> num[i];
        for (int i = 1 ; i <= k ; i++)  //한사람씩 dfs
        {
            if (!visit[i])
                dfs(i);
        }
        cout << k - cnt << "\n";
        memset(num, 0, sizeof(num));
        memset(visit, 0, sizeof(visit));
    }
    return (0);
}