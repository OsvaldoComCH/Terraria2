#include "imports.h"
#include "functions.c"

void RenderMap(const LList * Map, HDC hdc)
{
    block * B = (block *) Map->Head->Value;
    BITMAP bm;
    HBITMAP Image = (HBITMAP)LoadImage(NULL, B->img, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    HDC BitmapDC = CreateCompatibleDC(hdc);
    SelectObject(BitmapDC, Image);
    GetObject((HGDIOBJ)Image, sizeof(bm), &bm);

    LLNode * N = Map->Head;
    for(int i = 0; i < Map->Size; ++i)
    {
        B = (block *) N->Value;
        TransparentBlt(hdc, B->x*32, 649 - (B->y*32), bm.bmWidth, bm.bmHeight, BitmapDC, 0, 0, 31, 31, RGB(255, 0, 255));
        N = N->Next;
    }
    
    DeleteDC(BitmapDC);
    DeleteObject(Image);
}

void RenderPlayer(const character * Player, HDC hdc)
{
    wchar_t * img
    if(Player.state == 0)
    {
        img = "imagens/Ferzinho3.bmp";
    }
    else
    {
        img = "imagens/Ferzinho.bmp";
    }
    DrawImg(hdc, Player->xPos*32 + Player->xSubPos, 649 - Player->yPos*32 - Player->ySubPos, 32, 64, img);
}