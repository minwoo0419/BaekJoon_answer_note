#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
vector<int> lines;
vector< vector<int> > problem;
vector<int> ans;
int main(int argc, char** argv) {
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int> > pq;
    lines.assign(n+1, 0);
    problem.assign(n+1, vector<int>(0, 0));
    for (int i = 0 ; i < m ; i++){
        int easy, hard;
        cin >> easy >> hard;
        problem[easy].push_back(hard);
        lines[hard]++;
    }
    for (int i = 1; i <= n ; i++){
        if(!lines[i])
            pq.push(i);
    }
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        ans.push_back(node);
        for (int i = 0 ; i < problem[node].size() ; i++){
            int newNode = problem[node][i];
            lines[newNode]--;
            if (!lines[newNode])
                pq.push(newNode);
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
