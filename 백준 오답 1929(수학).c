#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void num(int *a, int y)
{
    for(int i = 2 ; i <= y ; i++)
    {
        if(a[i] == 0)
            continue;
        else
        {
            for(int j = 2*i ; j <= y ; j = j + i)
            {
                a[j] = 0;
            }
        }
    }
}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int a[y+1];
    for(int i = 2 ; i <= y ; i++)
    {
        a[i] = 1;
    }
    num(a,y);
    for(int i = x ; i <= y ; i++)
    {
        if(a[i] == 1)
            printf("%d\n",i);
    }
    return 0;
}