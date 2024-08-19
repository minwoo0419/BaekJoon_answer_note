#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_map<char, int> m;
    vector<vector<vector<int>>> visits(13, vector<vector<int>>(13, vector<int>(4, 0)));
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    m['U'] = 0;
    m['D'] = 1;
    m['L'] = 2;
    m['R'] = 3;
    int x = 0, y = 0;
    for (int i = 0 ; i < dirs.length() ; i++){
        int idx = m[dirs[i]];
        int ridx = (idx % 2) ? idx - 1 : idx + 1;
        if (abs(x + dx[idx]) > 5 || abs(y + dy[idx]) > 5)
            continue;
        cout << x << " " << y << " " << dirs[i] << "\n";
        if (!visits[x+5][y+5][idx] && !visits[x + 5 + dx[idx]][y + 5 + dy[idx]][ridx]){
            visits[x+5][y+5][idx] = 1;
            answer++;
        }
        x += dx[idx];
        y += dy[idx];
    }
    return answer;
}