#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health, maxx = 0;
    map<int, int> maps;
    for (int i = 0 ; i < attacks.size() ; i++){
        maxx = max(maxx, attacks[i][0]);
        maps[attacks[i][0]] = attacks[i][1];
    }
    int cnt = 0;
    for (int i = 1 ; i <= maxx ; i++){
        if (maps.find(i) != maps.end()){
            answer = max(0, answer - maps[i]);
            cnt = 0;
        } else {
            answer = min(health, answer + bandage[1]);
            cnt++;
            if (cnt == bandage[0]) {
                answer = min(health, answer + bandage[2]);
                cnt = 0;
            }
        }
        if (answer == 0) break;
    }
    return answer == 0 ? -1 : answer;
}