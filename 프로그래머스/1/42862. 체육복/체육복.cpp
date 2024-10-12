#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> per(n, 0);
    for (int i = 0 ; i < lost.size() ; i++){
        per[lost[i] - 1]--;
    }
    for (int i = 0 ; i < reserve.size() ; i++){
        per[reserve[i] - 1]++;
    }
    for (int i = 0 ; i < per.size() ; i++){
        if (per[i] == -1){
            if (i > 0 && per[i-1] == 1) {
                per[i] = 0;
                per[i-1] = 0;
            } else if (i < n - 1 && per[i+1] == 1){
                per[i] = 0;
                per[i+1] = 0;
            }
        }
        if (per[i] >= 0) answer++;
    }
    return answer;
}