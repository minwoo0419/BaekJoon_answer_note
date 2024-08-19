#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iostream>
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
int calc_min(string hours){
    vector<string> ans = split(hours, ':');
    return stoi(ans[0]) * 60 + stoi(ans[1]);
}
int calc_price(int n, vector<int> fees){
    int temp = (n - fees[0]);
    if (temp < 0)
        return fees[1];
    temp = (temp % fees[2]) ? (temp / fees[2]) + 1 : temp / fees[2];
    return fees[1] + temp * fees[3];
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> temp_m;
    map<string, int> m;
    for (int i = 0 ; i < records.size() ; i++){
        vector<string> cars = split(records[i], ' ');
        if (cars[2] == "IN"){
            temp_m[cars[1]] = calc_min(cars[0]);
        } else {
            m[cars[1]] += calc_min(cars[0]) - temp_m[cars[1]];
            temp_m[cars[1]] = -1;
        }
    }
    for (pair<string, int> p : temp_m){
        if (p.second != -1){
            m[p.first] += calc_min("23:59") - p.second;
        }
    }
    for (pair<string, int> p : m){
        answer.push_back(calc_price(p.second, fees));
    }
    return answer;
}