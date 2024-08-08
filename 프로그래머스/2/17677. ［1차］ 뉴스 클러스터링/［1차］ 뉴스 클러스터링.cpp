#include <string>
#include <iostream>
#include <vector>
using namespace std;
string tolowers(string s){
    for (int i = 0 ; i < s.size() ; i++){
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }
    return s;
}
bool is_alpha(string s){
    for (int i = 0 ; i < s.size() ; i++){
        if (isalpha(s[i]) == 0)
            return false;
    }
    return true;
}
vector<string> get_two(string str){
    vector<string> result;
    for (int i = 0 ; i < str.size() - 1 ; i++){
        string s = str.substr(i, 2);
        if (!is_alpha(s))
            continue;
        result.push_back(s);
    }
    return result;
}
int solution(string str1, string str2) {
    int answer = 0, cnt = 0;
    str1 = tolowers(str1);
    str2 = tolowers(str2);
    vector<string> s1 = get_two(str1);
    vector<string> s2 = get_two(str2);
    if (s1.empty() && s2.empty())
        return 65536;
    int max = s1.size() + s2.size(), min = 0;
    for (int i = 0 ; i < s1.size() ; i++){
        for (int j = 0 ; j < s2.size() ; j++){
            if (s1[i].compare(s2[j]) == 0){
                min++;
                s2.erase(s2.begin() + j);
                break;
            }
        }
    }
    return (int)((double)min / (max - min) * 65536);
}