#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, hp, ans = 0;
vector<vector<int>> maps;
vector<int> v;
int find_answer(vector<int> &check){
    int i = 0, k = hp;
    for ( ; i < check.size() ; i++){
        if (k < maps[v[i]][0])
            break;
        k -= maps[v[i]][1];
    }
    return i;
}
void perm(vector<int> &check, int cnt){
    if (cnt == n){
        ans = max(ans, find_answer(check));
        return ;
    }
    for (int i = 0 ; i < n ; i++){
        if (!check[i]){
            check[i] = 1;
            v.push_back(i);
            perm(check, cnt + 1);
            v.pop_back();
            check[i] = 0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    maps = dungeons;
    hp = k;
    n = dungeons.size();
    vector<int> check(n, 0);
    perm(check, 0);
    return ans;
}