#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
using namespace std;
set<string> str;
string input;
int main(int argc, char** argv)
{
    cin >> input;
    for (int i = 0 ; i < input.length() ; i++){
        for (int j = 1 ; j <= input.length() - i ; j++){
            str.insert(input.substr(i, j));
        }
    }
    cout << str.size();
    return 0;
}