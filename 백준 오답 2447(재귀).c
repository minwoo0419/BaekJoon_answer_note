#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[2188][2188];
void pat(int x, int y, int n) /*n은 패턴의 크기*/
{
    if(n == 1)
        a[x][y] = '*';
    else /*n/3의 패턴들 먼저 출력*/
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(i == 1 && j == 1)
                    a[x+i][y+j] = ' ';
                pat(x+i*n/3, y+j*n/3,n/3);
            }
        }

    }
    for(int i = n/3 ; i < n*2/3 ; i++) /*n의 패턴 출력*/
    {
        for(int j = n/3 ; j < n*2/3 ; j++)
        {
            a[x+i][y+j] = ' ';
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    pat(0, 0, n);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}