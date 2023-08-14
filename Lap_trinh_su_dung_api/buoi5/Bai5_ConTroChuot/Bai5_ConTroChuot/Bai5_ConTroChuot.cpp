// Bai5_ConTroChuot.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Bai5_ConTroChuot.h"

#define MAX_LOADSTRING 100
#define ID_EDIT 2
#define ID_BTNOK 3


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hwndEditHT, hwndBTNOK;

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
    LoadStringW(hInstance, IDC_BAI5CONTROCHUOT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI5CONTROCHUOT));

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

    wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI5CONTROCHUOT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BAI5CONTROCHUOT);
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

   HWND hWnd = CreateWindowW(
       szWindowClass,       // Tên lớp của cửa sổ (kiểu TEXT)
       szTitle,             // tiêu đề
       WS_OVERLAPPEDWINDOW, // WS: Window Style: kiểu cửa sổ
       CW_USEDEFAULT,       
       0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
// hWnd: handler window cửa sổ
// UNIT: thông điệp
// wParam: id 
// lParam: kich thuoc cửa sổ
//
// WS_CHILD
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT pt[1000];
    static HDC hdc; // Handle Device Context: ngữ cảnh (DC)
    // HB: Handle Brush: ngữ cảnh bút vẽ
    static int i, j, count = 0, m = 0, s = 10, width, height;
    static TCHAR timeLeft[20];

    // WM: Window Message
    // BM: Button Message
    // LB: Listbox Button
    switch (message)
    {
    case WM_CREATE: // khi cua so duoc ta
        SetTimer(hWnd, 1, 1000, NULL);
        
        // chèn 1 edit và 1 button
        hwndEditHT = CreateWindow(TEXT("edit"), TEXT(""), 
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            50, 50, 200, 50, hWnd, (HMENU)ID_EDIT, NULL, NULL);
        hwndBTNOK = CreateWindow(TEXT("button"), TEXT("OK"), 
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            255, 50, 60, 50, hWnd, (HMENU)ID_BTNOK, NULL, NULL);
        break;
    case WM_SIZE:
        width = LOWORD(lParam); // lay ra chieu rong
        height = HIWORD(lParam); // lay ra chieu doc
        break;
    case WM_TIMER:
        if (s == 0 && m > 0) {
            s = 59;
            m = m - 1;
        }
        else {
            if (s > 0 && s <= 59) {
                s = s - 1;
            }
            if (s == 0 && m == 0) {
                KillTimer(hWnd, 1);
                MessageBox(NULL, TEXT("Het gio!"), TEXT("Thong bao"), MB_OK);
            }
        }
        wsprintfW(timeLeft, L"Time left: %d:%d", m, s); // tạo ra 1 chuỗi "timeLeft"
        hdc = GetDC(hWnd);     // Lấy ngữ cảnh
        TextOut(hdc, width-100, height-20, timeLeft, 200);
        ReleaseDC(hWnd, hdc);
        break;
    case WM_LBUTTONDOWN:
        pt[count].x = LOWORD(lParam);
        pt[count].y = HIWORD(lParam);
        hdc = GetDC(hWnd);
        SetPixel(hdc, pt[count].x, pt[count].y, RGB(0, 0, 0));
        ReleaseDC(hWnd, hdc);
        count++;
        break;
    case WM_RBUTTONDOWN:
        hdc = GetDC(hWnd);
        for (i = 0; i < count - 1; i++)
        {
            for (j = i + 1; j < count; j++) 
            {
                MoveToEx(hdc, pt[i].x, pt[i].y, NULL);
                LineTo(hdc, pt[j].x, pt[j].y);
            }
        }
        ReleaseDC(hWnd, hdc);
        break;
    case WM_LBUTTONDBLCLK:
        InvalidateRect(hWnd, NULL, TRUE);
        count = 0;
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
