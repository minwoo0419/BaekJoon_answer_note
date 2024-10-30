#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> v;
    vector<double> extent;
    v.push_back(k);
    while(k > 1){
        k = (k % 2) ? k * 3 + 1 : k / 2;
        v.push_back(k);
    }
    extent.push_back(0);
    for (int i = 1 ; i < v.size() ; i++){
        double ex = (double)(v[i] + v[i-1]) / 2;
        extent.push_back(extent[i-1] + ex);
    }
    int n = v.size();
    for (int i = 0 ; i < ranges.size() ; i++){
        int s = ranges[i][0];
        int e = ranges[i][1];
        if (s > n + e - 1) {
            answer.push_back(-1);
            continue;
        }
        answer.push_back(extent[n + e - 1] - extent[s]);
    }
    return answer;
}