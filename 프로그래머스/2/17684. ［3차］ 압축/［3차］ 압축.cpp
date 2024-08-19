#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int idx = 1;
    for (; idx <= 26 ; idx++){
        string c = "";
        c += 'A' + idx - 1;
        m[c] = idx;
    }
    string s = "";
    for (int i = 0 ; i < msg.length() ; i++){
        s += msg[i];
        if (m[s] == 0){
            m[s] = idx++;
            answer.push_back(m[s.substr(0, s.length()-1)]);
            s = "";
            i--;
        }
    }
    answer.push_back(m[s]);
    return answer;
}