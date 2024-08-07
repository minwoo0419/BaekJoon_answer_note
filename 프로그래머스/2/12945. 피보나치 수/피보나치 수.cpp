#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> dp(100001, -1);
long long fibo(int a){
    if (dp[a] >= 0)
        return dp[a];
    return dp[a] = (fibo(a-1) + fibo(a-2)) % 1234567;
}

int solution(int n) {
    dp[0] = 0, dp[1] = 1;
    int answer = fibo(n);
    return answer;
}