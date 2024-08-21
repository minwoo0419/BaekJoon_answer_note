#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0 ; i < numbers.size() ; i++){
        int len = 0;
        long long temp = numbers[i];
        if (temp % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else{
            while(temp % 2){
                temp /= 2;
                len++;
            }
            answer.push_back(numbers[i] + pow(2, len - 1));
        }
    }
    return answer;
}