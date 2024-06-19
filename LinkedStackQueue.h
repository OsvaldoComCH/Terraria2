#ifndef LINKED_STACK_QUEUE
#define LINKED_STACK_QUEUE
#include <stdlib.h>

typedef struct SQNode
{
    int Value;
    struct SQNode * Next;
} SQNode;

typedef struct LStack
{
    SQNode * Head;
} LStack;

typedef struct LQueue
{
    SQNode * Head, * Tail;
} LQueue;

void LStackCreate(LStack * Stack)
{
    Stack->Head = NULL;
}

void LStackPush(LStack * Stack, int Value)
{
    SQNode * S = (SQNode *) malloc(sizeof(SQNode));
    S->Next = Stack->Head;
    S->Value = Value;
    Stack->Head = S;
}

int LStackPop(LStack * Stack)
{
    SQNode * S = Stack->Head;
    int Value = S->Value;
    Stack->Head = Stack->Head->Next;
    free(S);
    return Value;
}

void LStackDelete(LStack * Stack)
{
    while(Stack->Head != NULL)
    {
        LStackPop(Stack);
    }
}

void LQueueCreate(LQueue * Queue)
{
    Queue->Head = NULL;
    Queue->Tail = NULL;
}

void LQueueEnqueue(LQueue * Queue, int Value)
{
    SQNode * S = (SQNode *) malloc(sizeof(SQNode));
    S->Next = 0;
    S->Value = Value;
    if(Queue->Head == NULL)
    {
        Queue->Tail = S;
        Queue->Head = Queue->Tail;
    }else
    {
        Queue->Tail->Next = S;
        Queue->Tail = S;
    }
}

int LQueueDequeue(LQueue * Queue)
{
    SQNode * S = Queue->Head;
    int Value = S->Value;
    Queue->Head = Queue->Head->Next;
    free(S);
    return Value;
}

void LQueueDelete(LQueue * Queue)
{
    while(Queue->Head != NULL)
    {
        LQueueDequeue(Queue);
    }
}

#endif