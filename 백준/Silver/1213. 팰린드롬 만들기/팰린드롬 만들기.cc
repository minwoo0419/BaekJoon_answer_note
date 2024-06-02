#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
using namespace std;
char str[51];
int alpha[26];
string input;
int main(int argc, char** argv)
{
    cin >> input;
    for (int i = 0 ; i < input.length() ; i++){
        alpha[input[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0 ; i < 26 ; i++){
        if (alpha[i] % 2 == 1)
            odd++;
    }
    if (odd > 0){
        if (input.length() % 2 == 0 || odd > 1){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    int start = 0;
    int end = input.length() - 1;
    for (int i = 0 ; i < 26 ; i++){
        if (alpha[i] % 2 == 1){
            str[input.length() / 2] = 'A' + i;
            alpha[i]--;
        }
        while(alpha[i]){
            str[start++] = 'A' + i;
            str[end--] = 'A' + i;
            alpha[i] -= 2;
        }
    }
    cout << str;
    return 0;
}