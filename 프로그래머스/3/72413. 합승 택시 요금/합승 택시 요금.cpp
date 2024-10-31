#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long INF = 1e9;
vector<vector<long long>> maps;
int N;
void func(){
    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= N ; j++){
            for (int k = 1 ; k <= N ; k++){
                maps[j][k] = min(maps[j][k], maps[j][i] + maps[i][k]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    N = n;
    maps.assign(n+1, vector<long long>(n+1, INF));
    for (auto f : fares){
        maps[f[0]][f[1]] = f[2];
        maps[f[1]][f[0]] = f[2];
    }
    for (int i = 1 ; i <= N ; i++) maps[i][i] = 0;
    func();
    for (int i = 1 ; i <= N ; i++){
        answer = min(answer, maps[s][i] + maps[i][a] + maps[i][b]);
    }
    return answer;
}