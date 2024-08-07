#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<string, int>> stk;
int get_minute(string time){
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 5));
}
bool cmp(vector<string> a, vector<string> b){
    return a[1] < b[1];
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    int time = 0;
    for (int i = 0 ; i < plans.size() ; i++){
        //각 과제의 시작 시간
        int start_time = get_minute(plans[i][1]);
        //시작 시간이 될 때 까지 진행 중인 일이 끝나는지 본다.
        while(time < start_time){
            time++;
            if (stk.empty())
                continue;
            stk.back().second--;
            if (!stk.back().second){
                answer.push_back(stk.back().first);
                stk.pop_back();
            }
        }
        //시작 시간이 되었으면 진행 중인 일로 추가
        stk.push_back(make_pair(plans[i][0], stoi(plans[i][2])));
    }
    while(!stk.empty()){
        answer.push_back(stk.back().first);
        stk.pop_back();
    }
    return answer;
}