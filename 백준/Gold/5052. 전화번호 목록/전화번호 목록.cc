#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
int t;
int main(int argc, char** argv)
{
    cin >> t;
    for (int i = 0 ; i < t ; i++){
        int n;
        cin >> n;
        vector<string> str;
        for (int j = 0 ; j < n ; j++){
            string s;
            cin >> s;
            str.push_back(s);
        }
        sort(str.begin(), str.end());
        int flag = 0;
        for (int j = 0 ; j < n - 1 ; j++){
            if (str[j] == str[j+1].substr(0, str[j].length())){
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}