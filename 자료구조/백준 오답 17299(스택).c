#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1000000];
int b[1000000];
int c[1000000];
typedef struct{
    int ptr;
    int stk[1000000];
}Stack;
int start(Stack *s)
{
    s->ptr = -1;
    return 0;
}
int push(Stack *s, int n)
{
    s->ptr++;
    s->stk[s->ptr] = n;
    return 0;
}
int pop(Stack *s)
{
    s->ptr--;
    return 0;
}
int top(Stack *s)
{
    return s->stk[s->ptr];
}
int empty(Stack *s)
{
    if(s->ptr == -1)
        return 1;
    else
        return -1;
}
int main()
{
    int n;
    Stack s, t;
    scanf("%d",&n);
    getchar();
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
        getchar();
        if(c[a[i]] == 0)
            cnt++;
        c[a[i]]++;
    }
    start(&s);
    start(&t);
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        while(empty(&s) == -1 && top(&s) <= c[a[i]])
        {
            pop(&s);
            pop(&t);
        }
        if(empty(&s) == 1)
            b[i] = -1;
        else
            b[i] = top(&t);
        push(&s, c[a[i]]);
        push(&t, a[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}