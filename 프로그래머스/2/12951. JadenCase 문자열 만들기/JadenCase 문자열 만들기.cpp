#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int flag = true;
    for (int i = 0 ; i < s.length() ; i++){
        if (flag && s[i] != ' '){
            flag = false;
            if (s[i] >= 'a' && s[i] <= 'z')
                answer += toupper(s[i]);
            else
                answer += s[i];
        } else if (!flag && s[i] >= 'A' && s[i] <= 'Z'){
            answer += tolower(s[i]);
        } else
            answer += s[i];
        if (s[i] == ' ')
            flag = true;
    }
    return answer;
}