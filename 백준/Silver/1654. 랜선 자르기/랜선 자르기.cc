#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long n;
long long h;
vector<long long> trees;

int main(int argc, char** argv)
{
    cin >> n >> h;
    for (int i = 0 ; i < n ; i++){
        long long t;
        cin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());
    long long s = 1, e = trees[n-1];
    long long ans = 0;
    while(s <= e){
        long long mid = (s + e) / 2;
        long long sum = 0;
        for (int i = 0 ; i < n ; i++){
            sum += trees[i] / mid;
        }
        if (sum >= h){
            ans = max(ans, mid);
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << ans;
    return 0;
}
