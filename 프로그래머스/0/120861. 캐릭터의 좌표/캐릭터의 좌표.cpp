#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    unordered_map<string, pii> arr;
    arr["up"] = make_pair(0, 1);
    arr["down"] = make_pair(0, -1);
    arr["left"] = make_pair(-1, 0);
    arr["right"] = make_pair(1, 0);
    for (int i = 0 ; i < keyinput.size() ; i++){
        pii tmp = arr[keyinput[i]];
        if (abs(answer[0] + tmp.first) > board[0] / 2 || abs(answer[1] + tmp.second) > board[1] / 2) continue;
        answer[0] += tmp.first;
        answer[1] += tmp.second;
    }
    return answer;
}