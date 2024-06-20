#ifndef BLOCKS
#define BLOCKS
#include <stdio.h>
#include "imports.h"


// Estrutura dos blocos, especificando com posição e tipo.
typedef struct block
{
    int x;
    int y;
    int type;
} block;

/* 
Função de leitura do arquivo de mapa, fazemos a construção do mapa do Ternaria por meio da leitura desse arquivo.
*/ 
LList *readArchive(LList *lista)
{
    int count = 0;
    FILE * File = fopen("Map.txt", "r");
    LListCreate(lista);

    while(!feof(File))
    {
        ++count;
        block *bloco = malloc(sizeof(block));
        fscanf(File, "%i,%i,%i", &bloco->x, &bloco->y, &bloco->type);
        LListAdd(lista, bloco);
    }
    return lista;
}




#endif 
