#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n, answer = 0, hp;
int calc(vector<int> &check, vector<vector<int>> &dungeons){
    int num = 0;
    int k = hp;
    for (int i = 0 ; i < n ; i++){
        if (k < dungeons[check[i]][0]) break;
        k -= dungeons[check[i]][1];
        num++;
    }
    return num;
}
void dfs(vector<int> &visits, vector<int> &check, vector<vector<int>> &dangeons){
    if (check.size() == n) {
        answer = max(answer, calc(check, dangeons));
        return ;
    }
    for (int i = 0 ; i < n ; i++){
        if (visits[i]) continue;
        visits[i] = 1;
        check.push_back(i);
        dfs(visits, check, dangeons);
        check.pop_back();
        visits[i] = 0;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    hp = k;
    vector<int> visits(n, 0);
    vector<int> check;
    dfs(visits, check, dungeons);
    return answer;
}