#include <string>
#include <vector>
#include <cmath>
using namespace std;
long long getNum(long long n){
    if (n == 1) return 0;
    long long ans = 1;
    for (long long i = 2 ; i * i <= n ; i++){
        if (n % i == 0) {
            if (n / i > 10000000) {
                ans = i;
                continue;
            }
            ans = n / i;
            break;
        }
    }
    return ans;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin ; i <= end ; i++){
        answer.push_back(getNum(i));
    }
    return answer;
}