#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
    int kg;
    int pr;
} Dmd;
Dmd a[300000];
Dmd q[300000];
int c[300000];
int push(int a, int b ,int n) /*최대 힙 push*/
{
    int i = n+1;
    while(a >= q[i/2].pr && i != 1)
    {
        q[i].pr = q[i/2].pr;
        q[i].kg = q[i/2].kg;
        i = i/2;
    }
    q[i].pr = a;
    q[i].kg = b;
    return 0;
}
int pop(int n) /*최대 힙 pop*/
{
    int parent, child, temp, first, temp2;
    first = q[1].pr;
    parent = 1;
    child = 2;
    temp = q[n+1].pr;
    temp2 = q[n+1].kg;
    while(child <= n)
    {
        if(child < n && q[child].pr < q[child+1].pr)
            child++;
        if(temp >= q[child].pr)
            break;
        q[parent].pr = q[child].pr;
        q[parent].kg = q[child].kg;
        parent = child;
        child = child * 2;
    }
    q[parent].pr = temp;
    q[parent].kg = temp2;
    return first;
}
int change(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int change2(const void *a, const void *b)
{
    Dmd *x = (Dmd*)a;
    Dmd *y = (Dmd*)b;
    return x->kg - y->kg;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %d", &a[i].kg, &a[i].pr);
        getchar();
    }
    for(int i = 0 ; i < k ; i++)
    {
        scanf("%d", &c[i]);
        getchar();
    }
    long long sum = 0;
    qsort(c, k, sizeof(int), change); /*가방무게 오름차순 정렬*/
    qsort(a, n, sizeof(Dmd), change2); /*보석무게 오름차순 정렬*/
    int j = 0, cnt = 0;
    for(int i = 0 ; i < k ; i++)
    {

        while(c[i] >= a[j].kg && j < n)
        {
            push(a[j].pr, a[j].kg, cnt++);
            j++;
        }            
        if(cnt > 0)
        {
            sum = sum + pop(--cnt);
        }
        else
            continue;
    }
    printf("%lld", sum);
    return 0;
}