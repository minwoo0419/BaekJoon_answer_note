#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int cut(string s, int n){
    string ans = "";
    for (int i = 0 ; i < s.length() ; ){
        int cnt = 1;
        string a = s.substr(i, n);
        int j = n;
        while(i + j < s.length() && a == s.substr(i + j, n)){
            cnt++;
            j += n;
        }
        if (cnt > 1) ans += to_string(cnt);
        ans += a;
        i += j;
    }
    return ans.length();
}

int solution(string s) {
    int answer = s.length();
    for (int i = 1 ; i <= s.length() / 2 ; i++){
        answer = min(answer ,cut(s, i));
    }
    return answer;
}