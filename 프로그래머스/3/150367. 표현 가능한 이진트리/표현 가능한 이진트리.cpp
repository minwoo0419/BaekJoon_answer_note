#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool is_zero(string str){
    for (int i = 0 ; i < str.length() ; i++){
        if (str[i] != '0')
            return false;
    }
    return true;
}
bool sol(string str){
    int mid = str.length() / 2;
    if (str.length() == 1 || is_zero(str))
        return true;
    string s = str.substr(0, mid);
    string e = str.substr(mid + 1);
    if (str[mid] == '1' && sol(s) && sol(e)){
        return true;
    } else
        return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (int i = 0 ; i < numbers.size() ; i++){
        string temp;
        int idx = 1;
        while (numbers[i] > 0){
            for (int j = 0 ; j < idx ; j++){
                temp.push_back(numbers[i] % 2 + '0');
                numbers[i] /= 2;
            }
            idx*=2;
        }
        reverse(temp.begin(), temp.end());
        if (sol(temp))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}