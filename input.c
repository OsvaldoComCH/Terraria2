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

void input(character * Player)
{
    if(GetAsyncKeyState(VK_A))
    {
        MoveLeft(Player, 3);
    }
    if(GetAsyncKeyState(VK_D))
    {
        MoveRight(Player, 3);
    }
}