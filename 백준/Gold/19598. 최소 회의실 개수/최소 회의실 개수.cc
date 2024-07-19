#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
vector< pair<int, int> > classes;
priority_queue<int, vector<int>, greater<int> > endTime;
int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        int s, e;
        cin >> s >> e;
        classes.push_back(make_pair(s, e));
    }
    sort(classes.begin(), classes.end());
    endTime.push(classes[0].second);
    for (int i = 1 ; i < n ; i++){
        if (!endTime.empty() && endTime.top() <= classes[i].first)
            endTime.pop();
        endTime.push(classes[i].second);
    }
    cout << endTime.size();
    return 0;
}
