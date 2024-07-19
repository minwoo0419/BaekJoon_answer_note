#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, l;
vector< pair<int, int> > water;

int main(int argc, char** argv)
{
    cin >> n >> l;
    for (int i = 0 ; i < n ; i++){
        int s, e;
        cin >> s >> e;
        water.push_back(make_pair(e, s));
    }
    sort(water.begin(), water.end());
    int temp = water[n-1].first;
    int cnt = 0;
    for (int i = n-1 ; i >= 0 ; i--){
        int poss = water[i].second;
        if (temp > water[i].first)
            temp = water[i].first;
        while(temp > poss){
            temp -= l;
            cnt++;
        }

    }
    cout << cnt;
    return 0;
}
