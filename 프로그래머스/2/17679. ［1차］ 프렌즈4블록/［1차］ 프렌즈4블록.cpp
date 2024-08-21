#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> maps;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

vector<pair<int, int>> check_square(int x, int y){
    vector<pair<int, int>> ans;
    if (x >= maps.size() - 1 || y >= maps[0].size() - 1)
        return ans;
    ans.push_back(make_pair(x, y));
    for (int i = 0 ; i < 3 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (maps[x][y] == maps[nx][ny])
            ans.push_back(make_pair(nx, ny));
    }
    return ans;
}

void make_down(){
    for (int i = 0 ; i < maps[0].size() ; i++){
        for (int j = maps.size() - 2 ; j >= 0 ; j--){
            if (maps[j][i] == '.')
                continue;
            int k = j, flag = 0;
            for ( ; k < maps.size() - 1 ; k++){
                if (maps[k + 1][i] != '.'){
                    flag = 1;
                    break;
                }
            }
            if ((k != j && flag) || (k == maps.size() - 1 && !flag)){
                maps[k][i] = maps[j][i];
                maps[j][i] = '.';
            }
        }
    }
}
int simul(int m, int n){
    vector<vector<int>> visits(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[i].size() ; j++){
            if (maps[i][j] == '.')
                continue;
            vector<pair<int, int>> square = check_square(i, j);
            if (square.size() == 4){
                for (int k = 0 ; k < square.size() ; k++){
                    visits[square[k].first][square[k].second] = 1;
                }
            }
        }
    }
    for (int i = 0 ; i < maps.size() ; i++){
        for (int j = 0 ; j < maps[i].size() ; j++){
            if (visits[i][j]){
                maps[i][j] = '.';
                ans++;
            }
        }
    }
    make_down();
    return ans;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    maps = board;
    while(1){
        int temp = simul(m, n);
        if (temp == 0)
            break;
        answer += temp;
    }
    return answer;
}