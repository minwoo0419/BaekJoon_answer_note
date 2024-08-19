#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> stk;
    for (int i = prices.size() - 1 ; i >= 0 ; i--){
        int idx = prices.size() - 1 - i;
        while(!stk.empty()){
            if (stk.top().first < prices[i]){
                answer.push_back(idx - stk.top().second);
                break;
            }
            stk.pop();
        }
        if (stk.empty()){
            answer.push_back(idx);
        }
        stk.push(make_pair(prices[i], idx));
    }
    reverse(answer.begin(), answer.end());
    return answer;
}