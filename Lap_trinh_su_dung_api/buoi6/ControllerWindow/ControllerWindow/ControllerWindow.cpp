// ControllerWindow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ControllerWindow.h"

#define MAX_LOADSTRING 100
#define ID_EDITHT 1
#define ID_BUTTONOK 2
#define ID_BUTTONCLOSE 3
#define ID_BUTTONRESET 4
#define ID_CHECKMUSIC 5
#define ID_CHECKGAME 6
#define ID_CHECKSHOPPING 7

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND editHT, btnOK, btnClose, btnReset, chkMusic, chkGame, chkShopping;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CONTROLLERWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONTROLLERWINDOW));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CONTROLLERWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CONTROLLERWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR hoten[30], result[35];
    static int len = 0, count = 0;

    switch (message)
    {
    case WM_CLOSE:
        SendMessage(btnClose, BM_CLICK, 0, 0);
        break;
    case WM_CREATE:
        editHT = CreateWindow(TEXT("edit"), TEXT(""), 
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            50, 50, 200, 30, hWnd, (HMENU) ID_EDITHT, NULL, NULL);

        btnOK = CreateWindow(TEXT("button"), TEXT("OK"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            255, 50, 80, 30, hWnd, (HMENU) ID_BUTTONOK, NULL, NULL);

        btnReset = CreateWindow(TEXT("button"), TEXT("Reset"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            340, 50, 80, 30, hWnd, (HMENU) ID_BUTTONRESET, NULL, NULL);

        btnClose = CreateWindow(TEXT("button"), TEXT("Close"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            425, 50, 80, 30, hWnd, (HMENU) ID_BUTTONCLOSE, NULL, NULL);

        // insert a BS_CHECKBOX
        chkMusic = CreateWindow(TEXT("button"), TEXT("Music"),
            WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
            50, 85, 80, 30, hWnd, (HMENU) ID_CHECKMUSIC, NULL, NULL);

        chkGame = CreateWindow(TEXT("button"), TEXT("Game"),
            WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
            50, 120, 80, 30, hWnd, (HMENU) ID_CHECKGAME, NULL, NULL);

        chkShopping = CreateWindow(TEXT("button"), TEXT("Shopping"),
            WS_CHILD | WS_VISIBLE | BS_AUTO3STATE,
            50, 155, 80, 30, hWnd, (HMENU) BS_CHECKBOX, NULL, NULL);
        ShowWindow(chkShopping, SW_SHOWNORMAL);
        EnableWindow(btnReset, FALSE);
        break;
    case WM_COMMAND: // khi click
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_BUTTONRESET:
                SetWindowText(editHT, TEXT(""));
                SendMessage(chkMusic, BM_SETCHECK, 0, 0);
                SendMessage(chkGame, BM_SETCHECK, 0, 0);
                SendMessage(chkShopping, BM_SETCHECK, 0, 0);
                EnableWindow(btnReset, FALSE);
                break;
            case ID_BUTTONOK:
                len = GetWindowText(editHT, hoten, 30);
                if (len == 0) {
                    MessageBox(NULL, TEXT("Please enter your name!"), 
                        TEXT("Warning!"), MB_OK);
                    SetFocus(editHT);
                    return 0;
                }
                // count options
                if (SendMessage(chkMusic, BM_GETCHECK, 0, 0) == TRUE) {
                    count++;
                }
                if (SendMessage(chkGame, BM_GETCHECK, 0, 0) == TRUE) {
                    count++;
                }
                if (SendMessage(chkShopping, BM_GETCHECK, 0, 0) == TRUE) {
                    count++;
                }
                if (count == 0) {
                    MessageBox(NULL, TEXT("Chon de!"), TEXT("Warning!"), MB_OK);
                    return 0;
                }
                wsprintf(result, L"%s has successfully registered!", hoten);
                MessageBox(NULL, result, TEXT("Result"), MB_OK);
                EnableWindow(btnReset, TRUE);
                break;
            case ID_CHECKMUSIC:
                // Neu dang chon -> bo chon
                if (SendMessage(chkMusic, BM_GETCHECK, 0, 0) == TRUE) {
                    SendMessage(chkMusic, BM_SETCHECK, 0, 0);
                }
                else {
                    SendMessage(chkMusic, BM_SETCHECK, 1, 0);
                }
                break;
            case ID_BUTTONCLOSE:
                if (MessageBox(NULL, TEXT("Do you want to exit?"), TEXT("Question"),
                    MB_YESNO | MB_ICONQUESTION) == IDYES)
                    PostQuitMessage(0); // ket thuc chuong trinhf
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
