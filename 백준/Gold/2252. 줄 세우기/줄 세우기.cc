#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, ans = 0, maxNode = 0;
vector< vector<int> > tree;
vector<int> lines;
vector<int> visits;
int main(int argc, char** argv) {
    cin >> n >> m;
    tree.assign(n+1, vector<int>(0, 0));
    visits.assign(n+1, 0);
    lines.assign(n+1, 0);
    queue<int> q;

    for (int i = 0 ; i < m ; i++){
        int small, big;
        cin >> small >> big;
        tree[small].push_back(big);
        lines[big]++;
    }
    for (int i = 1 ; i <= n ; i++){
        if (!lines[i]){
            q.push(i);
        }
    }
    int i = 0;
    while(!q.empty()){
        int node = q.front();
        visits[i++] = node;
        q.pop();
        for (int j = 0 ; j < tree[node].size() ; j++){
            int nextNode = tree[node][j];
            lines[nextNode]--;
            if (!lines[nextNode])
                q.push(nextNode);
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << visits[i] << " ";
    }
    return 0;
}
