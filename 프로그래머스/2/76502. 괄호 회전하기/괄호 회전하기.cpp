#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>
using namespace std;

bool check_first(char a){
    if (a == '{' || a == '[' || a == '(')
        return true;
    return false;
}

bool check_match(char a, char b){
    if (a == '{'){
        if (b == '}')
            return true;
    } else if (a == '('){
        if (b == ')')
            return true;
    } else if (a == '['){
        if (b == ']')
            return true;
    }
    return false;
}

bool is_right(deque<char> dq){
    stack<char> stk;
    for (int i = 0 ; i < dq.size() ; i++){
        if (stk.empty()){
            if (!check_first(dq[i]))
                return false;
        } else if(!check_first(dq[i])){
            if (check_match(stk.top(), dq[i])){
                stk.pop();
                continue;
            } else
                return false;
        }
        stk.push(dq[i]);
    }
    if (!stk.empty())
        return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    for (int i = 0 ; i < s.length() ; i++){
        dq.push_back(s[i]);
    }
    int cnt = 0;
    while (cnt < dq.size()){
        if (is_right(dq)) {
            answer++;
        }
        char c = dq.front();
        dq.pop_front();
        dq.push_back(c);
        cnt++;
    }
    return answer;
}