#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> visits;
vector<string> word;
int ans = 0;
bool check_str(string a, string b){
    int cnt = 0;
    for (int i = 0 ; i < a.length() ; i++){
        if (a[i] != b[i]) cnt++;
    }
    return cnt == 1;
}
int bfs(string s, string tar){
    queue<pair<string, int>> q;
    q.push(make_pair(s, 0));
    while(!q.empty()){
        string str = q.front().first;
        int cnt = q.front().second;
        if (str == tar) return cnt;
        q.pop();
        for (int i = 0 ; i < word.size() ; i++){
            if (visits[i]) continue;
            if (!check_str(str, word[i])) continue;
            visits[i] = 1;
            q.push(make_pair(word[i], cnt + 1));
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    visits.assign(words.size() + 1, 0);
    word = words;
    return bfs(begin, target);
}