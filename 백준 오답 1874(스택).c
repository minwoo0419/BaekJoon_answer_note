#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[100000];
int num2[100000];
char stk[200001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&num[i]);
    }
    int j = -1, k = 1, cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        while(num[i] != num2[j] && cnt <= 2 * n)
        {
            num2[++j] = k++;
            stk[cnt++] = '+';
        }
        stk[cnt++] = '-';
        j--;
    }
    if(j == -1)
    {
        for(int i = 0 ; i < cnt ; i++)
        {
            printf("%c\n",stk[i]);
        }
    }
    else
        printf("NO");
    return 0;
}