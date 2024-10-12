#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> maps;
    for (int i = 0 ; i < nums.size() ; i++)
        maps[nums[i]]++;
    answer = min(maps.size(), nums.size() / 2);
    return answer;
}