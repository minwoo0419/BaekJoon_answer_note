#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, ans = 0, maxNode = 0;
vector< vector<int> > tree;
vector<int> visits(10001, 0);
int find(int x){
    if (visits[x] == x)
        return x;
    return visits[x] = find(visits[x]);
}

bool isSameParent(int x, int y){
    return find(x) == find(y);
}

void unionFind(int x, int y){
    x = find(x);
    y = find(y);
    visits[y] = x;
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        vector<int> temp;
        tree.push_back(temp);
        int parent, child, length;
        cin >> parent >> child >> length;
        tree[i].push_back(length);
        tree[i].push_back(parent);
        tree[i].push_back(child);
    }
    for (int i = 1 ; i <= n ; i++){
        visits[i] = i;
    }
    int sum = 0;
    sort(tree.begin(), tree.end());
    for (int i = 0 ; i < m ; i++){
        int parent = tree[i][1];
        int child = tree[i][2];
        int cost = tree[i][0];
        if (!isSameParent(parent, child)){
            unionFind(parent, child);
            sum += cost;
        }
    }
    cout << sum;
    return 0;
}
