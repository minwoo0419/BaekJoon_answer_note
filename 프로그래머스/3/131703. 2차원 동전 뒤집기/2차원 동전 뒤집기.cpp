#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int answer = -1;
vector<vector<int>> ans;

void change(vector<vector<int>>& start, int x, int is_row) {
    if (is_row) {
        for (int i = 0; i < start.size(); i++) {
            start[i][x] = 1 - start[i][x];
        }
    } else {
        for (int i = 0; i < start[x].size(); i++) {
            start[x][i] = 1 - start[x][i];
        }
    }
}
int check_cnt(int k){
    int cnt = 0;
    while(k > 0){
        if (k & 1)
            cnt++;
        k = k >> 1;
    }
    return cnt;
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int n = target.size();
    int m = target[0].size();
    int k = 1 << (n + m);
    cout << k;
    for (int i = 0 ; i < k ; i++){
        vector<vector<int>> temp = beginning;
        for (int x = 0 ; x < n ; x++){
            int bx = 1 << x;
            if ((i & bx) != 0){
                change(temp, x, 0);
            }
        }
        for (int y = 0 ; y < m ; y++){
            int by = 1 << (y + n);
            if ((i & by) != 0){
                change(temp, y, 1);
            }
        }
        if (temp == target){
            if (answer == -1 || check_cnt(i) < answer)
                answer = check_cnt(i);
        }
    }
    return answer;
}