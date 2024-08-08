#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int uclid(int a, int b){
    while(a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 0;
    stack<int> stk;
    stk.push(arr[0]);
    for (int i = 1 ; i < arr.size() ; i++){
        int a = stk.top();
        int b = uclid(a, arr[i]);
        stk.pop();
        stk.push((a * arr[i]) / b);
    }
    return stk.top();
}