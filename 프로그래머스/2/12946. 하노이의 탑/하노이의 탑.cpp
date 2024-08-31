#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void push_arr(int a, int b){
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    answer.push_back(ans);
}
void hanoi(int n, int from, int to, int mid){
    if (n == 1){
        push_arr(from, to);
        return ;
    }
    hanoi(n-1, from, mid, to);
    push_arr(from, to);
    hanoi(n-1, mid, to, from);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}