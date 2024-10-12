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
    if (parent[a] > parent[b]) swap(a, b);
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
    vector<int> group_sizes;
    for (int i = 0; i < n; i++) {
        if (parent[i] < 0) {
            group_sizes.push_back(-parent[i]);  // 그룹의 크기를 저장
        }
    }
    sort(group_sizes.rbegin(), group_sizes.rend());
    if (group_sizes.size() >= 2) {
        answer = group_sizes[0] * group_sizes[1];  // 가장 큰 두 그룹의 크기 곱셈
    } else {
        answer = 0;  // 두 개 이상의 그룹이 존재하지 않으면 0 반환
    }
    return answer;
}