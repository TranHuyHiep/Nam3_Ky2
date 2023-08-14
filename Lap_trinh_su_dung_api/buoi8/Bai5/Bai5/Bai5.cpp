// Bai5.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Bai5.h"

#define MAX_LOADSTRING 100
#define ID_NAME 3
#define ID_LIST_SV 4
#define ID_BTN_THEM 5
#define ID_BTN_XOA 6
#define ID_BTN_TIMKIEM 7
#define ID_BTN_THOAT 8

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hwndtxtName, hwndListSV, hwndBtnThem, hwndBtnXoa, hwndTimKiem, hwndThoat;

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
    LoadStringW(hInstance, IDC_BAI5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI5));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BAI5);
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
    static TCHAR ht[30];
    static int lenHT, lIndex, fIndex;
    switch (message)
    {
    case WM_CREATE:

        hwndtxtName = CreateWindow(TEXT("edit"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            100, 20, 200, 30, hWnd, (HMENU)ID_NAME, NULL, NULL);
        hwndListSV = CreateWindow(TEXT("listbox"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            20, 100, 300, 100, hWnd, (HMENU)ID_LIST_SV, NULL, NULL);
        hwndBtnThem = CreateWindow(TEXT("button"), TEXT("Thêm mới"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            20, 210, 100, 50, hWnd, (HMENU)ID_BTN_THEM, NULL, NULL);
        hwndBtnXoa = CreateWindow(TEXT("button"), TEXT("Xóa"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            130, 210, 100, 50, hWnd, (HMENU)ID_BTN_XOA, NULL, NULL);
        hwndTimKiem = CreateWindow(TEXT("button"), TEXT("Tìm kiếm"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            240, 210, 100, 50, hWnd, (HMENU)ID_BTN_TIMKIEM, NULL, NULL);
        hwndThoat = CreateWindow(TEXT("button"), TEXT("Thoát"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            350, 210, 100, 50, hWnd, (HMENU)ID_BTN_THOAT, NULL, NULL);
        EnableWindow(hwndBtnXoa, false);

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_LIST_SV:
                lIndex = (int)SendMessage(hwndListSV, CB_GETCURSEL, 0, 0);
                if (lIndex >= 0) {
                    EnableWindow(hwndBtnXoa, true);
                }
                else {
                    EnableWindow(hwndBtnXoa, false);
                }
                break;
            case ID_BTN_THEM:
                GetWindowText(hwndtxtName, ht, 30);
                lenHT = GetWindowTextLength(hwndtxtName);
                if (lenHT == 0) {
                    MessageBox(hWnd, TEXT("Vui lòng nhập tên"), TEXT("Lỗi"), MB_OK);
                    return 0;
                }
                SendMessage(hwndListSV, LB_ADDSTRING, -1, (LPARAM) ht);
                SetWindowText(hwndtxtName, TEXT(""));
                break;
            case ID_BTN_XOA:
                SendMessage(hwndListSV, LB_DELETESTRING, lIndex, 0);
                break;
            case ID_BTN_TIMKIEM:
                GetWindowText(hwndtxtName, ht, 30);
                fIndex = (int)SendMessage(hwndListSV, LB_FINDSTRING, 0, (LPARAM) ht);
                if (fIndex >= 0) {
                    SendMessage(hwndListSV, LB_SETCURSEL, fIndex, 0);
                }
                else {
                    MessageBox(NULL, TEXT("Không tìm thấy"), 0, 0);
                }
                break;
            case ID_BTN_THOAT:
                DestroyWindow(hWnd);
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
            TextOut(hdc, 20, 20, TEXT("Họ và tên"), 10);
            TextOut(hdc, 20, 70, TEXT("Danh sách sinh viên"), 10);

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
