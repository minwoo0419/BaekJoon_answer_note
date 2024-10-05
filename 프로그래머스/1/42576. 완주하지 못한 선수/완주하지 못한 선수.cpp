#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> maps;
    for (auto p : participant){
        maps[p]++;
    }
    for (auto c : completion){
        maps[c]--;
    }
    for (auto m : maps){
        if (m.second) answer = m.first; 
    }
    return answer;
}