#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int st;
    int scd;
    int cnt;
}Point;
Point a[1000000];
int compare(const void *a, const void *b)
{
    Point *x = (Point*) a;
    Point *y = (Point*) b;
    return x->st - y->st;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i].st);
        a[i].scd = i;
    }
    qsort(a,n,sizeof(Point),compare);
    int c = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i-1].st != a[i].st)
        {
            a[a[i].scd].cnt = i - c;
        }
        if(a[i-1].st == a[i].st)
        {
            a[a[i].scd].cnt = a[a[i-1].scd].cnt;
            c++;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",a[i].cnt);
    }
    return 0;
}