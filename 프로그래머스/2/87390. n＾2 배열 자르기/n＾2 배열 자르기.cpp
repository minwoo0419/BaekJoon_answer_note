#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left ; i <= right ; i++)
        answer.push_back((i / n >= i % n) ? i / n + 1 : i % n + 1);
    return answer;
}