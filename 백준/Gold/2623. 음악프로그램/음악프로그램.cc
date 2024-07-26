#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
vector< vector<int> > people;
vector<int> lines;
int main(int argc, char** argv) {
    cin >> n >> m;
    people.assign(n+1, vector<int>(0, 0));
    lines.assign(n+1, 0);
    for (int i = 0 ; i < m ; i++){
        int k;
        cin >> k;
        int temp = 0;
        for (int j = 0 ; j < k ; j++){
            int a;
            cin >> a;
            if (j > 0){
                people[temp].push_back(a);
                lines[a]++;
            }
            temp = a;
        }
    }
    queue<int> q;
    for (int i = 1 ; i <= n ; i++){
        if (!lines[i]){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0 ; i < people[node].size() ; i++){
            int newNode = people[node][i];
            lines[newNode]--;
            if (!lines[newNode])
                q.push(newNode);
        }
    }
    if (ans.size() != n){
        cout << 0;
    } else{
        for (int i = 0 ; i < n ; i++){
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
