#ifndef CHARACTERS
#define CHARACTERS

typedef struct character
{
    int xPos, yPos;
    int xSubPos, ySubPos;
    int inventory[32];
    int life = 10;
    int damage = 0;
    char * img;
} character;

typedef struct zombie
{
    int xPos, yPos;
    int xSubPos, ySubPos;
    int life = 10;
    int damage = 0;
    char * img;
} zombie;

#endif