#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> maps;
int change(int sx, int sy, int r, int c){
    vector<pair<int, int>> vp;
    int minn = 987654321;
    deque<int> val;
    val.push_back(0);
    for (int i = sy ; i < sy + c ; i++){
        vp.push_back(make_pair(sx, i));
        val.push_back(maps[sx][i]);
    }
    for (int i = sx ; i < sx + r ; i++){
        vp.push_back(make_pair(i, sy + c));
        val.push_back(maps[i][sy + c]);
    }
    for (int i = sy + c ; i > sy ; i--){
        vp.push_back(make_pair(sx + r, i));
        val.push_back(maps[sx + r][i]);
    }
    for (int i = sx + r ; i > sx ; i--){
        vp.push_back(make_pair(i, sy));
        val.push_back(maps[i][sy]);
    }
    int t = val.back();
    val[0] = t;
    for (int i = 0 ; i < vp.size() ; i++){
        maps[vp[i].first][vp[i].second] = val[i];
        minn = min(minn, val[i]);
    }
    return minn;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    maps.assign(rows + 1, vector<int>(columns + 1, 0));
    for (int i = 1 ; i <= rows ; i++){
        for (int j = 1 ; j <= columns ; j++){
            maps[i][j] = (i - 1) * columns + j;
        }
    }
    for (int i = 0 ; i < queries.size() ; i++){
        answer.push_back(change(queries[i][0], queries[i][1], queries[i][2] - queries[i][0], queries[i][3] - queries[i][1]));
    }
    return answer;
}