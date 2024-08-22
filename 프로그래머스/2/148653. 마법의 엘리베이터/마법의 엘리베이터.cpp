#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int func(int num){
    if (num < 10)
        return min(num, 10 - num + 1);
    int n1 = num % 10;
    int n2 = 10 - (num % 10);
    return min(func(num / 10) + num % 10, func(num / 10 + 1) + (10 - num % 10));
}

int solution(int storey) {
    return func(storey);
}