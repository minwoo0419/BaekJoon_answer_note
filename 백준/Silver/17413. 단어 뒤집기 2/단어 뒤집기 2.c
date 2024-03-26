#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[100020];
char b[100020];
int main()
{
    scanf("%[^\n]s",a);
    getchar();
    int j = 0;
    int k = strlen(a);
    while(j < k)
    {
        int cnt = 0;
        while(a[j] != ' ' && a[j] != '\0' && a[j] != '<')
        {
            b[cnt++] = a[j++];
        }
        while(cnt > 0)
        {
            printf("%c", b[--cnt]);
        }
        if(a[j] == '<')
        {
            while(a[j] != '>')
            {
                printf("%c",a[j++]);
            }
            printf("%c", a[j++]);
        }
        else if(a[j] == '\0')
            break;
        else
        {
            printf(" ");
            j++;
        }
    }
    return 0;
}