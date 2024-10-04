#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <sstream>
using namespace std;

vector<string> split(string s){
    vector<string> answer;
    stringstream ss;
    string stringBuffer;
    ss.str(s);
    while(getline(ss, stringBuffer, ' ')){
        if (stringBuffer.empty()) continue;
        answer.push_back(stringBuffer);
    }
    return answer;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector <int> answer(id_list.size(), 0);
    unordered_set<string> sets;
    unordered_map<string, vector<string>> maps;
    unordered_map<string, int> ans;
    for (int i = 0 ; i < report.size() ; i++){
        if (sets.insert(report[i]).second){
            vector<string> v = split(report[i]);
            maps[v[1]].push_back(v[0]); 
        }
    }
    for (auto m : maps){
        cout << m.first << " " << m.second.size() << "\n";
        if (m.second.size() >= k){
            for (int i = 0 ; i < m.second.size() ; i++){
                ans[m.second[i]]++;
            }
        }
    }

    for (int i = 0 ; i < id_list.size() ; i++){
        answer[i] = ans[id_list[i]];
    }
    return answer;
}