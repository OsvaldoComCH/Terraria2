#include "imports.h"

typedef struct character
{
    int inventory[32];
    int life[10];
    int damage = 0;
    HDC hdc;
} character;

typedef struct zombie
{
    int life = 10;
    int damage = 0;
} zombie;


