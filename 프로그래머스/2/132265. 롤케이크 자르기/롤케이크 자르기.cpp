#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    int a1 = 0, a2 = 0;
    for (int i = 0 ; i < topping.size() ; i++){
        m2[topping[i]]++;
        if (m2[topping[i]] == 1) a2++;
    }
    for (int i = 0 ; i < topping.size() ; i++){
        m2[topping[i]]--;
        m1[topping[i]]++;
        if (m2[topping[i]] == 0) a2--;
        if (m1[topping[i]] == 1) a1++;
        if (a2 == a1) answer++;
    }
    return answer;
}