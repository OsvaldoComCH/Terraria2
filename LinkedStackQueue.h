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

void CreateLStack(LStack * Stack)
{
    Stack->Head = NULL;
}

void Push(LStack * Stack, int Value)
{
    SQNode * S = (SQNode *) malloc(sizeof(SQNode));
    S->Next = Stack->Head;
    S->Value = Value;
    Stack->Head = S;
}

int Pop(LStack * Stack)
{
    SQNode * S = Stack->Head;
    int Value = S->Value;
    Stack->Head = Stack->Head->Next;
    free(S);
    return Value;
}

void DeleteLStack(LStack * Stack)
{
    while(Stack->Head != NULL)
    {
        Pop(Stack);
    }
}

void CreateLQueue(LQueue * Queue)
{
    Queue->Head = NULL;
    Queue->Tail = NULL;
}

void Enqueue(LQueue * Queue, int Value)
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

int Dequeue(LQueue * Queue)
{
    SQNode * S = Queue->Head;
    int Value = S->Value;
    Queue->Head = Queue->Head->Next;
    free(S);
    return Value;
}

void DeleteLQueue(LQueue * Queue)
{
    while(Queue->Head != NULL)
    {
        Dequeue(Queue);
    }
}

#endif