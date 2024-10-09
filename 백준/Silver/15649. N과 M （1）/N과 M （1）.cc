#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
int n, m;
string str;
vector<int> visits(10, 0);
void perm(vector<int> &nums){
    if (nums.size() == m){
        for (int i = 0 ; i < nums.size() ; i++)
            cout << nums[i] << " ";
        cout << "\n";
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
    cin >> n >> m;
    vector<int> nums;
    perm(nums);
    return (0);
}