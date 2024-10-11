#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int getCount(char c){
    return min(c - 'A', 'Z' - c + 1);
}

int solution(string name) {
    int answer = 0, minn = name.length();
    for (int i = 0 ; i < name.length() ; i++){
        answer += getCount(name[i]);
        int idx = i + 1;
        while(idx < name.length() && name[idx] == 'A') idx++;
        //현재 위치에서 다음 A가 아닌 문자 까지의 최소 거리 저장(오른쪽에서 왼쪽으로 갈 경우, 왼쪽에서 오른쪽으로 갈 경우)
        minn = min(minn, min(2 * i + ((int)name.length() - idx), i + 2 * ((int)name.length() - idx)));
    }
    answer += minn;
    return answer;
}