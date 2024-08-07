#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int> &v1, vector<int> &v2){
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] < v2[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    int e = targets[0][1];
    for (int i = 1 ; i < targets.size() ; i++){
        if (e <= targets[i][0]) {
            e = targets[i][1];
            answer++;
        }
    }
    return answer;
}