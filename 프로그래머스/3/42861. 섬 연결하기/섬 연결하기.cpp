#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> parent;

int find_parent(int n){
    if (parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return ;
    parent[b] = a;
}
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parent.assign(n, 0);
    for (int i = 0 ; i < n ; i++){
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), cmp);
    for (int i = 0 ; i < costs.size() ; i++){
        int a = costs[i][0];
        int b = costs[i][1];
        if (find_parent(a) == find_parent(b)) continue;
        answer += costs[i][2];
        union_find(a, b);
    }
    return answer;
}