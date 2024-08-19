#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;
vector<string> strs;
void split(string s, char c){
    string buffer;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buffer, c)){
        if (!buffer.empty())
            strs.push_back(buffer);
    }
}
string func(int n, int k){
    string s = "";
    while(n > 0){
        s = to_string(n % k) + s;
        n /= k;
    }
    return s;
}
bool is_prime(long long n){
    if (n < 2)
        return false;
    for (int i = 2 ; i <= sqrt(n) ; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s = func(n, k);
    split(s, '0');
    for (int i = 0 ; i < strs.size() ; i++){
        if(is_prime(stoll(strs[i])))
            answer++;
    }
    return answer;
}