#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int j = 0;
    for (int i = 0 ; i < B.size() ; i++){
        while(j < A.size() && A[j] >= B[i]) j++;
        if (j == A.size()) break;
        answer++;
        j++;
    }
    return answer;
}