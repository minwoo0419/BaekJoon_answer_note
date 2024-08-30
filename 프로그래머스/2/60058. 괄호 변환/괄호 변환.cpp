#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool is_right(string p){
    int cnt = 0;
    for (int i = 0 ; i < p.length() ; i++){
        if (p[i] == '(')
            cnt++;
        else{
            if (cnt == 0)
                return false;
            cnt--;
        }
    }
    return cnt == 0;
}

int find_idx(string p){
    int a = 0, b = 0;
    for (int i = 0 ; i < p.length() ; i++){
        if (p[i] == '(')
            a++;
        else
            b++;
        if (a != 0 && b != 0 && a == b)
            return i;
    }
    return p.length();
}
string remove_reverse(string p){
    p = p.substr(1, p.length() - 2);
    string s = "";
    for (int i = 0 ; i < p.length() ; i++){
        s += p[i] == '(' ? ")" : "(";
    }
    return s;
}
string func(string p){
    if (p == "")
        return p;
    int idx = find_idx(p) + 1;
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    if (is_right(u))
        return u + func(v);
    return "(" + func(v) + ")" + remove_reverse(u);
    
}
string solution(string p) {
    string answer = "";
    return func(p);
}