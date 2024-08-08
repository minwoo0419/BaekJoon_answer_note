#include <string>
#include <vector>
#include <set>
using namespace std;

int sum(int idx, int length, vector<int> elements){
    int sum = 0;
    for (int i = idx ; i < idx + length ; i++){
        int x = i % elements.size();
        sum += elements[x];
    }
    return sum;
}

int solution(vector<int> elements) {
    set<int> check;
    int answer = 0;
    int length = 1;
    while(length <= elements.size()){
        for (int i = 0 ; i < elements.size() ; i++){
            check.insert(sum(i, length, elements));
        }
        length++;
    }
    return check.size();
}