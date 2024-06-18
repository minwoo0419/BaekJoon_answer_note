#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;
int n, m, h, ans = -1;
int maps[31][11];
bool check_pos(){
    for (int j = 1 ; j <= n ; j++){
        int y = j;
        for (int i = 1 ; i <= h ; i++){
            if (maps[i][y-1])
                y--;
            else if (maps[i][y])
                y++;
        }
        if (y != j)
        {
            return false;
        }
    }
    return true;
}
void find_min(int a, int cnt){
    if (cnt > 3)
        return;
    if (check_pos()){
        if (ans ==-1 || ans > cnt)
            ans = cnt;
        return;
    }
    for (int i = a ; i <= h ; i++){
        for (int j = 1 ; j < n ; j++){
            if (maps[i][j-1] || maps[i][j] || maps[i][j+1])
                continue;
            maps[i][j] = 1;
            find_min(i, cnt + 1);
            maps[i][j] = 0;
        }
    }
}
int main(int argc, char** argv)
{
    cin >> n >> m >> h;
    for (int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        maps[a][b] = 1;
    }
    find_min(1, 0);
    cout << ans;
    return 0;
}