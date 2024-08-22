#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, -1};
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> maps(n, vector<int>(n, 0));
    int count = n, x = -1, y = 0, num = 1;
    while(count > 0){
        for (int i = 0 ; i < count ; i++){
            x += dx[(n - count) % 3];
            y += dy[(n - count) % 3];
            maps[x][y] = num++;
        }
        count--;
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (maps[i][j])
                answer.push_back(maps[i][j]);
        }
    }
    return answer;
}