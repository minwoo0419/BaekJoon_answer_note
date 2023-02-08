#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
typedef struct NODE{
    struct NODE *next;
    int data;
}NODE;
void appendfirst(NODE *list, int data)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->next = list->next;
    newnode->data = data;
    list->next = newnode;
}
void append(NODE *list, int data)
{
    NODE *newnode = malloc(sizeof(NODE));
    if(list->next == NULL)
    {
        newnode->next = NULL;
        newnode->data = data;
        list->next = newnode;
    }
    else
    {
        NODE *ptr = list;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->next = NULL;
        newnode->data = data;
        ptr->next = newnode;
    }
}
void insert(NODE *list, int data, int x)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->next = NULL;
    newnode->data = data;
    NODE *ptr;
    if(x == 0)
    {
        newnode->next = list->next;
        list->next = newnode;
    }
    else
    {
        int i = 0;
        ptr = list;
        while(i < x)
        {
            if(i == x-1)
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
            }
            ptr = ptr->next;
            i++;
        }
    }
}
void print(NODE *list)
{
    NODE *cur = list->next;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void compare(NODE *list)
{
    NODE *ptr = list->next;
    for(int j = 0 ; j < 8 ; j++)
    {
        if(ptr == NULL)
            break;
        for(int k = 0 ; k < 7-j ; k++)
        {
            if(ptr->data < ptr->next->data)
            {
                int x = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = x;
            }
            ptr = ptr->next;
        }
        ptr = list->next;
    }
}
int main()
{
    NODE *list = malloc(sizeof(NODE));
    list->next = NULL;
    for(int i = 1 ; i <= 7 ; i++)
    {
        if(i%2 == 0)
        {
            appendfirst(list, i);
        }
        else
        {
            append(list, i);
        }
    }
    insert(list, 10, 4);
    print(list);
    compare(list);
    print(list);
    return 0;
}