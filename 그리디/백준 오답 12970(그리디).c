#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[51];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i = 0;
    while(i < n)
    {
        a[i] = 'B';
        i++;
    }
    if(k > ((n/2)*(n-n/2)))
        printf("-1");
    else
    {
        int cnt = 0, num;
        while(1)
        {
            num = 0;
            a[cnt++] = 'A';
            int t = 0;
            while(t < n)
            {
                if(a[t] == 'A')
                {
                    int x = t+1;
                    while(x < n)
                    {
                        if(a[x] == 'B')
                            num++;
                        x++;
                    }
                }
                t++;
            }
            if(num == k)
                break;
            else if(num > k)
                a[cnt-1] = 'B';
        }
        printf("%s",a);
    }
    return 0;
}