#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
pair<int, int> ans = {0, 0};
vector<vector<int>> user;
vector<int> emoticon;
pair<int, int> calc(vector<int> &dis){
    int sum = 0, count = 0;
    for (int i = 0 ; i < user.size() ; i++){
        int temp = 0;
        for (int j = 0 ; j < n ; j++){
            if (dis[j] < user[i][0]) continue;
            else temp += (emoticon[j] / 100 * (100 - dis[j]));
        }
        if (temp >= user[i][1]) count++;
        else sum += temp;
    }
    return {count, sum};
}

void perm(vector<int> &dis){
    if (dis.size() == n){
        ans = max(ans, calc(dis));
        return ;
    }
    for (int i = 10 ; i <= 40 ; i += 10){
        dis.push_back(i);
        perm(dis);
        dis.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    user = users;
    emoticon = emoticons;
    n = emoticons.size();
    vector<int> dis;
    perm(dis);
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}