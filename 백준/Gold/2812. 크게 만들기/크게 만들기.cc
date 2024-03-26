#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
vector <int> num;
vector <int> num2;
int main()
{
    int n, k, cnt = 0;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++)
    {
        char a;
        cin >> a;
        num.push_back(a - '0');
    }
    for (int i = 0 ; i < num.size() ; i++)
    {
        while (cnt < k && !num2.empty() && num2.back() < num[i])
        {
                num2.pop_back();
                cnt++;
        }
        num2.push_back(num[i]);
    }
    for (int i = 0 ; i < num2.size() - (k - cnt) ; i++)
        cout << num2[i];
    return 0;
}