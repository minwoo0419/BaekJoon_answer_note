#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> maps;
vector<int> dist;
void dijkstra(){
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while(!pq.empty()){
        int n = pq.top().second;
        int l = pq.top().first;
        pq.pop();
        for (int i = 0 ; i < maps[n].size() ; i++){
            int nn = maps[n][i].first;
            int nl = maps[n][i].second;
            if (dist[nn] > l + nl){
                dist[nn] = l + nl;
                pq.push(make_pair(dist[nn], nn));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    maps.assign(N+1, vector<pair<int, int>>(0));
    dist.assign(N+1, 987654321);
    for (int i = 0 ; i < road.size() ; i++){
        maps[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        maps[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    dijkstra();
    for (int i = 1 ; i < dist.size() ; i++){
        if (dist[i] <= K)
            answer++;
    }
    return answer;
}