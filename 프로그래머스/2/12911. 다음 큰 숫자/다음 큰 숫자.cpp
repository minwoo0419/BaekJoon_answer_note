#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n) {
    int tmp = n, cnt = 0, first = 0;
    int flag = 1;
    while( tmp > 0){
        if (tmp % 2){
            cnt++;
            flag = 0;
        }
        tmp /= 2;
        if (flag)
            first++;
    }
    tmp = n + pow(2, first);
    int temp = tmp;
    first = 0;
    int cnt2 = 0;
    while(temp > 0){
        if (temp % 2)
            cnt2++;
        temp /= 2;
    }
    temp = tmp;
    while(temp > 0 && first < cnt - cnt2){
        if (temp % 2 == 0){
            tmp += pow(2, first);
            first++;
        }
        temp /= 2;
    }
    return tmp;
}