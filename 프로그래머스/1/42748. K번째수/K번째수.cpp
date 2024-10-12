#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    string str = "";
    for (int i = 0 ; i < commands.size() ; i++) {
        vector<int> v;
        int s = commands[i][0] - 1, e = commands[i][1];
        for (int i = s ; i < e ; i++) v.push_back(array[i]);
        sort(v.begin(), v.end());
        answer.push_back(v[commands[i][2]-1]);
    }
    return answer;
}