#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i = 0 ; i < n ; i++)
    {
        char a[1002];
        fgets(a, 1000, stdin);
        int j = 0;
        int k = strlen(a);
        a[k] = ' ';
        while(j < k)
        {
            int cnt = 0;
            char b[21];
            while(a[j] != ' ' && a[j] != '\n')
            {
                b[cnt++] = a[j];
                j++;
            }
            while(cnt > 0)
            {
                printf("%c", b[--cnt]);
            }
            printf(" ");
            j++;
        }
        printf("\n");
    }
    return 0;
}