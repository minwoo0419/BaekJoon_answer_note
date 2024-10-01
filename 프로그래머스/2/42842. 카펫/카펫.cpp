#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int b = 1;
    while(1){
        int b2 = (brown - (b + 2) * 2) / 2;
        if (b * b2 == yellow){
            answer.push_back(b2 + 2);
            answer.push_back(b + 2);
            break;
        }
        b++;
    }
    return answer;
}