#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int calc(string s){
    vector<int> time;
    stringstream sstr;
    string buf;
    sstr.str(s);
    int idx = 1;
    while(getline(sstr, buf, ':')){
        if (buf.empty()) continue;
        time.push_back(stoi(buf));
    }
    return time[0] * 60 + time[1];
}
string trans(string s){
    return s.length() == 1 ? "0" + s : s;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int ans = 0;
    vector<int> times;
    for (int i = 0 ; i < timetable.size() ; i++){
        times.push_back(calc(timetable[i]));
    }
    sort(times.begin(), times.end());
    int idx = 0, s = 9 * 60, e = 23 * 60 + 59;
    while(n > 0 && s <= e){
        int i = 0;
        while(idx + i < times.size() && i < m){
            if (s >= times[idx + i]) ans = times[idx + i] - 1;
            if (s < times[idx + i]) {
                ans = s;
                break;
            }
            i++;
        }
        if (i < m) ans = s;
        idx += i;
        s += t;
        n--;
    }
    answer = trans(to_string(ans / 60)) + ":" + trans(to_string(ans % 60));
    return answer;
}