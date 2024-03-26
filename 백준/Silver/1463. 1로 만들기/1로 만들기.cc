#include <iostream>

using namespace std;
int x[1000001];

int main()
{
    int a;
    cin >> a;
    for (int i = 2 ; i <= a ; i++)
    {
        x[i] = x[i- 1] + 1;
        if (i % 2 == 0)
            x[i] = (x[i / 2] + 1 < x[i] ? x[i / 2] + 1 : x[i]);
        if (i % 3 == 0)
            x[i] = (x[i / 3] + 1 < x[i] ? x[i / 3] + 1 : x[i]);
    }
    cout << x[a];
    return (0);
}