#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> nums;
vector<int> answer;
long long perm(int n){
    if (n == 1)
        return 1;
    return n * perm(n-1);
}
void find(long long k){
    if (nums.size() == 1){
        answer.push_back(nums[0]);
        return ;
    }
    long long p = perm(nums.size() - 1);
    int idx = 1;
    while(idx * p < k){
        idx++;
    }
    answer.push_back(nums[idx-1]);
    nums.erase(nums.begin() + idx - 1);
    k -= (idx - 1) * p;
    find(k);
}
vector<int> solution(int n, long long k) {
    for (int i = 1 ; i <= n ; i++){
        nums.push_back(i);
    }
    find(k);
    return answer;
}