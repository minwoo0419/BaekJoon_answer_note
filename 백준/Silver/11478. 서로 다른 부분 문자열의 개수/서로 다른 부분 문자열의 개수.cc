#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
using namespace std;
map<string, int> str;
string input;
int count = 0;
void func(int idx, string s){
    if (idx >= input.size())
        return;
    string tmp = s + input[idx];
    str[tmp]++;
    func(idx + 1, tmp);
}
int main(int argc, char** argv)
{
    cin >> input;
    for (int i = 0 ; i < input.length() ; i++){
        func(i, "");
    }
    cout << str.size();
    return 0;
}