#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> nodes(1000001);

vector<int> ins(1000001);
vector<int> outs(1000001);
int donut = 0, stick = 0, eight = 0;
void bfs(int a){
    queue<int> q;
    q.push(a);
    bool enter = false;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (now == a && enter){
            donut++;
            return ;
        }
        if (nodes[now].size() >= 2){
            eight++;
            return ;
        }
        for (int i = 0 ; i < nodes[now].size() ; i++){
            q.push(nodes[now][i]);
        }
        enter = true;
    }
    stick++;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for (int i = 0 ; i < edges.size() ; i++){
        nodes[edges[i][0]].push_back(edges[i][1]);
        outs[edges[i][0]]++;
        ins[edges[i][1]]++;
    }
    int root = 0;
    for (int i = 1 ; i <= 1000000 ; i++){
        if (outs[i] >= 2 && ins[i] == 0)
            root = i;
    }
    for (int i = 0 ; i < nodes[root].size() ; i++){
        bfs(nodes[root][i]);
    }
    answer.push_back(root);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}