#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> m;
    int answer = 0;
    for (int i = 0 ; i < want.size() ; i++){
        m[want[i]] = number[i];
    }
    for (int i = 0 ; i <= discount.size() - 10 ; i++){
        int flag = 1;
        for (int j = 0 ; j < want.size() ; j++){
            if (count(discount.begin() + i, discount.begin() + i + 10, want[j]) < number[j]){
                flag = 0;
                break;
            }
        }
        if (flag)
            answer++;
    }
    return answer;
}