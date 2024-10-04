#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

string link(string s, string c, int a){
    for (int i = 0 ; i < a ; i++){
        s += c;
    }
    return s;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    vector<int> arr(4, 0);
    int rem = k - abs(x - r) - abs(y - c); //도착했는데 남은 거리
    if (rem < 0 || rem % 2) return "impossible"; //음수거나 나머지 1이면 안됨
    if (x < r) {
        arr[0] += (r - x);
    } else {
        arr[3] += (x - r);
    }
    if (c < y) {
        arr[1] += (y - c);
    } else {
        arr[2] += (c - y);
    }
    int canDown = min(rem / 2, n - (x + arr[0]));
    arr[0] += canDown;
    arr[3] += canDown;
    rem -= canDown * 2;
    int canLeft = min(rem / 2, y - arr[1] - 1);
    arr[1] += canLeft;
    arr[2] += canLeft;
    rem -= canLeft * 2;
    answer = link(answer, "d", arr[0]);
    answer = link(answer, "l", arr[1]);
    answer = link(answer, "rl", rem / 2);
    answer = link(answer, "r", arr[2]);
    answer = link(answer, "u", arr[3]);
    return answer;
}