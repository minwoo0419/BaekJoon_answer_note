#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> m, m2;
    int answer = 0;
    for (int i = 0 ; i < want.size() ; i++){
        m[want[i]] = number[i];
    }
    for (int i = 0 ; i < 9 ; i++){
        m2[discount[i]]++;
    }
    for (int i = 9 ; i < discount.size() ; i++){
        m2[discount[i]]++;
        if (m == m2) answer++;
        m2[discount[i-9]]--;
        if (m2[discount[i-9]] ==0) m2.erase(discount[i - 9]);
    }
    return answer;
}