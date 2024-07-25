#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, ans = 0, maxNode = 0;
vector< vector< pair<int, int> > > tree(10001);
vector<int> visits(10001, 0);
void dfs(int node, int length){
    if (visits[node])
        return ;
    visits[node] = 1;
    if (ans < length){
        ans = length;
        maxNode = node;
    }
    for (int i = 0 ; i < tree[node].size() ; i++){
        dfs(tree[node][i].first, length + tree[node][i].second);
    }
}
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++){
        int parent, child, length;
        cin >> parent >> child >> length;
        tree[parent].push_back(make_pair(child, length));
        tree[child].push_back(make_pair(parent, length));
    }
    //루트 노드에서 가장 먼 노드 찾기
    dfs(1, 0);
    visits.assign(n+1, 0);
    //가장 먼 노드에서 가장 먼 노드 찾기
    dfs(maxNode, 0);
    cout << ans;
    return 0;
}
