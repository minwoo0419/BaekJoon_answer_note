#include <stdio.h>
#include <stdlib.h>
/*int형 큐 IntQueue(헤더)*/
#ifndef ___IntQueue
#define ___IntQueue

/*큐를 구현하는 구조체*/
typedef struct
{
    int max;/*큐의 최대 용량*/
    int num;/*현재의 요소 개수*/
    int front;
    int rear;
    int *que;/*큐의 맨 앞 요소에 대한 포인터*/
}IntQueue;

/*큐 초기화*/
int Initialize(IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0;
    if((q->que = calloc(max,sizeof(int))) == NULL)
    {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

/*큐에 데이터를 인큐*/
int Enque(IntQueue *q, int x)
{
    if(q->num >= q->max)
        return -1;
    else
    {
        q->num++;
        q->que[q->rear++] = x;
        if(q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*큐에서 데이터를 디큐*/
int Deque(IntQueue *q, int *x)
{
    if(q->num <= 0)
        return -1;
    else
    {
        q->num--;
        *x = q->que[q->front++];
        if(q->front >= q->max)
            q->front = 0;
        return 0;
    }
}

/*큐에서 데이트를 피크*/
int Peek(const IntQueue *q, int *x)
{
    if(q->num <= 0)
        return -1;
    else
    {
        *x = q->que[q->front];
        return 0;
    }
}

/*모든 데이터 삭제*/
void Clear(IntQueue *q)
{
    q->num = q->fornt = q->rear = 0;
}
/* 큐의 최대 용량*/
int Capacity(const IntQueue *q)
{
    return q->max;
}

/* 큐에 저장된 데이터 개수*/
int Size(const IntQueue *q)
{
    return q->num;
}

/*큐가 비어있는가*/
int IsEmpty(const IntQueue *q)
{
    return q->num <= 0;
}

/*큐가 가득찼는가*/
int IsFull(const IntQueue *q)
{
    return q->num >= q->max;
}

/*큐에서 검색*/
int Search(const IntQueue *q, int x)
{
    int idx;
    for(int i = 0 ; i < q->num ; i++)
    {
        if(q->que[idx = (i+q->front)%q->max] == x)
            return idx;
    }
    return -1;
}

/*모든 데이터 출력*/
void Printf(const IntQueue *q)
{
    for(int i = 0 ; i < q->num ; i++)
    {
        printf("%d ", q->que[(i+q->front)%q->max]);
    }
    printf("\n");
}

/*큐 종료*/
void Terminate(IntQueue *q)
{
    if(q->que != NULL)
        free(q->que);
    q->max = q->num = q->front = q->rear = 0;
}
