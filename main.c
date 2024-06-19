/* Compile:
gcc main.c -o Ternaria.exe -l gdi32 -l msimg32
*/

#include "imports.h"
#include "render.c"

DWORD ThreadID;
HANDLE Thread;

//Função da thread principal
DWORD WINAPI MainThread(LPVOID lpParam)
{
    int gameover = 0;
    character player;
    player.xPos = 10;
    player.yPos = 10;
    player.xSubPos = 0;
    player.ySubPos = 0;
    player.life = 10;
    player.damage = 1;
    player.img = NULL;

    zombie zombie;
    zombie.life = 12;
    zombie.damage = 2;
    zombie.img = NULL;

    HWND hwnd = *((HWND *)lpParam);
    while (gameover == 0)
    {

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
    const wchar_t WClassName[]  = L"Terraria 2";
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
        200, 10, 960, 720,
        NULL, NULL, hInstance, NULL
    );

    if(hwnd == NULL)
    {
        MessageBox(NULL, L"Window Creation Failed", L"Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HICON hIcon = (HICON)LoadImage(NULL, L"pixil-frame-0.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    
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