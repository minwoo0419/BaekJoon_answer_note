#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
pair<string, int> split(string str){
    vector<string> ans;
    string buf;
    stringstream sstr;
    sstr.str(str);
    while(getline(sstr, buf, ' ')){
        if (!buf.empty())
            ans.push_back(buf);
    }
    return make_pair(ans[0], stoi(ans[1]));
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> sets;
    int cnt = 0;
    for (int i = 0 ; i < operations.size() ; i++){
        pair<string, int> p = split(operations[i]);
        if (p.first == "I"){
            sets.insert(p.second);
        } else if (p.first == "D"){
            if (sets.size() == 0) continue;
            if (p.second == 1) sets.erase(--sets.end());
            else if (p.second == -1) sets.erase(sets.begin());
        }
    }
    if (sets.size() == 0) return {0, 0};
    answer.push_back(*(--sets.end()));
    answer.push_back(*sets.begin());
    return answer;
}