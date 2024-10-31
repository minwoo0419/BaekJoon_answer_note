#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int getIdx(int start, int n, vector<int> &v){
    int cnt = 0;
    while(cnt < n){
        start = v[start];
        cnt++;
    }
    return start;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> stk;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int idx = k;
    for (int i = 0 ; i < n ; i++){
        answer += 'O';
        left[i] = i -1;
        right[i] = i + 1;
    }
    for (int i = 0 ; i < cmd.size() ; i++) {
        if (cmd[i][0] == 'U'){
            int num =stoi(cmd[i].substr(2, cmd[i].length() - 2));
            idx = getIdx(idx, num, left);
        } else if (cmd[i][0] == 'D'){
            int num = stoi(cmd[i].substr(2, cmd[i].length() - 2));
            idx = getIdx(idx, num, right);
        } else if (cmd[i] == "C"){
            answer[idx] = 'X';
            if (left[idx] != -1) right[left[idx]] = right[idx];
            if (right[idx] != n) left[right[idx]] = left[idx];
            stk.push(idx);
            idx = right[idx] == n ? left[idx] : right[idx];
        } else{
            int t = stk.top();
            stk.pop();
            answer[t] = 'O';
            if (right[t] != n) left[right[t]] = t;
            if (left[t] != -1) right[left[t]] = t;
        }
            
    }

    return answer;
}