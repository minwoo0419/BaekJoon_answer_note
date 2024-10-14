#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<vector<vector<int> > > visits;
vector<vector<int> > maps;

int n;
char con[4] = {'D', 'S', 'L', 'R'};

string bfs(int start, int end){
    vector<int> visits(10000, 0);
    queue<pair<int, string> > q;
    q.push(make_pair(start, ""));
    visits[start] = 1;
    while (!q.empty()){
        int num = q.front().first;
        string path = q.front().second;
        q.pop();
        if (num == end) return path;
        for (int i = 0 ; i < 4 ; i++){
            int nNum = num;
            if (con[i] == 'D'){
                nNum = nNum * 2 % 10000;
            } else if (con[i] == 'S'){
                nNum = (nNum == 0) ? 9999 : nNum - 1;
            } else if (con[i] == 'L'){
                nNum = (nNum % 1000) * 10 + (nNum / 1000);
            } else {
                nNum = (nNum % 10) * 1000 + nNum / 10;
            }
            if (visits[nNum]) continue;
            visits[nNum] = 1;
            q.push(make_pair(nNum, path + con[i]));
        }
    }
    return "";
}
int main() {
    cin >> n;
    for (int k = 0 ; k < n ; k++){
        int start, end;
        cin >> start >> end;
        cout << bfs(start, end) << "\n";
    }
    return 0;
}