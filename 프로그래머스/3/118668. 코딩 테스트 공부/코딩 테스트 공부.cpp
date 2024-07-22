#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int n = problems.size();
    int maxa = 0, maxc = 0;
    for (int i = 0 ; i < n ; i++){
        maxa = max(maxa, problems[i][0]);
        maxc = max(maxc, problems[i][1]);
    }
    if (maxa <= alp && maxc <= cop)
        return 0;
    alp = min(alp, maxa);
    cop = min(cop, maxc);
    for (int i = alp ; i <= maxa ; i++){
        for (int j = cop ; j <= maxc ; j++){
            dp[i][j] = 987654321;
        }
    }
    dp[alp][cop] = 0;
    for (int i = alp ; i <= maxa ; i++){
        for (int j = cop ; j <= maxc ; j++){
            if (i < maxa)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if (j < maxc)
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            for (int k = 0 ; k < n ; k++){
                if (i < problems[k][0] || j < problems[k][1])
                    continue;
                int tempa = min(i + problems[k][2], maxa);
                int tempc = min(j + problems[k][3], maxc);
                dp[tempa][tempc] = min(dp[tempa][tempc], dp[i][j] + problems[k][4]);
            }
        }
    }
    return dp[maxa][maxc];
}