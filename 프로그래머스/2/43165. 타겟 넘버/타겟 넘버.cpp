#include <string>
#include <vector>

using namespace std;
vector<int> nums;
int answer = 0, t = 0;
void func(int ans, int idx){
    if (idx == nums.size()){
        if (ans == t)
            answer++;
        return ;
    }
    func(ans + nums[idx], idx + 1);
    func(ans - nums[idx], idx + 1);
}
int solution(vector<int> numbers, int target) {
    nums = numbers;
    t = target;
    func(0, 0);
    return answer;
}