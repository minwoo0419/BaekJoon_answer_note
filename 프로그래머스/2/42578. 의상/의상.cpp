#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cmap;
    for (int i = 0 ; i < clothes.size() ; i++){
        cmap[clothes[i][1]]++;
    }
    for (auto m : cmap){
        answer *= (m.second + 1);
    }
    return answer - 1;
}