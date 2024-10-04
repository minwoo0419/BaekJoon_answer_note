#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int give = 0, take = 0;
    for (int i = deliveries.size() - 1 ; i >= 0 ; i--){
        give -= deliveries[i];
        take -= pickups[i];
        int cnt = 0;
        while(give < 0 || take < 0){
            give += cap;
            take += cap;
            cnt++;
        }
        answer += cnt * (i + 1) * 2;
    }
    return answer;
}