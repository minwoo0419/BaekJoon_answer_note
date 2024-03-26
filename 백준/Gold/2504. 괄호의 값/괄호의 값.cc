#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int check_braket(char c){
    if (c == '(')
        return 2;
    else if (c == '[')
        return 3;
    else if (c == ')')
        return 4;
    else if (c == ']')
        return 6;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string braket;
    cin >> braket;
    int sum = 0, temp = 1, i = 0;
    stack<int> stk;
    while(i < braket.size()){
        int n = check_braket(braket[i]);
        if (n == 2 || n == 3){
            temp *= n;
            stk.push(n);
        } else {
            if(stk.empty() || n / 2 != stk.top())
                break;
            if(stk.top() == check_braket(braket[i-1])){
                sum += temp;
                temp /= stk.top();
            } else{
                temp /= stk.top();
            }
            stk.pop();
        }
        i++;
    }
    if(i != braket.size() || !stk.empty()){
        sum = 0;
    }
    cout << sum;
    return 0;
}
