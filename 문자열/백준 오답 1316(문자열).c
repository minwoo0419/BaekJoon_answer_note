#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char a[])
{
    int t = strlen(a);
    int sum = 1;
    for(int i = 0 ; i < t ; i++)
    {
        int j;
        for(j = i+1 ; j < t ; j++)
        {
            if(a[i] != a[j])
                break;
        }
        for(; j < t ; j++)
        {
            if(a[i] == a[j])
            {
                sum = 0;
                break;
            }
        }
    }
    return sum;
}
int main()
{
    int n = 0, sum = 0;
    scanf("%d",&n);
    char a[101];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",a);
        sum = sum + check(a);   
    }
    printf("%d",sum);
    return 0;
}