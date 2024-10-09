#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
int n, maxx = 0;
vector<int> visits(10, 0), arr;
int calc(vector<int> &nums){
    int answer = 0;
    for (int i = 0 ; i < n - 1; i++){
        answer += (abs(arr[nums[i]-1] - arr[nums[i+1]-1]));
    }
    return answer;
}
void perm(vector<int> &nums){
    if (nums.size() == n){
        maxx = max(maxx, calc(nums));
        return ;
    }
    for (int i = 1 ; i <= n ; i++){
        if (visits[i]) continue;
        visits[i] = 1;
        nums.push_back(i);
        perm(nums);
        visits[i] = 0;
        nums.pop_back();
    }
}
int main()
{  
    cin >> n;
    vector<int> nums;
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    perm(nums);
    cout << maxx;
    return (0);
}