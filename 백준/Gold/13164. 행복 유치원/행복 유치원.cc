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
    int n, m;
    cin >> n >> m;
    vector<int> minus;
    vector <int> height;
    for (int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        height.push_back(a);
    }
    for (int i = 0 ; i < n-1 ; i++){
        minus.push_back(height[i+1] - height[i]);
    }
    sort(minus.begin(), minus.end());
    int sum = 0;
    for (int i = 0 ; i < minus.size() - m + 1 ; i++){
        sum += minus[i];
    }
    cout << sum;
    return 0;
}
