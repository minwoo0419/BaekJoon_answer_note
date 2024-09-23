#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> appeach(11, 0);
vector<int> ryan(11, 0);
vector<int> answer;
int ans = 0;
int calc(){
    int sum = 0;
    for(int i = 0 ; i < 11 ; i++){
        if (appeach[i] == 0 && ryan[i] == 0)
            continue;
        if (appeach[i] >= ryan[i])
            sum -= (10 - i);
        else
            sum += (10 - i);
    }
    return sum;
}
void dfs(int round, int arrow){
    if (round == -1 || arrow == 0){
        ryan[10] = arrow;
        int temp = calc();
        if (ans < temp){
            ans = temp;
            answer = ryan;
        }
        return ;
    }
    if (appeach[round] < arrow){
        ryan[round] = appeach[round] + 1;
        dfs(round - 1, arrow - ryan[round]);
        ryan[round] = 0;
    }
    dfs(round - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
    appeach = info;
    dfs(10, n);
    if (ans <= 0)
        answer.push_back(-1);
    return answer;
}