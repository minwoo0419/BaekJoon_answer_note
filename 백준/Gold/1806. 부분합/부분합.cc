#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
int num[100001];
int main(int argc, char** argv)
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> num[i];
    }
    int minn = 987654321;
    int s = 0, e = 0, sum = 0;
    while(s <= e){
        if (sum >= m){
            minn = min(e - s, minn);
            sum -= num[s++];
        } else if (e == n)
            break;
        else{
            sum += num[e++];
        }
    }
    if (minn == 987654321)
        cout << 0;
    else
        cout << minn;
    return 0;
}
