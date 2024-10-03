#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> ans(4, 0);
vector<pair<int, int> > comb;
vector<vector<int> > v, arr;
int t = 0;
bool check(){
    for (int i = 0 ; i < arr.size() ; i++){
        for (int j = 0 ; j < arr[i].size() ; j++){
            if (arr[i][j] != v[i][j]) return false;
        }
    }
    return true;
}
void func(int cnt){
    if (cnt == 15) {
        if (check()) ans[t] = 1;
        return ;
    }
    for (int k = 0 ; k < 3 ; k++){
        v[comb[cnt].first][k] += 1;
        v[comb[cnt].second][2-k] += 1;
        func(cnt + 1);
        v[comb[cnt].first][k] -= 1;
        v[comb[cnt].second][2-k] -= 1;
    }
}

int main(){
    arr.assign(6, vector<int>(3, 0));
    v.assign(6, vector<int>(3, 0));
    for (int i = 0 ; i < 6 ; i++){
        for (int j = i + 1 ; j < 6 ; j++){
            comb.push_back(make_pair(i, j));
        }
    }
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 6 ; j++){
            for (int k = 0 ; k < 3 ; k++){
                cin >> arr[j][k];
            }
        }
        func(0);
        t++;
    }
    for (int i = 0 ; i < 4 ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}