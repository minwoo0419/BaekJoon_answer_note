#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;
    for (int i = numbers.size() - 1 ; i >= 0 ; i--){
        if (stk.empty()){
            answer.push_back(-1);
        } else if (stk.top() > numbers[i]){
            answer.push_back(stk.top());
        } else {
            while(!stk.empty()){
                if (stk.top() > numbers[i]){
                    answer.push_back(stk.top());
                    break;
                }
                stk.pop();
            }
            if (stk.empty())
                answer.push_back(-1);
        }
        stk.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}