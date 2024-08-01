#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, k;
vector< vector<int> > maps;
int const_maps[11][11];
deque<int> trees[11][11];
void spring_summer(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            int l = 0;
            for ( ; l < trees[i][j].size() ; l++){
                if (trees[i][j][l] > maps[i][j]){
                    break;
                } else {
                    maps[i][j] -= trees[i][j][l];
                    trees[i][j][l]++;
                }
            }
            while(trees[i][j].size() > l){
                maps[i][j] += trees[i][j].back() / 2;
                trees[i][j].pop_back();
            }
        }
    }
}
void autumn(){
    int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            for (int t = 0 ; t < trees[i][j].size() ; t++){
                if (trees[i][j][t] % 5)
                    continue;
                for (int l = 0 ; l < 8 ; l++){
                    int nx = i + dx[l];
                    int ny = j + dy[l];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    trees[nx][ny].push_front(1);
                }
            }
        }
    }
}
void winter(){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            maps[i][j] += const_maps[i][j];
        }
    }
}
int main(int argc, char** argv) {
    cin >> n >> m >> k;
    maps.assign(n, vector<int>(n, 5));
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> const_maps[i][j];
        }
    }
    for (int i = 0 ; i < m ; i++){
        int x, y, z;
        cin >> x >> y >> z;
        trees[x-1][y-1].push_back(z);
    }
    for (int i = 0 ; i < k ; i++){
        spring_summer();
        autumn();
        winter();
    }
    int answer = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            answer += trees[i][j].size();
        }
    }
    cout << answer;
    return 0;
}
