#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n, l;
int simulation_col(vector< vector<int> > map, int idx){
    int past = map[idx][0];
    int cnt = 1;
    int down = 0;
    for (int i = 1 ; i < n ; i++){
        if (past == map[idx][i]){
            cnt++;
        }else if (abs(past - map[idx][i]) > 1){
            return 0;
        } else{
            if (past > map[idx][i]){
                if (down == 1)
                    return 0;
                down = 1;
            } else if (past < map[idx][i]){
                if (down == 1 || cnt < l)
                    return 0;
                down = 0;
            }
            cnt = 1;
        }
        if (cnt == l && down == 1){
            cnt = 0;
            down = 0;
        }
        if (i == n - 1 && down == 1)
            return 0;
        past = map[idx][i];
    }
    return 1;
}
int simulation_row(vector< vector<int> > map, int idx){
    int past = map[0][idx];
    int cnt = 1;
    int down = 0;
    for (int i = 1 ; i < n ; i++){
        if (past == map[i][idx]){
            cnt++;
            if (cnt == l && down == 1){
                cnt = 0;
                down = 0;
            }
        }else if (abs(past - map[i][idx]) > 1){
            return 0;
        } else{
            if (past > map[i][idx]){
                if (down == 1)
                    return 0;
                down = 1;
            } else if (past < map[i][idx]){
                if (down == 1 || cnt < l)
                    return 0;
                down = 0;
            }
            cnt = 1;
        }
        if (cnt == l && down == 1){
            cnt = 0;
            down = 0;
        }
        if (i == n - 1 && down == 1)
            return 0;
        past = map[i][idx];
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector< vector<int> > map;
    int cnt = 0;
    cin >> n >> l;
    for (int i = 0 ; i < n ; i++){
        map.push_back(vector<int>());
        for (int j = 0 ; j < n ; j++){
            int num;
            cin >> num;
            map[i].push_back(num);
        }
    }
    for (int i = 0 ; i < n ; i++){
        cnt += (simulation_col(map, i) + simulation_row(map, i));
    }
    cout << cnt;
    return 0;
}
