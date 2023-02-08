#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(type, x, y) do {type t = x ; x = y ; y = t;}while(0)
typedef struct{
    int x;
    int y;
}Point;
int compare(const void *a, const void *b)
{
    Point *x;
    Point *y;
    x = (Point*) a;
    y = (Point*) b;
    if(x->x == y->x)
        return x->y - y->y;
    return x->x - y->x;
}
int main()
{
    int n = 0;
    scanf("%d",&n);
    Point a[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    qsort(a, n, sizeof(Point), compare);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d %d\n",a[i].x, a[i].y);
    }
    return 0;
}