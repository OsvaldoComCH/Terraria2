#include "imports.h"

void MoveLeft(character * Player, int Pixels)
{
    Player->xSubPos -= Pixels;
    if(Player->xSubPos < 0)
    {
        Player->xPos -= Player->xSubPos / 32 + 1;
        Player->xSubPos = 32 - Player->xSubPos % 32;
    }
}

void MoveRight(character * Player, int Pixels)
{
    Player->xSubPos += Pixels;
    if(Player->xSubPos > 31)
    {
        Player->xPos += Player->xSubPos / 32;
        Player->xSubPos = Player->xSubPos % 32;
    }
}

void MoveUp(character * Player, int Pixels)
{
    Player->ySubPos -= Pixels;
    if(Player->ySubPos < 0)
    {
        Player->yPos -= Player->ySubPos / 32 + 1;
        Player->ySubPos = 32 - Player->ySubPos % 32;
    }
}

void MoveDown(character * Player, int Pixels)
{
    Player->ySubPos += Pixels;
    if(Player->ySubPos > 31)
    {
        Player->yPos += Player->ySubPos / 32;
        Player->ySubPos = Player->ySubPos % 32;
    }
}

void input(character * Player)
{
    if(GetAsyncKeyState(VK_A))
    {
        MoveLeft(Player, 5);
    }
    if(GetAsyncKeyState(VK_D))
    {
        MoveRight(Player, 5);
    }
    if(GetAsyncKeyState(VK_W))
    {
        MoveUp(Player, 5);
    }
    if(GetAsyncKeyState(VK_S))
    {
        MoveDown(Player, 5);
    }
}