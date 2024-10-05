#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
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
    if (a > b) swap(a, b);
    parent[b] = a;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0 ; i < n ; i++){
        parent.push_back(i);
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (find_parent(i) == find_parent(j)) continue;
            if (!computers[i][j]) continue;
            union_find(i, j);
        }
    }
    unordered_set<int> sets;
    for (int i = 0 ; i < n ; i++) sets.insert(parent[i]);
    return sets.size();
}