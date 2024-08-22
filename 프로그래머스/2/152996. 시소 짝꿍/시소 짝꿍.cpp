#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int mul[3] = {3, 2, 4};
    int div[3] = {2, 1, 3};
    unordered_map<long long, long long> ans;
    for (int i = 0 ; i < weights.size() ; i++){
        ans[weights[i]]++;
    }
    for (auto p : ans){
        if (p.second)
            answer += p.second * (p.second - 1) / 2;
        for (int i = 0 ; i < 3 ; i++){
            if (p.first % div[i] == 0){
                if (ans.find(p.first / div[i] * mul[i]) != ans.end())
                    answer += ans[p.first / div[i] * mul[i]] * p.second;
            }
        }
    }
    return answer;
}