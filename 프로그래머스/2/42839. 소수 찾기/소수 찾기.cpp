#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;
set<int> ans;
bool is_prime(int n){
    if (n < 2)
        return false;
    for (int i = 2 ; i <= sqrt(n) ; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}
void func(vector<int> idx, string numbers, string s){
    if (!s.empty()){
        int num = stoi(s);
        if (is_prime(num)){
            ans.insert(num);
        }
    }
    for (int i = 0 ; i < numbers.length() ; i++){
        if (!idx[i]){
            idx[i] = 1;
            func(idx, numbers, s + numbers[i]);
            idx[i] = 0;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    vector<int> idx(numbers.size(), 0);
    func(idx, numbers, "");
    return ans.size();
}