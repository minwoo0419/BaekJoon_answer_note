#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int INF = 987654321;
vector< vector<int> > dp(1001, vector<int>(52, INF));
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF, temp = 0;
    temp = (temperature > t2) ? t1 - (temperature - t2) : temperature;
    t1 -= temp;
    t2 -= temp;
    temp = 0;
    dp[0][0] = 0;
    for (int i = 1 ; i <= onboard.size() ; i++){
        for (int j = 0 ; j <= 50 ; j++){
            if(onboard[i - 1] && (t1 > j || t2 < j))
                continue;
            if (j == 0){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]);
            } else {
                dp[i][j] = min(dp[i-1][j] + b, min(dp[i-1][j+1], dp[i-1][j-1] + a));
            }
        }
    }
    for (int j = 0 ; j <= 50 ; j++){
        if (answer > dp[onboard.size()][j])
            answer = dp[onboard.size()][j];
    }
    return answer;
}