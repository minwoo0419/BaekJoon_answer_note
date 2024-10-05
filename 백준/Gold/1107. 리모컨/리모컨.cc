#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m, answer = 987654321;
string str;
vector<int> broken;
int main(int argc, char** argv)
{
    cin >> n >> m;
    str = to_string(n);
    broken.assign(10, 0);
    for (int i = 0 ; i < m ; i++){
        int a;
        cin >> a;
        broken[a] = 1;
    }
    answer = abs(stoi(str) - 100);
    for (int i = 0 ; i <= 999999 ; i++){
        string s = to_string(i);
        int flag = 0;
        for (int i = 0 ; i < s.length() ; i++){
            if (broken[s[i] - '0']) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        answer = min(answer, (int)s.size() + abs(stoi(str) - stoi(s)));
    }
    cout << answer;
    return 0;
}