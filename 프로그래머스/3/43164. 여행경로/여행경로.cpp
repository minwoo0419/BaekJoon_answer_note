#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string, vector<pair<string, int>>> maps;
int sizes = 0;
vector<string> dfs(vector<string> ans){
    if(ans.size() == sizes){
        return ans;
    }
    vector<string> tmp;
    for (auto &i : maps[ans.back()]){
        if (i.second) continue;
        i.second = 1;
        ans.push_back(i.first);
        tmp = dfs(ans);
        if (!tmp.empty()) return tmp;
        i.second = 0;
        ans.pop_back();
    }
    return {};
}
bool cmp(pair<string, int> a, pair<string, int> b){
    return a.first > b.first;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sizes = tickets.size() + 1;
    for (int i = 0 ; i < tickets.size() ; i++){
        maps[tickets[i][0]].push_back(make_pair(tickets[i][1], 0));
    }
    for (auto &m : maps){
        sort(m.second.begin(), m.second.end());
    }
    return dfs({"ICN"});
}