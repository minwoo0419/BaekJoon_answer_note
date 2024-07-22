#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
long long water[5001];
long long minn = 3000000001;
long long ans[3];
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> water[i];
    }
    sort(water, water + n);
    for (int i = 0 ; i < n - 2 ; i++){
        int e = n - 1;
        int mid = i + 1;
        while(mid < e){
            long long sum = water[i] + water[mid] + water[e];
            if (abs(sum) < minn){
                minn = abs(sum);
                ans[0] = water[i];
                ans[1] = water[mid];
                ans[2] = water[e];
            }
            if (sum < 0){
                mid++;
            } else
                e--;
        }
    }
    for (int i = 0 ; i < 3 ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
