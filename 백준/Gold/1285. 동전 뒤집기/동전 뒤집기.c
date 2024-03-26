#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[21][21];
char b[21][21];
int min(int a, int b)
{
    if(a <= b)
        return a;
    else
        return b;
}
int change(char x)
{
    if(x == 'H')
        return 'T';
    else
        return 'H';
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s", a[i]);
        getchar();
    }
    int chk = n * n;
    for(int i = 0 ; i < (1<<n) ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < n ; j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                b[j][k] = a[j][k];
            }
        }
        for(int j = 0 ; j < n ; j++)
        {
            int cnt = 0;
            for(int k = 0 ; k < n ; k++)
            {
                if((1<<k) & i)
                    b[j][k] = change(b[j][k]);
                if(b[j][k] == 'T')
                    cnt++;
            }
            sum = sum + min(cnt, n - cnt);
        }
        chk = min(sum, chk);
    }
    printf("%d", chk);
    return 0;
}