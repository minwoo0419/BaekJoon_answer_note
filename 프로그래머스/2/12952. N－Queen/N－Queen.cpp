#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
vector<int> visits;
vector<int> idx;
int answer = 0;
int N;
bool poss(int x){
    for (int i = 0 ; i < idx.size() ; i++){
        if (abs((int)idx.size() - i) == abs(x - idx[i])) return false;
    }
    return true;
}
void func(){
    if (idx.size() == N){
        answer++;
        return ;
    }
    for (int i = 0 ; i < N ; i++){
        if (visits[i]) continue;
        if (!poss(i)) continue;
        visits[i] = 1;
        idx.push_back(i);
        func();
        visits[i] = 0;
        idx.pop_back();
    }
}

int solution(int n) {
    N = n;
    visits.assign(N, 0);
    func();
    return answer;
}