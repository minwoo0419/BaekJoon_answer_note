#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int t = 0 ; t < T ; t++){
        long long n, sum = 0;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        cin >> n;
        for (int i = 0 ; i < n ; i++){
            int a;
            cin >> a;
            pq.push(a);
        }
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(a + b);
            sum += a + b;
        }
        cout << sum << "\n";
    }
    return 0;
}
