#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
struct Pri{
    int gen;
    int play;
    int order;
};
bool cmp(Pri &a, Pri &b){
    if (a.gen == b.gen){
        if (a.play == b.play){
            return a.order < b.order;
        }
        return a.play > b.play;
    }
    return a.gen > b.gen;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> maps;
    map<string, vector<pair<int,int>>> indexs;
    vector<Pri> p;
    for (int i = 0 ; i < genres.size() ; i++){
        maps[genres[i]] += plays[i];
        indexs[genres[i]].push_back({plays[i],i});
    }
    for (auto m : indexs){
        int gen = maps[m.first];
        sort(m.second.rbegin(), m.second.rend());
        int s = min((int)m.second.size(), 2);
        for (int i = 0 ; i < s ; i++){
            p.push_back({gen, m.second[i].first, m.second[i].second});
        }
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0 ; i < p.size() ; i++){
        answer.push_back(p[i].order);
    }
    return answer;
}