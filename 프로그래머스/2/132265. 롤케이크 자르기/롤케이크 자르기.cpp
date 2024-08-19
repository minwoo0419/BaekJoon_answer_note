#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    for (int i = 0 ; i < topping.size() ; i++){
        m2[topping[i]]++;
    }
    int c1 = 0, c2 = m2.size();
    for (int i = 0 ; i < topping.size() ; i++){
        m1[topping[i]]++;
        m2[topping[i]]--;
        if(m1[topping[i]] == 1)
            c1++;
        if(m2[topping[i]] == 0)
            c2--;
        if(c1 == c2)
            answer++;
        else if (c1 > c2)
            break;
        
    }
    return answer;
}