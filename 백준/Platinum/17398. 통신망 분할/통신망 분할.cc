#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> parent;
int n, m, q;
int find_parent(int x){
  if (parent[x] < 0) return x;
  return parent[x] = find_parent(parent[x]);
}

long long union_parent(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    if (pa == pb)
      return 0;
    long long sum = parent[pa] * parent[pb];
    parent[pa] += parent[pb];
    parent[pb] = pa;
    return sum;
}
int main() {
  cin >> n >> m >> q;
  long long ans = 0;
  vector< pair<int, int> > lines;
  vector<int> queries;
  vector<int> is_query;
  parent.assign(n + 1, -1);
  is_query.assign(m, 0);
  for (int i = 0 ; i < m ; i++){
    int a, b;
    cin >> a >> b;
    lines.push_back(make_pair(a, b));
  }
  for (int i = 0 ; i < q ; i++){
    int a;
    cin >> a;
    queries.push_back(a - 1);
    is_query[a - 1] = 1;
  }

  for (int i = 0 ; i < m ; i++){
    if (is_query[i] == 0)
      union_parent(lines[i].first, lines[i].second);
  }

  for (int i = q - 1 ; i >= 0 ; i--){
    int a = lines[queries[i]].first;
    int b = lines[queries[i]].second;
    ans += union_parent(a, b);
  }
  cout << ans;
  return 0;
}
