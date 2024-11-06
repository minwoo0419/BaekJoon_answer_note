#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;
int conv(string a, int b){
    int ans = 0;
    for (int i = 0 ; i < a.length() ; i++){
        ans *= b;
        ans += (a[i] - '0');
    }
    return ans;
}
int rconv(int a, int b) {
    string ans = "";
    while(a > 0) {
        ans = to_string(a % b) + ans;
        a /= b;
    }
    if (ans == "") ans = "0";
    return stoi(ans);
}
int calc(int a, int b){
    
}
vector<int> find_range(string a, string op, string b, string c, int maxNum){
    vector<int> nums;
    for (int i = maxNum ; i <= 9 ; i++){
        if (op == "-"){
            if (conv(a, i) - conv(b, i) == conv(c, i)) nums.push_back(i);
        } else {
            if (conv(a, i) + conv(b, i) == conv(c, i)) nums.push_back(i);
        }
    }
    return nums;
}
vector<string> split(string s){
    vector<string> ans;
    string buf;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buf, ' ')){
        if (buf.empty()) continue;
        ans.push_back(buf);
    }
    return ans;
}
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    int maxNum = 2, cnt = 0;
    int n = expressions.size();
    for (auto ex : expressions){
        for (auto e : ex){
            if (isdigit(e)) maxNum = max(maxNum, e - '0' + 1);
        }
    }
    map<int, int> maps;
    vector<vector<string>> haveX;
    for (auto ex : expressions){
        vector<string> sp = split(ex);
        if (sp[4] == "X") {
            haveX.push_back(sp);
            continue;
        }
        cnt++;
        vector<int> range = find_range(sp[0], sp[1], sp[2], sp[4], maxNum);
        for (auto r : range) maps[r]++;
    }
    for (auto m : maps) if (m.second != cnt) maps.erase(m.first);
    if (maps.empty()){
        for (int i = maxNum ; i <= 9 ; i++) maps[i]++;
    }
    for (auto x : haveX){
        int ans = -1;
        for (auto m : maps){
            int temp = 
                x[1] == "-" ?
                conv(x[0], m.first) - conv(x[2], m.first)
                : conv(x[0], m.first) + conv(x[2], m.first);
            temp = rconv(temp, m.first);
            if (ans != -1 && ans != temp) {
                x[4] = "?";
                break;
            }
            ans = temp;
        }
        if (x[4] != "?") x[4] = to_string(ans);
        answer.push_back(x[0] + " "+ x[1] + " " + x[2] + " " + x[3] + " " + x[4]);
    }
    return answer;
}