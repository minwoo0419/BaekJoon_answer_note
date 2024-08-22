#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<long long, long long> ans;
    for (int i = 0 ; i < weights.size() ; i++){
        ans[weights[i]]++;
    }
    for (auto p : ans){
        if (p.second){
            answer += p.second * (p.second - 1) / 2;
        }
        if (p.first % 2 == 0){
            if (ans.find(p.first * 3 / 2) != ans.end())
                answer += ans[p.first * 3 / 2] * p.second;
        } if (p.first % 3 == 0){
            if (ans.find(p.first * 4 / 3) != ans.end())
                answer += ans[p.first * 4 / 3] * p.second;
        }
        if (ans.find(p.first * 2) != ans.end())
            answer += ans[p.first * 2] * p.second;
    }
    return answer;
}