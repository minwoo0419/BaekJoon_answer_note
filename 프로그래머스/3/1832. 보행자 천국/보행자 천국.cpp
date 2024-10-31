#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;
vector<vector<int>> dp_r;
vector<vector<int>> dp_d;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    dp_r.assign(m + 1, vector<int>(n + 1, 0));
    dp_d.assign(m + 1, vector<int>(n + 1, 0));
    for (int i = 1 ; i <= m ; i++) {
        if (city_map[i-1][0] == 1) break;
        dp_d[i][1] = 1;
    }
    for (int i = 1 ; i <= n ; i++) {
        if (city_map[0][i-1] == 1) break;
        dp_r[1][i] = 1;
    }
    for (int i = 2 ; i <= m ; i++){
        for (int j = 2 ; j <= n ; j++){
            if (city_map[i-1][j-1] == 1) {
                dp_r[i][j] = 0;
                dp_d[i][j] = 0;
                continue;
            }
            dp_r[i][j] = city_map[i-1][j-2] == 2 ? 
                dp_r[i][j-1] : (dp_r[i][j-1] + dp_d[i][j-1]) % MOD;
            dp_d[i][j] = city_map[i-2][j-1] == 2 ?
                dp_d[i-1][j] : (dp_r[i-1][j] + dp_d[i-1][j]) % MOD;
        }
    }

    return (dp_r[m][n] + dp_d[m][n]) % MOD;
}