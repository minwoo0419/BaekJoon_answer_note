#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
vector<int> prime;
vector<int> num;
int main(int argc, char** argv) {
    cin >> n;

    num.assign(n+1, 1);
    for (int i = 2 ; i * i <= n ; i++){
        if (!num[i])
            continue;
        for (int j = i * 2 ; j <= n ; j += i){
            num[j] = 0;
        }
    }
    for (int i = 2 ; i <= n ; i++){
        if (num[i])
            prime.push_back(i);
    }
    int cnt = 0;
    int s = 0, e = 0, sum = 0;
    while(s <= e){
        if (sum <= n){
            if (sum == n)
                cnt++;
            if (e == prime.size())
                break;
            sum += prime[e++];
        } else {
            sum -= prime[s++];
        }
    }
    cout << cnt;
    return 0;
}
