#ifndef BLOCKS
#define BLOCKS
#include <stdio.h>
#include "imports.h"

FILE * archive;

/* 
Função de leitura do arquivo de mapa, fazemos a construção do mapa do Ternaria por meio da leitura desse arquivo.
*/ 
LList *readArchive()
{
    LList *list;
    LListCreate(list);
    char line[10];
    
    archive = fopen("Map.txt", "r");

    LListAdd(list, (line, 10, archive));

    return list;
}

// Estrutura dos blocos, especificando com posição e tipo.
typedef struct block
{
    int x;
    int y;
    int type;
} block;

#endif 
