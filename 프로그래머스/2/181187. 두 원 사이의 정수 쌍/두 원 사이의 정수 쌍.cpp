#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int i = 1 ; i <= r2 ; i++){
        long long max_y = floor(sqrt((long long)r2 * r2 - (long long)i * i));
        long long min_y = r1 > i ? ceil(sqrt((long long)r1 * r1 - (long long)i * i)) : 0;
        answer += (max_y - min_y + 1);
    }
    return answer * 4;
}