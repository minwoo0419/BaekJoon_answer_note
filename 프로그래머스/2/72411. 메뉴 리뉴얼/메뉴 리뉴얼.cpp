#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
vector<string> ss;
vector<pair<int, string>> ans;
int find(string s){
    int cnt = 0;
    for (int i = 0 ; i < ss.size() ; i++){
        int len = 0;
        for (int j = 0 ; j < ss[i].length() ; j++){
            for (int k = 0 ; k < s.length() ; k++){
                if (ss[i][j] == s[k]){
                    len++;
                    k++;
                    break;
                }
            }
        }
        if (len == s.length())
                cnt++;
    }
    return cnt;
}

void comb(int size, string s, int idx){
    if (s.length() == size){
        int n = find(s);
        if (n > 1){
            ans.push_back(make_pair(n, s));
        }
        return ;
    }
    for (int i = idx ; i < 26 ; i++){
        char c = 'A' + i;
        comb(size, s + c, i + 1);
    }
}
bool cmp(pair<int, string> p1, pair<int, string> p2){
    return p1.first > p2.first;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    ss = orders;
    for (int i = 0 ; i < course.size() ; i++){
        comb(course[i], "", 0);
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0 ; i < ans.size() ; i++){
            answer.push_back(ans[i].second);
            if (i < ans.size() - 1 && ans[i].first != ans[i+1].first)
                break;
        }
        ans.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}