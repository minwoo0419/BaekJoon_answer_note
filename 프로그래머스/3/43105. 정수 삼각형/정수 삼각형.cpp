#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    for (int i = 1; i < triangle.size() ; i++){
        for (int j = 0 ; j < triangle[i].size() ; j++){
            int s = max(j-1, 0);
            int e = min((int)triangle[i-1].size()-1, j);
            triangle[i][j] += max(triangle[i-1][s], triangle[i-1][e]);
            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}