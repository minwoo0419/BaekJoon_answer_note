#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
vector< vector<int> > maps;
int main(int argc, char** argv) {
    cin >> n >> m;
    maps.assign(n, vector<int>(m, 0));
    for (int i = 0 ; i < m ; i++){
        int h;
        cin >> h;
        for (int j = n-1 ; j >= n - h ; j--){
            maps[j][i] = 1;
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (maps[i][0] != 0)
            continue;
        for (int j = 0 ; j < m ; j++){
            if (maps[i][j] == 0)
                maps[i][j] = -1;
            else
                break;
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (maps[i][m-1]!= 0)
            continue;
        for (int j = m-1 ; j >= 0 ; j--){
            if (maps[i][j] == 0)
                maps[i][j] = -1;
            else
                break;
        }
    }
    int answer = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (maps[i][j] == 0)
                answer++;
        }
    }
    cout << answer;
    return 0;
}
