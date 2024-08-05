#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
int gates[100001];
int find(int a){
    if (a == gates[a])
        return a;
    return gates[a] = find(gates[a]);
}
void join(int p, int s){
    int fp = find(p), fs = find(s);
    if (fp != fs)
        gates[fs] = fp;
}
int main(int argc, char** argv) {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++){
        gates[i] = i;
    }
    for (int i = 0 ; i < m ; i++){
        int plane;
        cin >> plane;
        if (!find(plane))
            break;
        cnt++;
        //앞의 게이트와 연결시켜준다.
        join(find(plane) - 1, find(plane));
    }
    cout << cnt;
    return 0;
}
