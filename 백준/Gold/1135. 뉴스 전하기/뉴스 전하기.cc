#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n;
vector<vector<int> > nodes;

int dfs(int node){
    int ret = 0;
    vector<int> v;
    int p = nodes[node].size() - 1;
    for (int i = 0 ; i < nodes[node].size() ; i++){
        v.push_back(dfs(nodes[node][i]));
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; i++){
        ret = max(v[i] + p, ret);
        p--;
    }
    return ret + 1;
}

int main(int argc, char** argv)
{
    cin >> n;
    nodes.assign(n, vector<int>(0));
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        if (a == -1) continue;
        nodes[a].push_back(i);
    }
    cout << dfs(0) - 1;
    return 0;
}