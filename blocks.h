#ifndef BLOCKS
#define BLOCKS
#include <stdio.h>
#include "imports.h"

typedef struct block
{
    int x;
    int y;
    int type;
} block;

FILE * archive;

LList *readArchive()
{
    int n1, n2, n3;
    int count = 0;
    FILE * File = fopen("Map.txt", "r");
    LList *lista;
    LListCreate(lista);

    block *bloco;

    while(!feof(File))
    {
        ++count;
        fscanf(File, "%i,%i,%i", &bloco->x, &bloco->y, &bloco->type);
        LListAdd(lista, bloco);
    }
    for(int i = 0; i < 100; i++)
    {
        printf(LListGet(lista, i));
    }
}


#endif 
