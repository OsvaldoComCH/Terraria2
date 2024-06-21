#include "imports.h"

int Collision(const LList * Map, const character * Player)
{
    RECT PlayerRect, BlockRect, Intersection;
    PlayerRect.left = Player->xPos*32 + Player->xSubPos;
    PlayerRect.top = 649 - Player->yPos*32 - Player->ySubPos;
    PlayerRect.right = PlayerRect.left + 32;
    PlayerRect.bottom = PlayerRect.top + 64;
    LLNode * N = Map->Head;
    for(int i = 0; i < Map->Size; ++i)
    {
        block * Block = (block *) N->Value;
        if(Block->x == Player->xPos + ((Player->xSubPos - 16) < 0) && Block->y == Player->yPos + ((Player->ySubPos - 16) < 0))
        {
            BlockRect.left = Block->x*32;
            BlockRect.top = 649 - Block->y*32;
            BlockRect.right = BlockRect.left + 32;
            BlockRect.bottom = BlockRect.top + 32;
            IntersectRect(&Intersection, &BlockRect, &PlayerRect);
            if(Intersection.right - Intersection.left && Intersection.top - Intersection.bottom)
            {
                return 1;
            }else
            {
                return 0;
            }
        }
        N = N->Next;
    }
}

void MoveLeft(character * Player, int Pixels)
{
    Player->state = Player->state ^ 1;
    Player->xSubPos -= Pixels;
    if(Player->xSubPos < 0)
    {
        Player->xPos -= Player->xSubPos / 32 + 1;
        Player->xSubPos = 32 - Player->xSubPos % 32;
    }
    /*if(Collision(Map, Player))
    {
        Player->xSubPos = 31;
    }*/
}

void MoveRight(character * Player, int Pixels)
{
    Player->state = Player->state ^ 1;
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

void Jump(character * Player, int Pixels)
{
    if(Player->jump <= 0)
    {
        if(Player->canJump == 1)
        {
            Player->jump = 65;
            Player->canJump = 0;
        }
    }
    else
    {
        Player->jump -= 5;
        MoveUp(Player, 5);
    }
}

void Gravity(character * Player, int Pixels)
{
    MoveDown(Player, Pixels);
}



void input(character * Player, LList * Map)
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
    if(GetAsyncKeyState(VK_SPACE))
    {
        Jump(Player, 5);
    }
    if(GetAsyncKeyState(VK_G))
    {
        Gravity(Player, 5);
    }
}