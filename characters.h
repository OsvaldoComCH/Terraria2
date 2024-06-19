#ifndef CHARACTERS
#define CHARACTERS

typedef struct character
{
    int xPos, yPos;
    int xSubPos, ySubPos;
    int inventory[32];

    int life;
    int damage;
    char * img;
} character;

typedef struct zombie
{
    int life;
    int damage;
    int xPos, yPos;
    int xSubPos, ySubPos;
    char * img;
} zombie;

#endif