#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
vector <vector <int> > map(101, vector<int>(101, 0));
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
int check(int x, int y){
    for (int i = 0 ; i < 4 ; i++){
        if (x == dx[i] && y == dy[i])
            return i;
    }
    return -1;
}
void check_map(vector< pair<int, int> > where){
    for (int i = 0 ; i < where.size() ; i++){
        int x = where[i].first;
        int y = where[i].second;
        if (x <= 100 && y <= 100 && x >= 0 && y >= 0){
            map[x][y] = 1;
        }
    }
}
int check_square(){
    int cnt = 0;
    for (int i = 0 ; i < map.size() - 1 ; i++){
        for (int j = 0 ; j < map[i].size() - 1 ; j++){
            if (map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
                cnt++;
        }
    }
    return cnt;
}
void simulation(){
    int x, y, d, g;
    cin >> y >> x >> d >> g;
    stack<int> stk;
    vector< pair<int, int> > where;
    stk.push(d);
    where.push_back(make_pair(x, y));
    for (int i = 0 ; i < g ; i++){
        while(!stk.empty()){
            int lx = where[where.size() - 1].first;
            int ly = where[where.size() - 1].second;
            int idx = stk.top();
            stk.pop();
            where.push_back(make_pair(lx + dx[idx], ly + dy[idx]));
        }
        for (int j = 0 ; j < where.size() - 1 ; j++){
            int lx = where[j+1].first - where[j].first;
            int ly = where[j+1].second - where[j].second;
            int idx = check(lx, ly);
            if (idx != -1){
                if (idx == 3)
                    idx = -1;
                stk.push(idx + 1);
            }
        }
    }
    while(!stk.empty()){
            int lx = where[where.size() - 1].first;
            int ly = where[where.size() - 1].second;
            int idx = stk.top();
            stk.pop();
            where.push_back(make_pair(lx + dx[idx], ly + dy[idx]));
        }
    check_map(where);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector< vector<int> > vec;
    for (int i = 0 ; i < n ; i++){
        simulation();
    }
    cout << check_square();
    return 0;
}
