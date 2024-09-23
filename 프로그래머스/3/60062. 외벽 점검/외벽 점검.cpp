#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    int length = weak.size();
    for (int i = 0 ; i < length ; i++){
        weak.push_back(weak[i] + n);
    }
    for (int i = 0 ; i < length ; i++){
        do{
            int cnt = 0;
            int position = weak[i] + dist[cnt];
            for (int j = i ; j < i + length ; j++){
                if (weak[j] > position){
                    cnt++;
                    if (cnt == dist.size())
                        break;
                    position = weak[j] + dist[cnt];
                }
            }
            answer = min(answer, cnt + 1);
        }while(next_permutation(dist.begin(), dist.end()));
    }
    if (answer == dist.size() + 1)
        answer = -1;
    return answer;
}