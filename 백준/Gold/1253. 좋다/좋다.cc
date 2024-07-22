#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, cnt = 0;
long long num[2001];
void check_good(int idx){
    int s = 0, e = n - 1;
    while(s < e){
        long long temp = num[s] + num[e];
        if (temp == num[idx]){
            if (s != idx && e != idx){
                cnt++;
                break;
            } else if ( s == idx){
                s++;
            } else if (e == idx){
                e--;
            }
        } else if (temp < num[idx])
            s++;
        else
            e--;
    }
}
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = 0 ; i < n ; i++){
        check_good(i);
    }
    cout << cnt;
    return 0;
}
