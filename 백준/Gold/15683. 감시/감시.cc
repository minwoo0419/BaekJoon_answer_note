#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
using namespace std;
struct INFO {
    int idx, cnt;
    vector< vector<int> > map;
    INFO(int _idx, int _cnt, vector< vector<int> > _map) : idx(_idx), cnt(_cnt), map(_map) {}
};
int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, -1, 0, 1};
int n, m;
int draw_view(vector< vector <int> > &map, int i, int j, int idx){
    int cnt = 0;
    while(i + nx[idx] >= 0 && i + nx[idx] < n && j + ny[idx] >= 0 && j + ny[idx] < m){
        i += nx[idx];
        j += ny[idx];
        if (map[i][j] == 6)
            break;
        else if (map[i][j] == 0){
            map[i][j] = 7;
            cnt++;
        }
    }
    return cnt;
}
int count_view(vector< vector<int> > &map, tuple<int, int, int> cctv, int idx){
    int i = get<0>(cctv);
    int j = get<1>(cctv);
    int num = get<2>(cctv);
    int cnt = draw_view(map, i, j, idx);
    if (num == 2 || num == 4 || num == 5){
        int a = (idx < 2) ? idx + 2 : idx - 2;
        cnt += draw_view(map, i, j, a);
    }
    if (num == 3 || num == 4 || num == 5){
        int a = (idx < 3) ? idx + 1 : idx - 3;
        cnt += draw_view(map, i, j, a);
    }
    if (num == 5){
        int a = (idx < 1) ? idx + 3 : idx - 1;
        cnt += draw_view(map, i, j, a);
    }
    return cnt;
}
int simulation(INFO start, vector< tuple<int, int, int> > cctvs){
    int answer = 0;
    queue<INFO> q;
    q.push(start);
    while(!q.empty()){
        INFO temp = q.front();
        q.pop();
        int idx = temp.idx;
        int cnt = temp.cnt;
        if (idx == cctvs.size()){
            answer = max(answer, cnt);
            continue;
        }
        tuple<int, int, int> cctv = cctvs[idx];
        for (int i = 0 ; i < 4 ; i++){
            vector< vector<int> > map = temp.map;
            int temp_cnt = cnt + count_view(map, cctv, i);
            INFO new_q(idx+1, temp_cnt, map);
            q.push(new_q);
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int zero_cnt = 0;
    vector < vector <int> > map;
    vector < tuple<int, int, int> > cctv;
    for (int i = 0 ; i < n ; i++){
        map.push_back(vector<int>());
        for (int j = 0 ; j < m ; j++){
            int n;
            cin >> n;
            map[i].push_back(n);
            if (n > 0 && n < 6)
                cctv.push_back(make_tuple(i, j, n));
            else if (n == 0)
                zero_cnt++;
        }
    }
    INFO start(0, 0, map);
    cout << zero_cnt - simulation(start, cctv);
    return 0;
}
