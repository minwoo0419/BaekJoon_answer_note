#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int t = 0, idx = 0, s = -1;
    while(idx < number.length()){
        if (t < k){
            int j = (k - t < answer.length()) ? answer.length() - k + t : 0;
            while(j < answer.length()){
                if (answer[j] < number[idx])
                    break;
                j++;
            }
            if (j < answer.length()){
                s = j;
                t += (answer.length() - s);
            }
        }
        if (s != -1){
            answer = answer.substr(0, s) + number[idx++];
            s = -1;
        } else
            answer += number[idx++];
    }
    answer = answer.substr(0, answer.length() - k + t);
    return answer;
}