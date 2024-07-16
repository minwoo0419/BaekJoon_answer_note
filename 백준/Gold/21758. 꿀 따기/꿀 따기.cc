#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int hunny[100001];
int sums[100001];
int endIdx;
int main(int argc, char** argv)
{
    int sum = 0, maxx = 0;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> hunny[i];
        sum += hunny[i];
        sums[i] = sum;
    }
    //벌 꿀통 벌
    for (int i = 1 ; i < n - 1 ; i++){
        maxx = max(maxx, (sums[i] - sums[0]) + (sums[n-2] - sums[i - 1]));
    }
    //벌 벌 꿀통
    for (int i = 1 ; i < n - 1 ; i++){
        maxx = max(maxx, (sums[n-1] - sums[0]) - hunny[i] + (sums[n-1] - sums[i]));
    }
    //꿀통 벌 벌
    for (int i = 1 ; i < n - 1 ; i++){
        maxx = max(maxx, (sums[n-2] - hunny[i]) + sums[i-1]);
    }
    cout << maxx;
    return 0;
}
