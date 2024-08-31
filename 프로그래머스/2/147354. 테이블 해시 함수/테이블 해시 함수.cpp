#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> h1, vector<int> h2){
    if (h1[0] == h2[0])
        return h1[1] > h2[1];
    return h1[0] < h2[0];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<vector<int>> v(data.size(), vector<int>(0));
    for (int i = 0 ; i < data.size() ; i++){
        v[i].push_back(data[i][col-1]);
        data[i].erase(data[i].begin() + col - 1);
        for (int j = 0 ; j < data[i].size() ; j++){
            v[i].push_back(data[i][j]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> x;
    for (int i = row_begin - 1 ; i < row_end ; i++){
        int temp = 0;
        for (int j = 0 ; j < v[i].size() ; j++){
            temp += (v[i][j] % (i + 1));
        }
        x.push_back(temp);
    }
    for (int i = 0 ; i < x.size() ; i++){
        answer = answer ^ x[i];
    }
    return answer;
}