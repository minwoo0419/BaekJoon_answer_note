#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[100000];
int a2[100000];
int b[100000];
int cnt = 0;
void change(int *s, int x, int n)
{
    for(int i = x-1 ; i <= x+1 ; i++)
    {
        if(i >= 0 && i < n)
        {
            s[i] = 1 - s[i];
        }
    }
}
int check(int *s, int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i-1] != b[i-1])
        {
            change(s, i, n);
            cnt++;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] != b[i])
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%1d",&a[i]);
        a2[i] = a[i];
    }
    getchar();
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%1d",&b[i]);
    }
    if(check(a, n) == 1)
    {
        printf("%d",cnt);
        return 0;
    }
    cnt = 1;
    change(a2, 0, n);
    if(check(a2, n) == 1)
    {
        printf("%d",cnt);
        return 0;
    }
    printf("-1");
    return 0;
}