#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, l;
int maps[17][17];
int originMaps[17][17];
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};
int ans = 0;
bool check_dis(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second) <= l;
}

void copyMap(){
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            maps[i][j] = originMaps[i][j];
        }
    }
}

void simul(vector<int> nums){
    int stay = n + 1;
    int cnt = 0;
    while(stay > 1){
        vector< pair<int, int> > canKill;
        for (int i = 0 ; i < nums.size() ; i++){
            vector< pair< int, pair<int, int> > > temp;
            for (int j = 1 ; j < stay ; j++){
                for (int k = 1 ; k <= m ; k++){
                    if (maps[j][k] && check_dis(make_pair(stay, nums[i]), make_pair(j, k))){
                        temp.push_back(make_pair(abs(stay - j) + abs(nums[i] - k), make_pair(k, j)));
                    }
                }
            }
            sort(temp.begin(), temp.end());
            if(!temp.empty()){
                canKill.push_back(make_pair(temp[0].second.second, temp[0].second.first));
            }
        }
        for (int i = 0 ; i < canKill.size() ; i++){
            if (maps[canKill[i].first][canKill[i].second]){
                cnt++;
                maps[canKill[i].first][canKill[i].second] = 0;
            }
        }
        stay--;
    }
    ans = max(ans, cnt);
}
void comb(vector<int> nums, int a){
    if (nums.size() == 3) {
        copyMap();
        simul(nums);
    }
    else {
        for (int i = a ; i <= m ; i++){
            nums.push_back(i);
            comb(nums, i + 1);
            nums.pop_back();
        }
    }
}
int main(int argc, char** argv) {
    cin >> n >> m >> l;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> originMaps[i][j];
        }
    }
    vector<int> nums(0);
    comb(nums, 1);
    cout << ans;
    return 0;
}