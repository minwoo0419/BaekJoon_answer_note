#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> ans(2, 0);
int n = 0;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};
vector<vector<int>> maps;
bool check(int x, int y, int size){
    int is_one = 0;
    for (int i = x ; i < x + size ; i++){
        for (int j = y ; j < y + size ; j++){
            if (maps[i][j] == 1)
                is_one++;
        }
    }
    return is_one == (size * size) || is_one == 0;
}
void func(int x, int y, int size){
    if (check(x, y, size)){
        ans[maps[x][y]]++;
        return ;
    } else {
        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] * size / 2;
            int ny = y + dy[i] * size / 2;
            func(nx, ny, size / 2);
        }
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    n = arr.size();
    maps = arr;
    func(0, 0, arr.size());
    return ans;
}