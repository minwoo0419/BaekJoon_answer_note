#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector < pair <int, int> > task;
    int maxi = 0;
    for (int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        task.push_back(make_pair(a, b));
        if (maxi < a)
            maxi = a;
    }
    int cnt = 0;
    for (int i = maxi ; i > 0 ; i--){
        int max_point = 0;
        int idx = -1;
        for (int j = 0 ; j < task.size() ; j++){
            int time = task[j].first;
            int point = task[j].second;
            if (i <= time){
                if (max_point < point){
                    max_point = point;
                    idx = j;
                } else if (max_point == point){
                    if (task[idx].first < time)
                        idx = j;
                }
            }
        }
        if (idx >= 0)
        {
            cnt += task[idx].second;
            task.erase(task.begin() + idx);
        }
    }
    cout << cnt;
    return 0;
}
