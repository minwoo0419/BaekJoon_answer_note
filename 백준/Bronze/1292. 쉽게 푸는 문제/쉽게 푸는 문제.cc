#include <iostream>
#include <vector>
using namespace std;
#define INF (~0LLU >> 2)
vector<vector<int> > arr, ans;

int n, m;
vector<int> v;
int main()
{
    cin >> n >> m;
    int flag = 1, plus = 0;
    while(v.size() < m){
        v.push_back(flag);
        plus++;
        if (plus == flag){
            flag++;
            plus = 0;
        }

    }
    int sum = 0;
    for (int i = n - 1 ; i < m ; i++){
        sum += v[i];
    }
    cout << sum;
    return (0);
}