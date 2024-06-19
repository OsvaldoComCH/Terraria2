#ifndef BLOCKS
#define BLOCKS
#include <stdio.h>
#include "imports.h"

FILE * archive;

LList *readArchive()
{
    LList *list;
    LListCreate(list);
    char line[10];
    
    archive = fopen("Map.txt", "r");

    LListAdd(list, (line, 10, archive));

    return list;
}

typedef struct block
{
    int x;
    int y;
    int type;

} block;

#endif 
