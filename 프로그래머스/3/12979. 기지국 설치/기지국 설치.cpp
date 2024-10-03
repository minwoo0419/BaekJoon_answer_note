#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<int> v;
    int num = 1;
    for (int i = 0 ; i < stations.size() ; i++){
        if (stations[i] - w > num){
            v.push_back(stations[i] - w - num);
        }
        num = stations[i] + w + 1;
    }
    if (num <= n) v.push_back(n - num + 1);
    for (int i = 0 ; i < v.size() ; i++){
        int a = v[i] / (2 * w + 1);
        int b = (v[i] % (2 * w + 1)) ? 1 : 0;
        answer += (a + b);
    }
    return answer;
}