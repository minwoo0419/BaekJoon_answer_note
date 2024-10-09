#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
vector<int> arr, ans;
int n, m;
int main()
{  
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    stack<int> stk;
    for (int i = n - 1 ; i >= 0 ; i--){
        while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
        if (stk.empty()) ans.push_back(-1);
        else ans.push_back(stk.top());
        stk.push(arr[i]);
    }
    for (int i = n - 1 ; i >= 0 ; i--){
        cout << ans[i] << " ";
    }
    return (0);
}