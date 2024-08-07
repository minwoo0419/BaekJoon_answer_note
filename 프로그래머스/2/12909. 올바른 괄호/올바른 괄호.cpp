#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for (int i = 0 ; i < s.length() ; i++){
        if (s[i] == '('){
            stk.push(s[i]);
        } else {
            if (stk.empty()){
                answer = false;
                break;
            } else {
                stk.pop();
            }
        }
    }
    if (!stk.empty())
        answer = false;
    return answer;
}