#ifndef BLOCKS
#define BLOCKS
#include <stdio.h>

FILE * archive;

void readArchive()
{
    archive = fopen("Map.txt", );
}

typedef struct block
{
    int x;
    int y;
    int type;

} block;

#endif 
