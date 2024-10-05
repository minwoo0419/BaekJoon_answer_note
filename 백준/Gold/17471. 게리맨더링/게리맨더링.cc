#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n, answer = 987654321;
vector<int> person;
vector<vector<int> > nodes;
void bfs(vector<int> &nums, int count){
    int node = 0, cnt = 1, sum = 0;
    for (int i = 0 ; i < n ; i++){
        if(nums[i]) {
            node = i;
            break;
        }
    }
    vector<int> visits(n, 0);
    queue<int> q;
    sum = person[node];
    visits[node] = 1;
    q.push(node);
    while(!q.empty()){
        int tn = q.front();
        q.pop();
        for (int i = 0 ; i < nodes[tn].size() ; i++){
            if (visits[nodes[tn][i]]) continue;
            if (!nums[nodes[tn][i]]) continue;
            cnt++;
            visits[nodes[tn][i]] = 1;
            q.push(nodes[tn][i]);
            sum += person[nodes[tn][i]];
        }
    }
    if (cnt != count) return ;
    for (int i = 0 ; i < n ; i++){
        if (!visits[i]) {
            node = i;
            break;
        }
    }
    visits[node] = 2;
    sum -= person[node];
    q.push(node);
    while(!q.empty()){
        int tn = q.front();
        q.pop();
        for (int i = 0 ; i < nodes[tn].size() ; i++){
            if (visits[nodes[tn][i]]) continue;
            visits[nodes[tn][i]] = 2;
            q.push(nodes[tn][i]);
            sum -= person[nodes[tn][i]];
        }
    }

    for (int i = 0 ; i < n ; i++){
        if (!visits[i]){
            return;
        }
    }
    answer = min(answer ,abs(sum));
}
void comb(vector<int> &nums, int idx, int cnt){
    if (cnt > n / 2) return ;
    bfs(nums, cnt);
    for (int i = idx ; i < n ; i++){
        nums[i] = 1;
        comb(nums, i + 1, cnt + 1);
        nums[i] = 0;
    }
}
int main(int argc, char** argv)
{
    cin >> n;
    person.assign(n, 0);
    nodes.assign(n, vector<int>(0));
    for (int i = 0 ; i < n ; i++) cin >> person[i];
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        for (int j = 0 ; j < a ; j++){
            int b;
            cin >> b;
            nodes[i].push_back(b-1);
            nodes[b-1].push_back(i);
        }
    }
    vector<int> nums(n, 0);
    comb(nums, 0, 0);
    answer == 987654321 ? cout << -1 : cout << answer;
    return 0;
}