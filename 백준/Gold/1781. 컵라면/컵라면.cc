#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector< pair<int, int> > probs;
int main(int argc, char** argv) {
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int dead_line, num;
        cin >> dead_line >> num;
        probs.push_back(make_pair(dead_line, num));
    }
    sort(probs.begin(), probs.end());
    for (int i = 0 ; i < n ; i++){
        int dead_line = probs[i].first, num = probs[i].second;
        if (pq.size() < dead_line){
            pq.push(num);
        } else {
            if (pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
    }
    long long sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}
