#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dd = pow(d, 2);
    for (long long i = 0 ; i <= d ; i += k){
        answer += (long long)sqrt(dd - pow(i, 2)) / k + 1;
    }
    return answer;
}