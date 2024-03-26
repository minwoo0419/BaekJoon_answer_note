#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cnt = 0;
void hanoi(int num, int str, int end)
{
    int mid = 6 - str - end;
    if(num > 0)
    {
        cnt++;
        hanoi(num-1, str, mid);
        printf("%d %d\n",str, end);
        hanoi(num-1, mid, end);
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    printf("%d\n", (int)pow(2,num)-1);
    hanoi(num, 1, 3);
    return 0;
}