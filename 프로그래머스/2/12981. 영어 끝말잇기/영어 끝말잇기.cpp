#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool find(vector<string> words, int idx){
    for (int i = 0 ; i < idx ; i++){
        if (words[i].compare(words[idx]) == 0)
            return true;
    }
    return false;
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    for (int i = 1 ; i < words.size() ; i++){
        if (words[i][0] != words[i-1].back() || find(words, i)){
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
    }
    return answer;
}