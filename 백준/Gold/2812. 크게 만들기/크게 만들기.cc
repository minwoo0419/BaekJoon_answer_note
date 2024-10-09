#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
int n, m;
string str;
int main()
{  
    cin >> n >> m;
    cin >> str;
    vector<char> stk;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++){
        while(cnt < m && !stk.empty() && stk.back() < str[i]){
            stk.pop_back();
            cnt++;
        }
        stk.push_back(str[i]);
    }
    for (int i = 0 ; i < stk.size() - (m - cnt) ; i++){
        cout << stk[i];
    }
    return (0);
}