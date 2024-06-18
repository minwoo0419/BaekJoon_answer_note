#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(vector<int> &v1, vector<int> &v2, int sum){
    for (int i = 0 ; i < v1.size() ; i++){
        for (int j = 0 ; j < v2.size() ; j++){
            if (v1[i] + v2[j] == sum)
            {
                v1[i] = 0;
                v2[j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    vector<int> hands, past;
    for (int i = 0 ; i < cards.size() / 3 ; i++){
        hands.push_back(cards[i]);
    }
    int idx = hands.size();
    int sum = cards.size() + 1;
    while (idx < cards.size()){
        for (int i = 0 ; i < 2 ; i++){
            past.push_back(cards[idx++]);
        }
        if (hands.size() > 1 && check(hands, hands, sum)){
            answer++;
        }else if (hands.size() > 0 && coin > 0 && check(hands, past, sum)){
            answer++;
            coin -= 1;
        } else if (coin > 1 && check(past, past, sum)){
            answer++;
            coin -= 2;
        } else
            break;
    }
    return answer;
}