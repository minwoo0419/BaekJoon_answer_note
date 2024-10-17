#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> user;
vector<string> ban;
int answer = 0;
bool check_cnt(vector<string> idx){
    sort(idx.begin(), idx.end());
    do{
        int i = 0;
        for ( ; i < idx.size() ; i++){
            if (idx[i].length() != ban[i].length()) break;
            int flag = 1;
            for (int j = 0 ; j < idx[i].length() ; j++){
                if (ban[i][j] != '*' && idx[i][j] != ban[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
        if (i == idx.size()) return true;
    } while(next_permutation(idx.begin(), idx.end()));
    return false;
}

void perm(vector<string> idx, int num){
    if (idx.size() == ban.size()){
        if (check_cnt(idx)) answer++;
        return ;
    }
    for (int i = num ; i < user.size() ; i++){
        idx.push_back(user[i]);
        perm(idx, i + 1);
        idx.pop_back();
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;
    perm({}, 0);
    return answer;
}