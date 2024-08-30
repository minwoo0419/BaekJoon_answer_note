#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;
vector<char> op;
vector<long long> num;
long long ans = 0;
vector<long long> split(string s, char op){
    vector<long long> ans;
    string buffer;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buffer, op)){
        if(buffer.empty())
            continue;
        ans.push_back(stoi(buffer));
    }
    return ans;
}

long long operation(long long a, long long b, char op){
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        return a * b;
}

long long solution(string expression) {
    vector<char> c = {'*', '+', '-'};
    for (int i = 0 ; i < expression.length() ; i++){
        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
            op.push_back(expression[i]);
            expression[i] = ' ';
        }
    }
    num = split(expression, ' ');
    do{
        vector<char> t_op = op;
        vector<long long> t_num = num;
        for (int i = 0 ; i < c.size() ; i++){
            for (int j = 0 ; j < t_op.size() ; j++){
                if (c[i] != t_op[j])
                    continue;
                t_num[j] = operation(t_num[j], t_num[j+1], t_op[j]);
                t_num.erase(t_num.begin() + j + 1);
                t_op.erase(t_op.begin() + j);
                j--;   
            }
        }
        ans = max(ans, abs(t_num[0]));
    }while(next_permutation(c.begin(), c.end()));
    return ans;
}