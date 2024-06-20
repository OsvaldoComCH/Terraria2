#include "imports.h"
#include "functions.c"

void RenderMap(const LList * Map, HWND hwnd)
{
    HDC hdc = GetDC(hwnd);
    LLNode * N = Map->Head;
    for(int i = 0; i < Map->Size; ++i)
    {
        block * B = (block *) N->Value;
        DrawImg(hdc, B->x*32, 649 - (B->y*32), 31, 31, B->img);
        N = N->Next;
    }
    ReleaseDC(hwnd, hdc);
}

void RenderPlayer(const character * Player, HWND hwnd)
{
    HDC hdc = GetDC(hwnd)
    
}