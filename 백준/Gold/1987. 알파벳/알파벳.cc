#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
vector<int> arr, ans;
vector<string> maps;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> visits(26, 0);

int dfs(int cnt, int x, int y){
    int ans = cnt;
    for (int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visits[maps[nx][ny] - 'A']) continue;
        visits[maps[nx][ny] - 'A'] = 1;
        ans = max(ans, dfs(cnt + 1, nx, ny));
        visits[maps[nx][ny] - 'A'] = 0;
    }
    return ans;
}
int main()
{  
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        maps.push_back(s);
    }
    visits[maps[0][0] - 'A'] = 1;
    cout << dfs(1, 0, 0);
    return (0);
}