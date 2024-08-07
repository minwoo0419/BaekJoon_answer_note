#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> tools;
vector<string> rocks;
int minn = 987654321;
int check(int n, string s){
    if (n == 2 && s == "diamond"){
        return 5;
    } else if (n == 3){
        if (s == "diamond")
            return 25;
        else if (s == "iron")
            return 5;
    }
    return 1;
}
void simul(vector<int> v, int k){
    int sum = 0;
    for (int i = 0 ; i < k ; i++){
        for (int j = i * 5 ; j < min(i * 5 + 5, (int)rocks.size()) ; j++) {
            sum += check(v[i], rocks[j]);
        }
    }
    minn = min(sum, minn);
}
int solution(vector<int> picks, vector<string> minerals) {
    for (int i = 0 ; i < picks.size() ; i++){
        for (int j = 0 ; j < picks[i] ; j++){
            tools.push_back(i + 1);
        }
    }
    sort(tools.begin(), tools.end());
    rocks = minerals;
    int k = minerals.size() / 5;
    k = (minerals.size() % 5 == 0) ? k : (k + 1);
    k = min(k, (int)tools.size());
    do{
        simul(tools, k);
    }while(next_permutation(tools.begin(), tools.end()));
    return minn;
}