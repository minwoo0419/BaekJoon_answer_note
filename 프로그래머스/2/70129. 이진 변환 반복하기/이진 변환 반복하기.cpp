#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0, zero = 0;
    while(s.size() > 1){
        int tmp = 0;
        for (int i = 0 ; i < s.length() ; i++){
            if (s[i] == '0'){
                tmp++;
            }
        }
        zero += tmp;
        string str;
        int n = s.length() - tmp;
        while(n > 0){
            str = to_string(n % 2) + str;
            n /= 2;
        }
        s = str;
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}