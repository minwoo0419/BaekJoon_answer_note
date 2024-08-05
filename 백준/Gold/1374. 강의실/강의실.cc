#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > pq;
vector< pair<long long, long long> > times;
int main(int argc, char** argv) {
    int n, maxx = 0;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        long long num, start, end;
        cin >> num >> start >> end;
        times.push_back(make_pair(start, end));
    }
    sort(times.begin(), times.end());
    for (int i = 0 ; i < n ; i++){
        if (!pq.empty() && pq.top() <= times[i].first){
            pq.pop();
        }
        pq.push(times[i].second);
        maxx = max(maxx, (int)pq.size());
    }
    cout << maxx;
    return 0;
}
