#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
int maps[9][9];
void print(){
    for (int i = 0 ; i < 9 ; i++){
        for (int j = 0 ; j < 9 ; j++){
            cout << maps[i][j];
        }
        cout << "\n";
    }
}
bool check(int x, int y, int num){
    for (int i = 0 ; i < 9 ; i++){
        if (maps[x][i] == num || maps[i][y] == num)
            return false;
    }
    int startX = x / 3 * 3;
    int startY = y / 3 * 3;
    for (int i = startX ; i < startX + 3 ; i++){
        for (int j = startY ; j < startY + 3 ; j++){
            if (maps[i][j] == num)
                return false;
        }
    }
    return true;
}
void solve(int cnt){
    if(cnt == 81){
        print();
        exit(0);
    }
    int i = cnt / 9;
    int j = cnt % 9;
    if (maps[i][j])
        solve(cnt+1);
    else{
        for (int k = 1 ; k <= 9 ; k++){
            if (!check(i, j, k))
                continue;
            maps[i][j] = k;
            solve(cnt+1);
            maps[i][j] = 0;
        }
    }
}

int main(int argc, char** argv) {
    for (int i = 0 ; i < 9 ; i++){
        for (int j = 0 ; j < 9 ; j++){
            char a;
            cin >> a;
            maps[i][j] = a - '0';
        }
    }
    solve(0);
    return 0;
}
