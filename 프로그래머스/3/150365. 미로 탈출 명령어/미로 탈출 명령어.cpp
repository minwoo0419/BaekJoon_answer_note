#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

void sum_str(string &s, string c, int cnt){
    for (int i = 0 ; i < cnt ; i++){
        s += c;
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int a = abs(x - r) + abs(y - c);
    k -= a;
    if (k < 0 || k % 2) //최소거리보다 작거나 k - 최소 거리가 짝수이면 불가능
        return "impossible";
    int dic[4] = {0, 0, 0, 0};
    if (r > x)
        dic[0] += r - x;
    else
        dic[3] += x - r;
    if (c > y)
        dic[2] += c - y;
    else
        dic[1] += y - c;
    //최소 거리일 때 카운팅
    sum_str(answer, "d", dic[0]);
    int t = min(k / 2, n - (x + dic[0]));   //남은 거리 중 d를 더 넣을 수 있는지
    sum_str(answer, "d", t);
    dic[3] += t;    //d만큼 u도 넣어주기
    k -= (t * 2);
    sum_str(answer, "l", dic[1]);   //남은 거리 중 l을 더 넣을 수 있는지
    int h = min(k / 2, y - dic[1] - 1);
    sum_str(answer, "l", h);
    dic[2] += h;    //l만큼 r도 넣어주기
    k -= (h * 2);
    sum_str(answer, "rl", k / 2);   //남은 건 rl로 채우기
    sum_str(answer, "r", dic[2]);
    sum_str(answer, "u", dic[3]);
    return answer;
}