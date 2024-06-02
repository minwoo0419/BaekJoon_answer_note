#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
using namespace std;

int main(int argc, char** argv)
{
    double tot;
    double stu;
    for (int i = 0 ; i < 20 ; i++){
        string s, sub;
        getline(cin, s);
        vector<string> split;
        istringstream stream(s);
        while(getline(stream, sub, ' ')){
            split.push_back(sub);
        }
        int hack = split[1][0] - '0';
        double temp = 0;
        if (split[2] == "P")
            continue;
        for (int i = 0 ; i < split[2].length() ; i++){
            if(split[2][i] >= 'A' && split[2][i] <= 'F'){
                int t = (4 - split[2][i] + 'A') > 0 ? (4 - split[2][i] + 'A') : 0;
                temp += t;
            } else {
                if (split[2][i] == '+')
                    temp += 0.5;
            }
        }
        tot += hack * temp;
        stu += hack;
    }
    cout << tot / stu;
    return 0;
}