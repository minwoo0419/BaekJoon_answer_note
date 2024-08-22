#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    char c2[3] = {'4', '1', '2'};
    while (n > 0){
        answer = c2[n % 3] + answer;
        if (n % 3 == 0){
            n -= 1;
        }
        n /= 3;
    }
    return answer;
}

