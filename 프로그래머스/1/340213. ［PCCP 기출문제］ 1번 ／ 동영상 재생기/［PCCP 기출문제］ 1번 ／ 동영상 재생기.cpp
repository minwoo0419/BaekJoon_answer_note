#include <string>
#include <vector>
#include <sstream>
using namespace std;
int get_time(string s){
    int ans = 0;
    string buf;
    stringstream ss;
    ss.str(s);
    while(getline(ss, buf, ':')){
        if (buf.empty()) continue;
        ans *= 60;
        ans += stoi(buf);
    }
    return ans;
}
string make_time(int n){
    return n < 10 ? "0" + to_string(n) : to_string(n);
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int start = get_time(pos), len = get_time(video_len), op_s = get_time(op_start), op_e = get_time(op_end);
    for (auto c : commands){
        if (start >= op_s && start <= op_e) start = op_e;
        if (c == "next") start = min(len, start + 10);
        else if (c == "prev") start = max(0, start - 10);
    }
    if (start >= op_s && start <= op_e) start = op_e;
    return make_time(start / 60) + ":" + make_time(start % 60);
}