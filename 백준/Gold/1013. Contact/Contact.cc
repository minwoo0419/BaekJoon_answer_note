#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
using namespace std;
int n;
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        regex re("(100+1+|01)+");
        if(regex_match(s, re)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}