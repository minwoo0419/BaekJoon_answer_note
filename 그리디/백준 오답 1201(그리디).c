#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[500];
int b[500][500];
void rev(int *a)
{
    int n = 0;
    while(a[n] != 0)
    {
        n++;
    }
    for(int i = 0 ; i < n/2 ; i++)
    {
        if(a[i] != 0)
        {
            int tmp = a[i];
            a[i] = a[n-i-1];
            a[n-i-1] = tmp;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int n, m, k;
    scanf("%d %d %d",&n, &m, &k);
    int cnt = 0;
    if(m+k-1 > n || n > m*k)
    {
        printf("-1");
        return 0;
    }
    else
    {
        int t = 0;
        for(; t < k ; t++)
        {
            b[0][t] = t+1;
        }
        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 1 ; j < m ; j++)
            {
                if(t == n)
                    break;
                else
                {
                    b[j][i-1] = ++t;
                }
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            rev(b[i]);
        }
        return 0;
    }
}