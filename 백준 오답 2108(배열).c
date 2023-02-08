#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int a[500001];
int b[8001];
int main()
{
    int n;
    double sum, av;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
        sum = sum + a[i];
        b[a[i]+4000]++;
    }
    av = sum / n;
    if(av > -0.5 && av < 0)
        av = 0;
    qsort(a, n, sizeof(int), compare);
    int chk = 0, max = 0, cnt = 0, cnt2 = 0, p;
    for(int i = 0 ; i < 8001 ; i++)
    {
        if(max < b[i])
        {
            max = b[i];
            cnt = 0;
            p = i - 4000;
        }
        else if(max == b[i])
        {
            cnt++;
            if(cnt == 1)
            {
                p = i - 4000;
            }
        }
    }
    printf("%.f\n%d\n%d\n%d", round(av), a[n/2], p, a[n-1] - a[0]);
    return 0;
}