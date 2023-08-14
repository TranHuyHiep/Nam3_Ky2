// LineDemo.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "LineDemo.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_LINEDEMO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LINEDEMO));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LINEDEMO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LINEDEMO);
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
    static int width, height;
    static HPEN hpen1, hpen2, hpen3;
    static HBRUSH hbrush1, hbrush2;

    static HBRUSH hbrush;
    static HPEN hpen;
    static int penStyle = PS_SOLID;
    static COLORREF penColor = RGB(0, 0, 0);
    static int xLeft, yTop, xRight, yBottom;
    static HDC hdc;
    static POINT pt[3];
    switch (message)
    {
    case WM_LBUTTONDOWN:
        xLeft = LOWORD(lParam);
        yTop = HIWORD(lParam);
        break;
    case WM_LBUTTONUP:
        xRight = LOWORD(lParam);
        yBottom = HIWORD(lParam);
        pt[0].x = xLeft + (xRight - xLeft) / 2;
        pt[0].y = yTop;
        pt[1].x = xRight;
        pt[1].y = yBottom;
        pt[2].x = xLeft;
        pt[2].y = yBottom;

        hdc = GetDC(hWnd);
        SelectObject(hdc, hpen);
        SelectObject(hdc, hbrush);
        Polygon(hdc, pt, 3);
        ReleaseDC(hWnd, hdc);
        break;
    case WM_SIZE:
        width = LOWORD(lParam);
        height = HIWORD(lParam);

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_NENDO:
                hbrush = CreateSolidBrush(RGB(255, 0, 0));
                break;
            case ID_NENXANH:
                hbrush = CreateSolidBrush(RGB(0, 255, 0));
                break;
            case ID_NENVANG:
                hbrush = CreateSolidBrush(RGB(255, 255, 0));
                break;
            case ID_Vien1:
                penStyle = PS_DOT;
                hpen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_Vien2:
                penStyle = PS_DASH;
                hpen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_VienDo:
                penColor = RGB(255, 0, 0);
                hpen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_VienVang:
                penColor = RGB(255, 255, 0);
                hpen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_VienXanh:
                penColor = RGB(0, 0, 255);
                hpen = CreatePen(penStyle, 1, penColor);
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
            // create pen
            hpen1 = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
            hpen2 = CreatePen(PS_DASH, 1, RGB(0, 255, 0));
            hpen3 = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
            // create brushes
            hbrush1 = CreateSolidBrush(RGB(255, 255, 0));
            hbrush2 = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 255));

            // draw
            HDC hdc = BeginPaint(hWnd, &ps);
            SelectObject(hdc, hpen1);
            // TODO: Add any drawing code that uses hdc here...
            SelectObject(hdc, hbrush1);

            Rectangle(hdc, width / 8, height / 8, 7 * width / 8, 7 * height / 8);
            // Ve 2 duong cheo
            SelectObject(hdc, hpen2);
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, width, height);
            MoveToEx(hdc, 0, height, NULL);
            LineTo(hdc, width, 0);
            // ve elípe
            SelectObject(hdc, hbrush2);
            Ellipse(hdc, width / 8, height / 8, 7 * width / 8, 7 * height / 8);
            SelectObject(hdc, hpen3);
            RoundRect(hdc, width / 4, height / 4, width * 3 / 4, height * 3 / 4, 200, 200);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        DeleteObject(hpen1);
        DeleteObject(hpen2);
        DeleteObject(hpen3);
        DeleteObject(hbrush1);
        DeleteObject(hbrush2);

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
