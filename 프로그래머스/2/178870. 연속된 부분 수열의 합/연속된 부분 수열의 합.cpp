#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<long long> sums;
int length = 987654321;
vector<int> find(int k){
    vector<int> ans(2, 0);
    int s = 0, e = 0;
    while(s <= e){
        long long temp = sums[e] - sums[s];
        if (temp == k) {
            if (length > (e-1 - s)){
                ans[0] = s;
                ans[1] = e - 1;
                length = e - 1 - s;
            }
            e++;
            if (e == sums.size())
                break;
        } else if (temp > k) {
            s++;
        } else {
            e++;
            if (e == sums.size())
                break;
        }
    }
    return ans;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    long long sum = 0;
    sums.push_back(sum);
    for (int i = 0 ; i < sequence.size() ; i++){
        sum += sequence[i];
        sums.push_back(sum);
    }
    return find(k);
}