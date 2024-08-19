#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stk;
    for (int i = 1 ; i <= order.size() ; i++){
        stk.push(i);
        while(!stk.empty() && stk.top() == order[answer]){
            answer++;
            stk.pop();
        }
    }
    return answer;
}
