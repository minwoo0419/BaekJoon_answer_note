#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    map<string, string> maps;
    map<string, int> moneys;
    vector<int> answer;
    for (int i = 0 ; i < enroll.size() ; i++){
        maps[enroll[i]] = referral[i];
    }
    for (int i = 0 ; i < seller.size() ; i++){
        int a = amount[i] * 100;
        string man = seller[i];
        while(a > 0 && man != "-"){
            moneys[man] += a - (a / 10);
            a /= 10;
            if (maps.find(man) == maps.end()) break;
            man = maps[man];
        }
    }
    for (int i = 0 ; i < enroll.size() ; i++){
        answer.push_back(moneys[enroll[i]]);
    }
    return answer;
}