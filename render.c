#include "imports.h"
#include "functions.c"

void DrawMap(const LList * Map, HWND hwnd)
{
    HDC hdc = GetDC(hwnd);
    LLNode * N = Map->Head;
    for(int i = 0; i < Map->Size; ++i)
    {
        block * B = (block *) N->Value;
        DrawRect(hdc, B->x*32, 720 - B->y*32, 32, 32, RGB(100, 50, 0));
        N = N->Next;
    }
    ReleaseDC(hwnd, hdc);
}