#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> per = {"12345", "21232425", "3311224455"};
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int check_cor(int idx, vector<int> &answers){
    int n = per[idx].length(), cnt = 0;
    for (int i = 0 ; i < answers.size() ; i++){
        if ((int)(per[idx][i % n] - '0') == answers[i]) cnt++;
    }
    return cnt;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> v;
    for (int i = 0 ; i < 3 ; i++){
        v.push_back(make_pair(check_cor(i, answers), i + 1));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0 ; i < 3 ; i++) {
        if (i == 0)
            answer.push_back(v[i].second);
        else{
            if (v[i-1].first > v[i].first) break;
            answer.push_back(v[i].second);
        }
    }
    return answer;
}