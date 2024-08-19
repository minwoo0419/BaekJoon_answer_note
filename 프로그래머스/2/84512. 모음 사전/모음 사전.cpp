#include <string>
#include <vector>
#include <iostream>
using namespace std;
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
int answer = 987654321, cnt = 0;
void dfs(string s, string word){
    if (answer < cnt)
        return ;
    if (s.length() == 5)
        return ;
    for (int i = 0 ; i < 5 ; i++){
        cnt++;
        if (!word.compare(s + alpha[i])){
            answer = cnt;
            return ;
        }
        dfs(s + alpha[i], word);
    }
}
int solution(string word) {
    dfs("", word);
    return answer;
}