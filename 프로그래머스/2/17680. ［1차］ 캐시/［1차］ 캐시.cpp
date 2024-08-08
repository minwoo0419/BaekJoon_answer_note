#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    for (int i = 0 ; i < cities.size() ; i++){
        for (int j = 0 ; j < cities[i].length() ; j++){
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] = tolower(cities[i][j]);
        }
        int idx = -1;
        for (int j = 0 ; j < cache.size() ; j++){
            if (cache[j].compare(cities[i]) == 0){
                idx = j;
                break;
            }
        }
        if (idx != -1){
            cache.erase(cache.begin() + idx);
            answer++;
        } else {
            answer += 5;
        }
        cache.push_back(cities[i]);
        if (cache.size() > cacheSize){
            cache.pop_front();
        }
    }
    return answer;
}