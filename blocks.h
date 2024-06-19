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

// Estrutura dos blocos, especificando com posição e tipo.
typedef struct block
{
    int x;
    int y;
    int type;
} block;

FILE * archive;




#endif 
