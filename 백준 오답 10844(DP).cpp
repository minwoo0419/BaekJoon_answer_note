#include <iostream>

using namespace std;
int x[101][11];
int dp(int a)
{
    int sum = 0;
    for (int i = 1 ; i <= a ; i++)
    {
        if (i == 1)
        {
            for (int j = 1 ; j <= 9 ; j++)
                x[i][j] = 1;
        }
        else
        {
            for(int j = 0 ; j <= 9; j++)
            {
                x[i][j] = (x[i - 1][j - 1] + x[i- 1][j + 1]) % 1000000000;
            }
        }
        for (int j = 0 ; j <= 9 ; j++)
            sum = (sum + x[a][j]) % 1000000000;
    }
    return (sum);
}
int main()
{
    int a;
    cin >> a;
    cout << dp(a);
    return (0);
}