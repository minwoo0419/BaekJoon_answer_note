#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) return {-1};
    for (int i = 0 ; i < n ; i++){
        if (i < s % n) answer.push_back(s / n + 1);
        else answer.push_back(s / n);
    }
    sort(answer.begin(), answer.end());
    return answer;
}