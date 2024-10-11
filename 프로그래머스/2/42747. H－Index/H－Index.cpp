#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0, n = citations.size();
    sort(citations.rbegin(), citations.rend());
    for (int i = 0 ; i < n ; i++){
        if (citations[i] >= i + 1) {
            answer = i + 1;
        }
    }
    return answer;
}