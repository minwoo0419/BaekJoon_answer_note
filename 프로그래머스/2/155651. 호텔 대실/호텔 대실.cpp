#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> split(string s, char op){
    vector<string> ans;
    string buffer;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buffer, op)){
        if (!buffer.empty())
            ans.push_back(buffer);
    }
    return ans;
}

int calc_time(string s){
    vector<string> time = split(s, ':');
    return stoi(time[0]) * 60 + stoi(time[1]);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> times;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0 ; i < book_time.size() ; i++){
        times.push_back(make_pair(calc_time(book_time[i][0]), calc_time(book_time[i][1])));
    }
    sort(times.begin(), times.end());
    for (int i = 0 ; i < times.size() ; i++){
        if (!q.empty() && q.top() <= times[i].first - 10){
            q.pop();
        }
        q.push(times[i].second);
        answer = max(answer, (int)q.size());
    }
    return answer;
}