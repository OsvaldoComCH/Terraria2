#ifndef CHARACTERS
#define CHARACTERS
#include "imports.h"
/* 
Estrutura dos personagens, especificando posição e subposição.
A subposição serve para calcular colisões entre personagem e bloco.
*/

typedef struct character
{
    int xPos, yPos;
    int xSubPos, ySubPos;
    int inventory[32];
    int life;
    int damage;
    wchar_t * img;
} character;

/*
Estrutura do zumbi.
*/

typedef struct zombie
{
    int life;
    int damage;
    int xPos, yPos;
    int xSubPos, ySubPos;
    wchar_t * img;
} zombie;

#endif