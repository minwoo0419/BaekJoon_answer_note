#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string arr = "0123456789ABCDEF";
string func(int num, int n){
    string s = "";
    while(num > 0){
        s = arr[num % n] + s;
        num /= n;
    }
    return s;
}
string solution(int n, int t, int m, int p) {
    string temp = "0";
    string answer = "";
    for (int i = 1 ; i < t * m ; i++){
        temp += func(i, n);
    }
    for (int i = p - 1 ; i < t * m ; i += m){
        answer += temp[i];
    }
    return answer;
}