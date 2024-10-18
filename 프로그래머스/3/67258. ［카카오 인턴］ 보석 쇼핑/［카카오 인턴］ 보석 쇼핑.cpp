#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    int len = gems.size();
    unordered_map<string, int> maps;
    unordered_set<string> sets;
    for (auto g : gems) sets.insert(g);
    int eidx = 0, sidx = 0;
    maps[gems[0]]++;
    while(sidx <= eidx){
        if (maps.size() == sets.size()){
            if (len > (eidx - sidx)){
                len = eidx - sidx;
                answer[0] = sidx + 1;
                answer[1] = eidx + 1;
            }
            if (maps[gems[sidx]] == 1) maps.erase(gems[sidx++]);
            else maps[gems[sidx++]]--;
        } else if (eidx < gems.size() - 1) {
            maps[gems[++eidx]]++;
        } else {
            break;
        }
    }
    return answer;
}