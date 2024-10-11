#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> dp(9);
    for(int i = 1 ; i <= 8 ; i++){
        int num = 0;
        for (int k = 1 ; k <= i ; k++){
            num = num * 10 + N;
        }
        dp[i].insert(num);
        for (int j = 0 ; j < i ; j++){
            for (auto a : dp[j]){
                for (auto b : dp[i - j]){
                    dp[i].insert(a + b);
                    if (a - b > 0) dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0 && a / b > 0) dp[i].insert(a / b);
                }
            }
        }
        if (dp[i].find(number) != dp[i].end()) return i;
    }
    
    return answer;
}