#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
#define INF (~0LLU >> 2)
int n;
vector<int> visits(10, 0);
vector<char> str;
string minn = "9876543210";
string maxx = "0123456789";
bool check(string &nums){
    for (int i = 0 ; i < n ; i++){
        if (str[i] == '>' && nums[i] < nums[i+1]) return false;
        else if (str[i] == '<' && nums[i] > nums[i+1]) return false;
    }
    return true;
}
void perm(string nums){
    if (nums.size() == n + 1){
        if (!check(nums)) return ;
        if (minn > nums) minn = nums;
        if (maxx < nums) maxx = nums;
        return ;
    }
    for (int i = 0 ; i <= 9 ; i++){
        if (visits[i]) continue;
        visits[i] = 1;
        perm(nums + to_string(i));
        visits[i] = 0;
    }
}
int main()
{  
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        char c;
        cin >> c;
        str.push_back(c);
    }
    string nums = "";
    perm(nums);
    cout << maxx << "\n" << minn;
    return (0);
}