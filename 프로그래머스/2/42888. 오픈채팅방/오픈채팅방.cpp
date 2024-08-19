#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
vector<string> split(string s, char op){
    vector<string> ans;
    string buffer;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buffer, op)){
        if (!buffer.empty())
            ans.push_back(buffer);
    }
    return ans;
}
vector<string> solution(vector<string> record) {
    unordered_map<string, string> m;
    vector<string> answer;
    vector<vector<string>> temp;
    for (int i = 0 ; i < record.size() ; i++){
        vector<string> s = split(record[i], ' ');
        temp.push_back(s);
        if (s[0].compare("Enter") == 0 || s[0].compare("Change") == 0){
            m[s[1]] = s[2];
        }
    }
    for (int i = 0 ; i < temp.size() ; i++){
        if (temp[i][0].compare("Enter") == 0){
            answer.push_back(m[temp[i][1]] + "님이 들어왔습니다.");
        } else if (temp[i][0].compare("Leave") == 0){
            answer.push_back(m[temp[i][1]] + "님이 나갔습니다.");
        }
    }
    return answer;
}