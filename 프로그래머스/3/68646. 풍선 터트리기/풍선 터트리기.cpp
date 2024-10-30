#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<vector<int>> mins((int)a.size(), vector<int>(2, 1000000001));
    for (int i = 1 ; i < a.size() ; i++){
        mins[i][0] = min(mins[i-1][0], a[i-1]);
    }
    for (int i = a.size() - 2 ; i >= 0 ; i--){
        mins[i][1] = min(mins[i+1][1], a[i+1]);
    }
    for (int i = 0 ; i < mins.size() ; i++){
        if (a[i] < mins[i][0] || a[i] < mins[i][1]) answer++;
    }
    return answer;
}