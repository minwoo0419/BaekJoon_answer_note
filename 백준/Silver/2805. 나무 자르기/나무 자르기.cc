#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
long long h;
vector<long long> trees;

int main(int argc, char** argv)
{
    cin >> n >> h;
    for (int i = 0 ; i < n ; i++){
        int t;
        cin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());
    int s = 0, e = trees[n-1];
    long long  ans = 0;
    while(s <= e){
        int mid = (s + e) / 2;
        long long sum = 0;
        for (int i = 0 ; i < n ; i++){
            if (mid <= trees[i]){
                sum += (trees[i] - mid);
            }
        }
        if (sum >= h){
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    cout << ans;
    return 0;
}
