#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
int n, k;
int sqare(int sum, int x, int y)
{
    if(sum == 1)
        return 0;
    sum = sum / n;
    if(x >= sum*(n-k)/2 && x < sum*(n+k)/2 && y >= sum*(n-k)/2 && y < sum*(n+k)/2)
        return 1;
    return sqare(sum, x%sum, y%sum);
}
int main()
{
    int s, r1, r2, c1, c2;
    scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
    int sum = 1;
    for(int i = 0 ; i < s ; i++)
    {
        sum = sum * n;
    }
    for(int i = r1 ; i <= r2 ; i++)
    {
        for(int j = c1 ; j <= c2 ; j++)
        {
            printf("%d",sqare(sum,i,j));
        }
        printf("\n");
    }
    return 0;
}

