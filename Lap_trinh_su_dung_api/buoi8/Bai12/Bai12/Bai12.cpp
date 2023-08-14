// Bai12.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Bai12.h"

#define MAX_LOADSTRING 100
#define ID_GROUB_CHONHINH 1
#define ID_GROUB_CHONMAUNEN 2
#define ID_GROUB_CHONMAUDUONGVIEN 3
#define ID_HINH_VUONG 4
#define ID_HINH_TRON 5
#define ID_MAUNEN_DO 6
#define ID_MAUNEN_XANHLA 7 
#define ID_MAUNEN_XANHDUONG 8 
#define ID_MAUNEN_VANG 9
#define ID_MAUNEN_XANHNHAT 10
#define ID_MAUDUONGVIEN_DO 11 
#define ID_MAUDUONGVIEN_XANHLA 12
#define ID_MAUDUONGVIEN_XANHDUONG 13
#define ID_MAUDUONGVIEN_VANG 14
#define ID_MAUDUONGVIEN_XANHNHAT 15


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HWND hwndGroubChonHinh, hwndGroubChonMauNen, hwndGroubChonMauDuongVien,
hwndHinhVuong, hwndHinhTron,
hwndMauNenDo, hwndMauNenXanhLa, hwndMauNenXanhDuong,
hwndMauNenVang, hwndMauNenXanhNhat,
hwndMauDuongVienDo, hwndMauDuongVienXanhLa,
hwndMauDuongVienXanhDuong, hwndMauDuongVienVang,
hwndMauDuongVienXanhNhat;

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
    LoadStringW(hInstance, IDC_BAI12, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI12));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI12));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BAI12);
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
    static HPEN hpen;
    static HBRUSH hbrush, hbrushother;
    static POINT pt[2];
    static int xIn, yIn, xOut, yOut;
    static HDC hdc, hdcmaunen;
    static int style;
    
    switch (message)
    {
    case WM_LBUTTONDOWN:
        xIn = LOWORD(lParam);
        yIn = HIWORD(lParam);
        break;
    case WM_LBUTTONUP:
        xOut = LOWORD(lParam);
        yOut = HIWORD(lParam);
        hdc = GetDC(hWnd);
        SelectObject(hdc, hpen);
        SelectObject(hdc, hbrush);
        
        switch (style)
        {
        case ID_HINH_VUONG:
            Rectangle(hdc, xIn, yIn, xOut, yOut);
            break;
        case ID_HINH_TRON:
            Ellipse(hdc, xIn, yIn, xOut, yOut);
            break;
        default:
            break;
        }

        ReleaseDC(hWnd, hdc);
        break;
    case WM_CREATE:
        // draw group
        hwndGroubChonHinh = CreateWindow(TEXT("button"), TEXT("Chọn hình"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_GROUPBOX,
            20, 20, 200, 100, hWnd, (HMENU) ID_GROUB_CHONHINH, NULL, NULL);
        hwndGroubChonMauNen = CreateWindow(TEXT("button"), TEXT("Chọn màu nền"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_GROUPBOX,
            230, 20, 410, 100, hWnd, (HMENU) ID_GROUB_CHONMAUNEN, NULL, NULL);
        hwndGroubChonMauDuongVien = CreateWindow(TEXT("button"), TEXT("Chọn màu đường viền"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_GROUPBOX,
            650, 20, 410, 100, hWnd, (HMENU) ID_GROUB_CHONMAUDUONGVIEN, NULL, NULL);
        // draw hinh
        hwndHinhVuong = CreateWindow(TEXT("button"), TEXT("Vuông"),
            WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
            40, 40, 70, 70, hWnd, (HMENU) ID_HINH_VUONG, NULL, NULL);
        hwndHinhTron = CreateWindow(TEXT("button"), TEXT("Tròn"),
            WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
            130, 40, 70, 70, hWnd, (HMENU)ID_HINH_TRON, NULL, NULL);
        // draw mau nen
        hwndMauNenDo = CreateWindow(TEXT("button"), TEXT("RED"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            240, 40, 70, 70, hWnd, (HMENU) ID_MAUNEN_DO, NULL, NULL);
        hwndMauNenXanhLa = CreateWindow(TEXT("button"), TEXT("GREEN"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            320, 40, 70, 70, hWnd, (HMENU) ID_MAUNEN_XANHLA, NULL, NULL);
        hwndMauNenXanhDuong = CreateWindow(TEXT("button"), TEXT("BLUE"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            400, 40, 70, 70, hWnd, (HMENU) ID_MAUNEN_XANHDUONG, NULL, NULL);
        hwndMauNenVang = CreateWindow(TEXT("button"), TEXT("YELLOW"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            480, 40, 70, 70, hWnd, (HMENU) ID_MAUNEN_VANG, NULL, NULL);
        hwndMauNenXanhNhat = CreateWindow(TEXT("button"), TEXT("CYAL"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            560, 40, 70, 70, hWnd, (HMENU) ID_MAUNEN_XANHNHAT, NULL, NULL);
        // Draw mau duong vien
        hwndMauDuongVienDo = CreateWindow(TEXT("button"), TEXT("RED"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            660, 40, 70, 70, hWnd, (HMENU) ID_MAUDUONGVIEN_DO, NULL, NULL);
        hwndMauDuongVienXanhLa = CreateWindow(TEXT("button"), TEXT("GREEN"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            740, 40, 70, 70, hWnd, (HMENU) ID_MAUDUONGVIEN_XANHLA, NULL, NULL);
        hwndMauDuongVienXanhDuong = CreateWindow(TEXT("button"), TEXT("BLUE"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            820, 40, 70, 70, hWnd, (HMENU) ID_MAUDUONGVIEN_XANHDUONG, NULL, NULL);
        hwndMauDuongVienVang = CreateWindow(TEXT("button"), TEXT("YELLOW"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            900, 40, 70, 70, hWnd, (HMENU) ID_MAUDUONGVIEN_VANG, NULL, NULL);
        hwndMauDuongVienXanhNhat = CreateWindow(TEXT("button"), TEXT("CYAL"),
            WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
            980, 40, 70, 70, hWnd, (HMENU) ID_MAUDUONGVIEN_XANHNHAT, NULL, NULL);
        break;
    case WM_CTLCOLORSTATIC:
        SetBkColor(GetDC(hwndMauNenDo), RGB(0, 0, 0));
        SetBkMode((HDC)wParam, TRANSPARENT);
        return(LRESULT)GetStockObject(HOLLOW_BRUSH);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            // MAU NEN
            case ID_MAUNEN_DO:
                hbrush = CreateSolidBrush(RGB(255, 0, 0));
                break;
            case ID_MAUNEN_XANHLA:
                hbrush = CreateSolidBrush(RGB(0, 255, 0));
                break;
            case ID_MAUNEN_XANHDUONG:
                hbrush = CreateSolidBrush(RGB(0, 0, 255));
                break;
            case ID_MAUNEN_VANG:
                hbrush = CreateSolidBrush(RGB(255, 255, 0));
                break;
            case ID_MAUNEN_XANHNHAT:
                hbrush = CreateSolidBrush(RGB(0, 100, 255));
                break;
            // MAU VIEN
            case ID_MAUDUONGVIEN_DO:
                hpen = CreatePen(PS_ALTERNATE, 2, RGB(255, 0, 0));
                break;
            case ID_MAUDUONGVIEN_XANHLA:
                hpen = CreatePen(PS_ALTERNATE, 2, RGB(0, 255, 0));
                break;
            case ID_MAUDUONGVIEN_XANHDUONG:
                hpen = CreatePen(PS_ALTERNATE, 2, RGB(0, 0, 255));
                break;
            case ID_MAUDUONGVIEN_VANG:
                hpen = CreatePen(PS_ALTERNATE, 2, RGB(255, 255, 0));
                break;
            case ID_MAUDUONGVIEN_XANHNHAT:
                hpen = CreatePen(PS_ALTERNATE, 2, RGB(0, 100, 255));
                break;
            // HINH VE
            case ID_HINH_VUONG:
                style = wmId;
                break;
            case ID_HINH_TRON:
                style = wmId;
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
    case WM_DRAWITEM:
        static LPDRAWITEMSTRUCT lpDIS = (LPDRAWITEMSTRUCT)lParam;
        switch (wParam)
        {
            // NAU NEN 
        case ID_MAUNEN_DO:
            SetDCBrushColor(lpDIS->hDC, RGB(255, 0, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUNEN_XANHLA:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 255, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUNEN_XANHDUONG:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 0, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUNEN_VANG:
            SetDCBrushColor(lpDIS->hDC, RGB(255, 255, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUNEN_XANHNHAT:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 100, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
            // NAU VIEN
        case ID_MAUDUONGVIEN_DO:
            SetDCBrushColor(lpDIS->hDC, RGB(255, 0, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUDUONGVIEN_XANHLA:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 255, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUDUONGVIEN_XANHDUONG:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 0, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUDUONGVIEN_VANG:
            SetDCBrushColor(lpDIS->hDC, RGB(255, 255, 0));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
        case ID_MAUDUONGVIEN_XANHNHAT:
            SetDCBrushColor(lpDIS->hDC, RGB(0, 100, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            break;
            // HINH DANG
        case ID_HINH_VUONG:
            SetDCPenColor(lpDIS->hDC, RGB(0, 100, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            Rectangle(lpDIS->hDC, lpDIS->rcItem.left + 10, lpDIS->rcItem.top + 10,
                lpDIS->rcItem.right - 10, lpDIS->rcItem.bottom - 10);
            break;
        case ID_HINH_TRON:
            SetDCPenColor(lpDIS->hDC, RGB(0, 100, 255));
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH));
            RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);
            Ellipse(lpDIS->hDC, lpDIS->rcItem.left + 10, lpDIS->rcItem.top + 10,
                lpDIS->rcItem.right - 10, lpDIS->rcItem.bottom - 10);
            break;
        default:
            break;
        }
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
