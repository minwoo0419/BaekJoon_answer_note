#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string s, char dlim){
    vector<string> ans;
    
    stringstream ss;
    string buffer;
    ss.str(s);
    
    while(getline(ss, buffer, dlim)){
        ans.push_back(buffer);
    }
    return ans;
}

string solution(string s) {
    vector<int> num;
    string answer = "";
    vector<string> v = split(s, ' ');
    for (int i = 0 ; i < v.size() ; i++){
        num.push_back(stoi(v[i]));
    }
    sort(num.begin(), num.end());
    answer += (to_string(num[0]) + " " + to_string(num.back()));
    return answer;
}