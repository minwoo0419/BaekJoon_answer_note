#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<vector<pair<string, pair<int, int>>>> table(51, vector<pair<string, pair<int, int>>>(51));

vector<string> split(string command) {
    vector<string> temp;
    stringstream ss(command);
    string s;
    while (getline(ss, s, ' ')) {
        temp.push_back(s);
    }
    return temp;
}

int convert(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        n *= 10;
        n += s[i] - '0';
    }
    return n;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            table[i][j] = make_pair("EMPTY", make_pair(i, j));
        }
    }

    for (const string &command : commands) {
        vector<string> temp = split(command);

        if (temp[0] == "UPDATE") {
            if (temp.size() == 3) {
                // UPDATE value1 value2
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (table[i][j].first == temp[1]) {
                            table[i][j].first = temp[2];
                        }
                    }
                }
            } else {
                // UPDATE r c value
                pair<int, int> coord = table[convert(temp[1])][convert(temp[2])].second;
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (table[i][j].second == coord) {
                            table[i][j].first = temp[3];
                        }
                    }
                }
            }
        } else if (temp[0] == "MERGE") {
            int r1 = convert(temp[1]), c1 = convert(temp[2]);
            int r2 = convert(temp[3]), c2 = convert(temp[4]);
            pair<int, int> p1 = table[r1][c1].second;
            pair<int, int> p2 = table[r2][c2].second;

            if (p1 != p2) {
                string value = (table[r1][c1].first == "EMPTY") ? table[r2][c2].first : table[r1][c1].first;
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (table[i][j].second == p1 || table[i][j].second == p2) {
                            table[i][j] = make_pair(value, p1);
                        }
                    }
                }
            }
        } else if (temp[0] == "UNMERGE") {
            int r = convert(temp[1]), c = convert(temp[2]);
            pair<int, int> p = table[r][c].second;
            string value = table[r][c].first;

            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (table[i][j].second == p) {
                        table[i][j] = make_pair("EMPTY", make_pair(i, j));
                    }
                }
            }

            table[r][c] = make_pair(value, make_pair(r, c));
        } else if (temp[0] == "PRINT") {
            int r = convert(temp[1]), c = convert(temp[2]);
            answer.push_back(table[r][c].first);
        }
    }

    return answer;
}

