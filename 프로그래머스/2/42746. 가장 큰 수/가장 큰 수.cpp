#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;
    for (int i = 0 ; i < numbers.size() ; i++){
        number.push_back(to_string(numbers[i]));
    }
    sort(number.begin(), number.end(), cmp);
    if (number[0] == "0"){
        return "0";
    }
    for (int i = 0 ; i < number.size() ; i++){
        answer += number[i];
    }
    return answer;
}