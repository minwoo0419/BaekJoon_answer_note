#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    for (int i = 0 ; i < number.size() - k ; i++){
        int maxNum = number[idx];
        int maxIdx = idx;
        for (int j = idx ; j <= i + k ; j++){
            if (maxNum < number[j]){
                maxIdx = j;
                maxNum = number[j];
            }
        }
        idx = maxIdx + 1;
        answer += maxNum;
    }
    return answer;
}