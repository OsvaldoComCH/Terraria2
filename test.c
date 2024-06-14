#ifndef UNICODE
#define UNICODE
#endif

#include "windows.h"


DWORD ThreadID;
HANDLE Thread;


DWORD WINAPI X(LPVOID lpParam)
{
    HWND hwnd = *((HWND *)lpParam);
    while(1)
    {
        HDC hdc = GetDC(hwnd);
        if(GetAsyncKeyState(VK_SPACE))
        {
            BITMAP bm;
            HBITMAP Image = (HBITMAP)LoadImage(NULL, L"./bmp.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            HDC BitmapDC = CreateCompatibleDC(hdc);
            SelectObject(BitmapDC, Image);
            GetObject((HGDIOBJ)Image, sizeof(bm), &bm);
            TransparentBlt(hdc, 10, 200, bm.bmWidth, bm.bmHeight, BitmapDC, 0, 0, 100, 100, RGB(255,255,255));
            DeleteDC(BitmapDC);
            DeleteObject(Image);
        }else
        {
            SelectObject(hdc, GetStockObject(DC_BRUSH));
            SetDCBrushColor(hdc, RGB(255,0,0));
            Rectangle(hdc, 10, 200, 110, 300);
        }
        ReleaseDC(hwnd, hdc);
        Sleep(100);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch(Msg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT PS;
            HDC hdc = BeginPaint(hwnd, &PS);
            Rectangle(hdc, 10, 10, 100, 100);
            EndPaint(hwnd, &PS);
        }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, Msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const wchar_t WClassName[]  = L"WindowClass";
    MSG Msg;
    WNDCLASS Window = {};
    Window.lpfnWndProc = WndProc;
    Window.hInstance = hInstance;
    Window.lpszClassName = WClassName;

    if(!RegisterClass(&Window))
    {
        MessageBox(NULL, L"Window Class Registration Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindowEx
    (
        0,
        WClassName,
        L"Tetris",
        WS_OVERLAPPEDWINDOW,
        200, 10, 960, 720,
        NULL, NULL, hInstance, NULL
    );
    if(hwnd == NULL)
    {
        MessageBox(NULL, L"Window Creation Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    Thread = CreateThread(NULL, 0, X, &hwnd, 0, &ThreadID);

    while(GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}