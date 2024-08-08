#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0, cnt = 1;
    for (int i = 0 ; i < progresses.size() ; i++){
        int temp = (100 - progresses[i]) % speeds[i] ? (100 - progresses[i]) / speeds[i] + 1 : (100 - progresses[i]) / speeds[i];
        if (days == 0) {
            days = temp;
        } else if (days >= temp){
            cnt++;
        } else {
            days = temp;
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}