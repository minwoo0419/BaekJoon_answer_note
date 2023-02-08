#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[10002], b[10002], c[10003]; /*전역변수로 선언 시 배열 초기화*/
void transe(char w[])
{
    int x = strlen(w);
    for(int i = 0 ; i < x/2 ; i++)
    {
        char tmp = w[i];
        w[i] = w[x-i-1];
        w[x-i-1] = tmp;
    }
}
int main()
{
    scanf("%s %s",a,b);
    int x , y;
    x = strlen(a);
    y = strlen(b);
    if(x < y)
        x = y;
    transe(a);
    transe(b);
    int u = 0;
    for(int i = 0 ; i <= x ; i++)
    {
        int p = 0;
        if(a[i] == '\0' && b[i] == '\0')
            p = 0;
        else if(a[i] == '\0')
            p = b[i]-48;
        else if(b[i] == '\0')
            p = a[i]-48;
        else
            p = (a[i]-48) + (b[i] - 48);
        if(p+u >= 10)
        {
            c[i] = ((p+u)%10)+48;
            u = 1;
        }
        else
        {
            c[i] = p+48+u;
            u = 0;
        }
    }
    if(c[x] == '0')
        c[x] = '\0';
    transe(c);
    printf("%s",c);
    return 0;
}