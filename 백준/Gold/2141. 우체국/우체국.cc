#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
vector< pair<long long, long long> > towns;
int main(int argc, char** argv) {
    cin >> n;
    long long sum = 0;
    for (int i = 0 ; i < n ; i++){
        long long num, peo;
        cin >> num >> peo;
        towns.push_back(make_pair(num, peo));
        sum += peo;
    }
    sort(towns.begin(), towns.end());
    long long temp = 0, ans = 0;
    for (int i = 0 ; i < n ; i++){
        temp += towns[i].second;
        if (temp >= (sum + 1) / 2){
            ans = towns[i].first;
            break;
        }
    }
    cout << ans;
    return 0;
}
