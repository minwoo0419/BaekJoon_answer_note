#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <map>
using namespace std;
vector<vector<string>> rel;
vector<vector<int>> maps;
bool check_key(vector<int> &nums){
    unordered_set<string> sets;
    vector<int> idx;
    for (int i = 0 ; i < rel.size() ; i++){
        string s;
        for (int j = 0 ; j < rel[i].size() ; j++){
            if (!nums[j]) continue;
            s += rel[i][j];
        }
        sets.insert(s);
    }    
    if (sets.size() != rel.size()) return false;

    for (int i = 0 ; i < nums.size() ; i++) if (nums[i]) idx.push_back(i);
    for (int i = 0 ; i < maps.size() ; i++){
        int cnt = 0;
        for (auto m : maps[i]){
            if (nums[m]) cnt++;
        }
        if (cnt == maps[i].size()) return false;
    }
    maps.push_back(idx);
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int n = relation[0].size();
    rel = relation;
    vector<int> nums(n, 0);
    for (int i = 1 ; i <= n ; i++){
        nums[n - i] = 1;
        do {
            if (check_key(nums)) {
                answer++;
            }
        } while(next_permutation(nums.begin(), nums.end()));
    }
    return answer;
}