/* Compile:
gcc main.c -o Ternaria.exe -l gdi32 -l msimg32
*/

#include "imports.h"
#include "render.c"
#include "input.c"

DWORD ThreadID;
HANDLE Thread;


//Função da thread principal
DWORD WINAPI MainThread(LPVOID lpParam)
{
    HWND hwnd = *((HWND *)lpParam);

    LList Map;
    int gameover = 0;
    character player;
    player.xPos = 10;
    player.yPos = 10;   
    player.xSubPos = 0;
    player.ySubPos = 0;
    player.life = 10;
    player.damage = 1;
    player.state = 0;

    zombie zombie;
    zombie.life = 12;
    zombie.damage = 2;
    zombie.img = NULL;

    LListCreate(&Map);
    SetThreadPriority(Thread, 2);
    readArchive(&Map);
    
    HANDLE Timer = CreateWaitableTimer(NULL, 0, NULL);
    LARGE_INTEGER DueTime;
    DueTime.QuadPart = -200000;
    SetWaitableTimer(Timer, &DueTime, 50, NULL, NULL, 0);
    while(gameover == 0)
    {
        input(&player);
        HDC hdc = GetDC(hwnd);
        RECT R;
        GetClientRect(hwnd, &R);
        HDC TempDC = CreateCompatibleDC(hdc);
        HBITMAP Bitmap = CreateCompatibleBitmap(hdc, (R.right-R.left), (R.bottom - R.top));
        SelectObject(TempDC, Bitmap);

        DrawImg(TempDC, 0, 0, 960, 720, L"imagens/BackGround.bmp");
        RenderMap(&Map, TempDC);
        RenderPlayer(&player, TempDC);

        BitBlt(hdc, 0, 0, R.right-R.left, R.bottom-R.top, TempDC, 0, 0, SRCCOPY);
        DeleteDC(TempDC);
        DeleteObject(Bitmap);
        ReleaseDC(hwnd, hdc);
        WaitForSingleObject(Timer, INFINITE);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch(Msg)
    {
        case WM_SETREDRAW:
        {

        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT PS;
            HDC hdc = BeginPaint(hwnd, &PS);
            FillRect(hdc, &PS.rcPaint, CreateSolidBrush(RGB(255,255,255)));
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
    const wchar_t WClassName[]  = L"Ternaria";
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
        L"Terraria 2",
        WS_OVERLAPPEDWINDOW,
        200, 10, 975, 720,
        NULL, NULL, hInstance, NULL
    );

    if(hwnd == NULL)
    {
        MessageBox(NULL, L"Window Creation Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HICON hIcon = (HICON)LoadImage(NULL, L"imagens/iconeTernaria.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    
    if (hIcon != NULL) {
        // Definindo o ícone grande da janela
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        // Definindo o ícone pequeno da janela
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    } else {
        MessageBox(NULL, L"Erro ao carregar o icone!", L"Erro", MB_ICONERROR);
    }
    
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    Thread = CreateThread(NULL, 0, MainThread, &hwnd, 0, &ThreadID);

    while(GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}