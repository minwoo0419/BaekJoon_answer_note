#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
long long water[100001];
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> water[i];
    }
    sort(water, water + n);
    pair<int, int> idx;
    int s = 0, e = n - 1;
    long long ans = 2000000001;
    while(s < e){
        int temp = water[e] + water[s];
        if (ans >= abs(temp)){
            ans = abs(temp);
            idx = make_pair(s, e);
        }
        if (temp < 0)
            s++;
        else
            e--;
    }
    cout << water[idx.first] << " " << water[idx.second];
    return 0;
}
