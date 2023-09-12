#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
int num[15];
int n;
int cnt = 0;
int abs(int a)
{
    return a>=0 ? a : -a;
}
void fuc(int a)
{
    if(a == n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            printf("%d",num[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = 0 ; i < n ; i++)
    {
        num[a] = i;
        int check = 1;
        for(int j = 0 ; j < a ; j++)
        {
            if(num[j] == i || a-j == abs(i - num[j]))
                check = 0;
        }
        if(check)
            fuc(a+1);
    }
    return ;
}
int main(){
    scanf("%d", &n);
    fuc(0);
    printf("%d", cnt);
    return 0;
}