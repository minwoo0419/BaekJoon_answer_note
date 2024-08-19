#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> m;
    for (int i = 0 ; i < skill.length() ; i++){
        m[skill[i]] = i + 1;
    }
    for (int i = 0 ; i < skill_trees.size() ; i++){
        int idx = 1, j = 0;
        for ( ; j < skill_trees[i].length() ; j++){
            if (m[skill_trees[i][j]]){
                if (idx == m[skill_trees[i][j]])
                    idx++;
                else
                    break;
            }
        }
        if (j == skill_trees[i].length())
            answer++;
    }
    return answer;
}