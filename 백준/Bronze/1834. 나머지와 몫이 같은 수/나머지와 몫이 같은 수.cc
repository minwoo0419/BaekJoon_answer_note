#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define INF (~0LLU >> 2)
vector<vector<int> > arr;
int n, m;
int main()
{  
    cin >> n;
    long long answer = 0;
    for (long long i = 1 ; i < n ; i++){
        answer += (i + i * n);
    }
    cout << answer;
    return (0);
}