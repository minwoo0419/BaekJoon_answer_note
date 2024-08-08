#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
vector<int> split(string s, char op){
    vector<int> result;
    stringstream ss;
    string buffer;
    ss.str(s);
    while(getline(ss, buffer, op)){
        result.push_back(stoi(buffer));
    }
    return result;
}
vector<int> solution(string s) {
    map<int, int> nmap;
    vector<int> answer;
    for (int i = 0 ; i < s.length() ; ){
        if (s[i] == '{' || s[i] == '}')
            s.erase(s.begin() + i);
        else
            i++;
    }
    vector<int> nums = split(s, ',');
    for (int i = 0 ; i < nums.size() ; i++){
        nmap[nums[i]]++;
    }
    vector<pair<int, int>> v;
    for (pair<int, int> m : nmap){
        v.push_back(make_pair(m.second, m.first));
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0 ; i < v.size() ; i++){
        answer.push_back(v[i].second);
    }
    return answer;
}