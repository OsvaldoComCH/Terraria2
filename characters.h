#ifndef CHARACTERS
#define CHARACTERS

typedef struct character
{
    int inventory[32];
    int life[10];
    int damage;
    char * img;
} character;

typedef struct zombie
{
    int life;
    int damage;
    char * img;
} zombie;

#endif // !

