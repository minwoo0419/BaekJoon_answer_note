#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[1000][1000];
int main()
{
    int r, c, min = 1000, x, y;
    scanf("%d %d",&r,&c);
    getchar();
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            scanf("%d",&a[i][j]);
        }
        getchar();
    }
    if(r%2 == 1)
    {
        for(int i = 1 ; i <= r ; i++)
        {
            for(int j = 1 ; j < c ; j++)
            {
                if(i%2 == 1)
                    printf("R");
                else
                    printf("L");
            }
            if(i != r)
                printf("D");
        }
    }
    else if(c%2 == 1)
    {
        for(int i = 1 ; i <= c ; i++)
        {
            for(int j = 1 ; j < r ; j++)
            {
                if(i%2 == 1)
                    printf("D");
                else
                    printf("U");
            }
            if(i != c)
                printf("R");
        }
    }
    else
    {
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                if((i+j)%2 == 1)
                {
                    if(min >= a[i][j])
                    {
                        min = a[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        int newx;
        newx = x%2 ? x-1 : x;
        for(int i = 0 ; i < newx ; i++)
        {
            for(int j = 0 ; j < c-1 ; j++)
            {
                if(i%2 == 0)
                    printf("R");
                else
                    printf("L");
            }
            printf("D");
        }
        for(int i = 0 ; i < y ; i++)
        {
            if(i%2 == 0)
                printf("DR");
            else
                printf("UR");
        }
        for(int i = y ; i < c-1 ; i++)
        {
            if(i%2 == 0)
                printf("RD");
            else
                printf("RU");
        }
        if(x%2 == 0)
            newx = r - x - 2;
        else
            newx = r - x - 1;
        for(int i = 0 ; i < newx ; i++)
        {
            printf("D");
            for(int j = 1 ; j < c ; j++)
            {
                if(i%2 == 0)
                    printf("L");
                else
                    printf("R");
            }
        }
    }
    return 0;
}