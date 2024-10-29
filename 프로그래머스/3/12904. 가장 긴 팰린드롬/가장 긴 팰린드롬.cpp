#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int check(string s, int l, int r){
    while(l >= 0 && r < s.length()){
        if (s[l] != s[r]) break;
        l--;
        r++;
    }
    return r - l - 1;
}

int solution(string s)
{
    int answer = 0;
    for (int i = 0 ; i < s.length() ; i++){
        answer = max(answer, check(s, i, i));
        answer = max(answer, check(s, i-1, i));
    }
    return answer;
}