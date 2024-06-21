#include "imports.h"

void MoveLeft(character * Player, int Pixels)
{
    Player->state ^ 1;
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

void MoveDown(character * Player, int Pixels)
{
    Player->ySubPos -= Pixels;
    if(Player->ySubPos < 0)
    {
        Player->yPos -= Player->ySubPos / 32 + 1;
        Player->ySubPos = 32 - Player->ySubPos % 32;
    }
}

void MoveUp(character * Player, int Pixels)
{
    Player->ySubPos += Pixels;
    if(Player->ySubPos > 31)
    {
        Player->yPos += Player->ySubPos / 32;
        Player->ySubPos = Player->ySubPos % 32;
    }
}

int Collision(const LList * Map, const character * Player, int Dir)//Dir - 0=Right, 1=Down, 2=Left, 3=Right
{
    RECT PlayerRect, BlockRect, Intersection;
    PlayerRect.left = Player->xPos*32 + Player->xSubPos;
    PlayerRect.bottom = 649 - Player->yPos*32 - Player->ySubPos;
    PlayerRect.right = PlayerRect.left + 32;
    PlayerRect.top = PlayerRect.bottom - 64;
    LLNode * N = Map->Head;
    for(int i = 0; i < Map->Size; ++i)
    {
        block * Block = (block *) N->Value;


        IntersectRect();
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