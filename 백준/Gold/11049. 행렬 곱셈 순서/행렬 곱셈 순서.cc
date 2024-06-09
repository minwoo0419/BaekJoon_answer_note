#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
#include<deque>
using namespace std;
int dp[501][501];
pair<int, int> num[501];
int n;
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> num[i].first >> num[i].second;
    }
    for (int i = 1 ; i < n ; i++){  //간격
        for (int j = 1 ; j + i <= n ; j++){ //시작점 -> 끝점 : i + j
            dp[j][i + j] = 987654321;
            for (int k = j ; k < i + j ; k++){ //시작점과 끝점 사이
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + num[j].first * num[k].second * num[i + j].second);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}


