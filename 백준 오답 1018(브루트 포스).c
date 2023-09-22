#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[51][51];
int chess(int x, int y) /*8*8로 잘라내서 오류갯수 세기*/
{
    int c = 0;
    for(int i = x ; i < x+8 ; i++)
    {
        for(int j = y ; j < y+8 ; j++)
        {
            if(a[x][y] == 'W') /*제일 처음 판이 흰색일 경우*/
            {
                if(((i-x)%2) == ((j-y)%2))
                {
                    if(a[i][j] == 'B')
                        c++;
                }
                else if(((i-x)%2) != ((j-y)%2))
                {
                    if(a[i][j] == 'W')
                        c++;
                }
            }
            else if(a[x][y] == 'B') /*제일 처음 판이 검은색일 경우*/
            {
                if(((i-x)%2) == ((j-y)%2))
                {
                    if(a[i][j] == 'W')
                        c++;
                }
                else if(((i-x)%2) != ((j-y)%2))
                {
                    if(a[i][j] == 'B')
                        c++;
                }
            }
        }
    }
    if(c > 32)
        c = 64 - c;    /*첫판이 잘못된 색일 경우*/
    return c;
}
int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",a[i]);
    }
    int cnt = n * m;
    for(int i = 0 ; i < n-7 ; i++)
    {
        for(int j = 0 ; j < m-7 ; j++)
        {
            if(cnt > chess(i,j))
                cnt = chess(i,j);
        }
    }
    printf("%d",cnt);
    return 0;
}