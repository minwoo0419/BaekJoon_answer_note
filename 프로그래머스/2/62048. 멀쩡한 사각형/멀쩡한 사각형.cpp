#include <algorithm>
using namespace std;
int gcd(int a, int b){
    while(b > 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
long long solution(int w,int h) {
    int g = gcd(w, h);
    long long answer = (long long)(w - 1) * (long long)(h - 1) + g - 1;
    return answer;
}