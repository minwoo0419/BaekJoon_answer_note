#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct INFO {
    int ri, rj, bi, bj, cnt;
    INFO(int _ri, int _rj, int _bi, int _bj, int _cnt) : ri(_ri), rj(_rj), bi(_bi), bj(_bj), cnt(_cnt) {}
};
int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};
int n, m, answer = -1;
vector<string> map;
int move(int &i, int &j, int idx){
    int count = 0;
    while(map[i + nx[idx]][j + ny[idx]] != '#' && map[i][j] != 'O'){
        i += nx[idx];
        j += ny[idx];
        count++;
    }
    return count;
}
void simulation(INFO start){
    int visited[10][10][10][10] = {0,};
    queue<INFO> q;
    visited[start.ri][start.rj][start.bi][start.bj] = 1;
    q.push(start);
    while(!q.empty()){
        INFO temp = q.front();
        q.pop();
        if (temp.cnt > 10)
            break;
        if (map[temp.bi][temp.bj] == 'O')
            continue;
        if (map[temp.ri][temp.rj] == 'O'){
            answer = temp.cnt;
            break;
        }
        for(int i = 0 ; i < 4 ; i++) {
            int new_ri = temp.ri;
            int new_rj = temp.rj;
            int new_bi = temp.bi;
            int new_bj = temp.bj;
            int rcnt = move(new_ri, new_rj, i);
            int bcnt = move(new_bi, new_bj, i);
            if(new_ri == new_bi && new_rj == new_bj && map[new_ri][new_rj] != 'O'){
                if(rcnt > bcnt) {
                    new_ri -= nx[i];
                    new_rj -= ny[i];
                } else {
                    new_bi -= nx[i];
                    new_bj -= ny[i];
                }
            }
            if (visited[new_ri][new_rj][new_bi][new_bj] == 0){
                visited[new_ri][new_rj][new_bi][new_bj] = 1;
                INFO new_q(new_ri, new_rj, new_bi, new_bj, temp.cnt + 1);
                q.push(new_q);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ri, rj;
    int bi, bj;
    cin >> n >> m;
    INFO start(0, 0, 0, 0, 0);
    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        if (s.find('R') != string::npos){
            start.ri = i;
            start.rj = s.find('R');
        }
        if (s.find('B') != string::npos){
            start.bi = i;
            start.bj = s.find('B');
        }
        map.push_back(s);
    }
    simulation(start);
    cout << answer;
    return 0;
}
