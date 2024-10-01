#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer = 0;
vector<string> arr(5, "");

bool isNear(vector<int> &nums){
    vector<vector<int> > visits(5, vector<int>(5, 0));
    queue<int> q;
    int cnt = 1;
    q.push(nums[0]);
    visits[nums[0] / 5][nums[0] % 5] = 1;
    while(!q.empty()){
        int x = q.front() / 5;
        int y = q.front() % 5;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visits[nx][ny]) continue;
            if (find(nums.begin(), nums.end(), nx * 5 + ny) == nums.end()) continue;
            visits[nx][ny] = 1;
            q.push(nx * 5 + ny);
            cnt++;
        }
    }
    return cnt == 7;
}

void comb(int idx, vector<int> &nums, int count){
    if (count < 4 && (4 - count) > (7 - nums.size())) return ;
    if (nums.size() == 7){
        if (isNear(nums)) answer++;
        return ;
    }
    for (int i = idx ; i < 25 ; i++){
        nums.push_back(i);
        int x = i / 5;
        int y = i % 5;
        if (arr[x][y] == 'S') comb(i + 1, nums, count + 1);
        else comb(i + 1, nums, count);
        nums.pop_back();
    }
}
int main(){
    for (int i = 0 ; i < 5 ; i++) cin >> arr[i];
    vector<int> nums(0);
    comb(0, nums, 0);
    cout << answer;
    return 0;
}