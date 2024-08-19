#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp(land.size()+1, vector<int>(4, 0));
    int answer = 0;
    for (int i = 1 ; i <= land.size() ; i++){
        for (int j = 0 ; j < 4 ; j++){
            int maxx = 0;
            for (int k = 0 ; k < 4 ; k++){
                if (j == k)
                    continue;
                maxx = max(maxx, dp[i-1][k]);
            }
            dp[i][j] = land[i-1][j] + maxx;
            answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}