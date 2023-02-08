#include <stdio.h>
#include <stdlib.h>
int a[10000] = {0, };
void fct(int n)
{
    int sum = n;
    while(n > 0)
    {
        sum = sum + (n % 10);
        if (sum >10000)
            break;
        n = (n/10);
    }
    a[sum-1] = 1;
}
int main()
{
    for(int i = 1 ; i <= 10000; i++)
    {
        fct(i);
    }
    for(int i = 0 ; i <= 10000 ; i++)
    {
        if(a[i] != 1)
            printf("%d\n",i+1);
    }
    return 0;
}