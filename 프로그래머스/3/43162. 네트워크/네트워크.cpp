#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> parent;

int find_parent(int n){
    if (parent[n] < 0) return n;
    return parent[n] = find_parent(parent[n]);
}

void merge(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return ;
    if ( a > b) swap(a, b);
    parent[b] = a;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    parent.assign(n, -1);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if(computers[i][j]) merge(i, j);
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (parent[i] < 0) answer++;
    }
    return answer;
}