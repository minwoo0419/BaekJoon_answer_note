#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> map(n+1, vector<int>(m+1, 0));
    int answer = 0;
    //누적합 구하기
    for (int i = 0 ; i < skill.size() ; i++){
        int mul = skill[i][0] == 1 ? -1 : 1;
        map[skill[i][1]][skill[i][2]] += mul * skill[i][5];
        map[skill[i][3]+1][skill[i][2]] += -1 * mul * skill[i][5];
        map[skill[i][1]][skill[i][4]+1] += -1 * mul * skill[i][5];
        map[skill[i][3]+1][skill[i][4]+1] += mul * skill[i][5];
    }
    //열에서 계산
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            map[i][j+1] += map[i][j];
        }
    }
    //행에서 계산
    for (int j = 0 ; j < m ; j++){
        for (int i = 0 ; i < n ; i++){
            map[i+1][j] += map[i][j];
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (board[i][j] + map[i][j] > 0){
                answer++;
            }
        }
    }
    return answer;
}