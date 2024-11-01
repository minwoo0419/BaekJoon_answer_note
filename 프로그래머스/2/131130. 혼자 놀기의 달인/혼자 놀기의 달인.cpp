#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> parent;
int n;
int find_parent(int n){
    if (parent[n] < 0) return n;
    return parent[n] = find_parent(parent[n]);
}
void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return ;
    // if (parent[a] > parent[b]) swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
}

int solution(vector<int> cards) {
    int answer = 1;
    n = cards.size();
    parent.assign(n, -1);
    for (int i = 0 ; i < cards.size() ; i++){
        union_parent(i, cards[i] - 1);
    }
    sort(parent.begin(), parent.end());
    for (int i = 0 ; i < 2 ; i++){
        answer *= parent[i];
    }
    if (answer < 0 ) answer = 0;
    return answer;
}