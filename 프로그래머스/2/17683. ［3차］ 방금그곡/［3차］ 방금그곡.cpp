#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, string>>> pq;

vector<string> split(string s, char op){
    vector<string> ans;
    string buffer;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buffer, op)){
        if (buffer.empty())
            continue;
        ans.push_back(buffer);
    }
    return ans;
}
int calc_time(string s){
    vector<string> t = split(s, ':');
    return stoi(t[0]) * 60 + stoi(t[1]);
}

string conv(string s){
    string ans = "";
    for (int i = 0 ; i < s.size() ; i++){
        if (i < s.size() - 1 && s[i+1] == '#'){
            ans += tolower(s[i]);
            i++;
        } else {
            ans += s[i];
        }
    }
    return ans;
}

bool check(int time, string s, string s2){
    string temp = "";
    for (int i = 0 ; i < time ; i++){
        temp += s[i % s.length()];
    }
    return temp.find(s2) != string::npos;
}
string solution(string m, vector<string> musicinfos) {
    m = conv(m);
    for (int i = 0 ; i < musicinfos.size() ; i++){
        vector<string> vs = split(musicinfos[i], ',');
        int diff = calc_time(vs[1]) - calc_time(vs[0]);
        string s = conv(vs[3]);
        if(check(diff, s, m)){
            pq.push(make_pair(diff, make_pair(-i, vs[2])));
        }
    }
    if(pq.empty())
        return "(None)";
    return pq.top().second.second;
}