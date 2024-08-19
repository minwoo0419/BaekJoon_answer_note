#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> find_num(string s){
    vector<string> ans;
    int start = 0, i = 0, end = 0;
    while(!isdigit(s[i])){
        i++;
    }
    start = i;
    while(isdigit(s[i])){
        i++;
    }
    end = i;
    ans.push_back(s.substr(0, start));
    ans.push_back(s.substr(start, end - start));
    ans.push_back(s.substr(end, s.length() - end));
    return ans;
}
string str_tolower(string s){
    for (int i = 0 ; i < s.length() ; i++){
        if (isupper(s[i])){
            s[i] = tolower(s[i]);
        }
    }
    return s;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string, int>, int>> sf;
    for (int i = 0 ; i < files.size() ; i++){
        vector<string> ts = find_num(files[i]);
        sf.push_back(make_pair(make_pair(str_tolower(ts[0]), stoi(ts[1])), i));
    }
    sort(sf.begin(), sf.end());
    for (int i = 0 ; i < sf.size() ; i++){
        answer.push_back(files[sf[i].second]);
    }
    return answer;
}