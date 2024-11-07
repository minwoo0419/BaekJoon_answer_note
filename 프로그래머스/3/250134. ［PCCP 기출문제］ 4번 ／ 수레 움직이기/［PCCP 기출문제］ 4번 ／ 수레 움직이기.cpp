#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
bool visited[4][4][2] = {false};
vector<vector<int>> map;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool endr = false, endb = false;
int n = 0, m = 0;
bool isPoss(pair<int, int> rp, pair<int, int> bp, pair<int, int> rr, pair<int, int> br){
    //일반적인 가능여부 처리들
    if (rr.first < 0 || rr.first >= n || rr.second < 0 || rr.second >= m)
        return false;
    if (br.first < 0 || br.first >= n || br.second < 0 || br.second >= m)
        return false;
    if (map[rr.first][rr.second] == 5 || map[br.first][br.second] == 5)
        return false;
    //스위칭되었을 경우
    if ((rp.first == br.first && rp.second == br.second) && (bp.first == rr.first && bp.second == rr.second))
        return false;
    //이동할 위치가 겹칠 경우
    if (rr == br){
        return false;
    }
    //도착지점이 아닌 곳들 중 이미 방문한 곳일 경우
    if ((!endr && visited[rr.first][rr.second][0]) || (!endb && visited[br.first][br.second][1]))
        return false;
    return true;
}
int backtracking(pair<int, int> rp, pair<int, int> bp, int result){
    if (endr && endb)
        return result;
    int answer = 987654321;
    
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            //도착했으면 안움직이기
            pair<int, int> rr = endr ? rp : make_pair(rp.first + dx[i], rp.second + dy[i]);
            pair<int, int> br = endb ? bp : make_pair(bp.first + dx[j], bp.second + dy[j]);
            if (!isPoss(rp, bp, rr, br))
                continue;
            visited[rr.first][rr.second][0] = true;
            visited[br.first][br.second][1] = true;
            if (map[rr.first][rr.second] == 3)
                endr = true;
            if (map[br.first][br.second] == 4)
                endb = true;
            answer = min(answer, backtracking(rr, br, result+1));
            visited[rr.first][rr.second][0] = false;
            visited[br.first][br.second][1] = false;
            endr = false;
            endb = false;
            
        }
    }
    return answer;
}
int solution(vector<vector<int>> maze) {
    map = maze;
    int answer = 0;
    n = map.size();
    m = map[0].size();
    pair<int, int> r, b;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (map[i][j] == 1)
                r = make_pair(i, j);
            else if (map[i][j] == 2)
                b = make_pair(i, j);
        }
    }
    visited[r.first][r.second][0] = true;
    visited[b.first][b.second][1] = true;
    answer = backtracking(r, b, 0);
    return answer == 987654321 ? 0 : answer;
}