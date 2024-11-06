#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    map<pair<int, pair<int, int>>, set<int>> maps;
    for (int i = 0 ; i < routes.size() ; i++){
        int t = 0;
        for (int j = 1 ; j < routes[i].size() ; j++){
            int sx = points[routes[i][j-1]-1][0];
            int sy = points[routes[i][j-1]-1][1];
            int ex = points[routes[i][j]-1][0];
            int ey = points[routes[i][j]-1][1];
            while(sx != ex) {
                maps[{t, {sx, sy}}].insert(i);
                sx = sx < ex ? sx + 1 : sx - 1;
                t++;
            }
            while(sy != ey) {
                maps[{t, {sx, sy}}].insert(i);
                sy = sy < ey ? sy + 1 : sy - 1;
                t++;
            }
            maps[{t, {sx, sy}}].insert(i);
        }
    }
    for (auto m : maps){
        if (m.second.size() > 1) answer++;
    }
    return answer;
}