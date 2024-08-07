#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    for (int i = 0 ; i < s.size() ; i++){
        if (stk.empty() || stk.top() != s[i])
            stk.push(s[i]);
        else if (stk.top() == s[i])
            stk.pop();
    }
    return stk.empty();
}