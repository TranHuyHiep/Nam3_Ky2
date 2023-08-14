// DialogExample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DialogExample.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    RegisterDialog(HWND, UINT, WPARAM, LPARAM);      // tạo hộp thoại about
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    RegisterSubjectDialog(HWND, UINT, WPARAM, LPARAM);


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
    LoadStringW(hInstance, IDC_DIALOGEXAMPLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DIALOGEXAMPLE));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DIALOGEXAMPLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DIALOGEXAMPLE);
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
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_FILE_REGISTERSUBJECT:
                HWND hwndDlg1;
                hwndDlg1 = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DANGKYHOC),
                    hWnd, RegisterSubjectDialog);
                ShowWindow(hwndDlg1, SW_SHOW);
                break;
            case ID_FILE_REGISTER:
                //DialogBox(hInst, MAKEINTRESOURCE(ID_REGISTER_DIALOG), hWnd, RegisterDialog);
                HWND hwndDlg;
                hwndDlg = CreateDialog(hInst, MAKEINTRESOURCE(ID_REGISTER_DIALOG),
                    hWnd, RegisterDialog);
                ShowWindow(hwndDlg, SW_SHOW);
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

// hàm dialog
INT_PTR CALLBACK    RegisterDialog(HWND hwndDialog, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int len;
    static TCHAR ht[30];
    static HWND editHT, lstSV, cboKhoa;

    switch (message) 
    {
    case WM_INITDIALOG:
        editHT = GetDlgItem(hwndDialog, IDC_EDITHT);
        lstSV = GetDlgItem(hwndDialog, IDC_LISTBOX);
        cboKhoa = GetDlgItem(hwndDialog, ID_CBO_KHOA);
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("60"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("61"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("62"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("63"));

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ADD:
            len = GetWindowText(editHT, ht, 30);
            if (len == 0)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập họ tên"), TEXT("Lỗi"), MB_OK);
                SetFocus(editHT);
                return 0;
            }
            SendMessage(lstSV, LB_INSERTSTRING, -1, (LPARAM) ht); // insert không cần sort
            SetWindowText(editHT, TEXT(""));
            SetFocus(editHT);

            break;
        default:
            break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwndDialog);
        break;
    default:
        
        break;
    }
    return false;
}

INT_PTR CALLBACK RegisterSubjectDialog(HWND hwndDialog, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND btnXoa, lstSV, cboKhoa, cboKhoaa, txtMSV, txtHoten, checkTin, checkTA, checkGT, checkTriet;
    static int lenMSV, lenHT, lIndex, count = 0;
    static TCHAR msv[30], ht[30], khoa[30], khoaa[30], monhoc[100];

    switch (message)
    {
    case WM_INITDIALOG:
        cboKhoa = GetDlgItem(hwndDialog, IDC_KHOA);
        cboKhoaa = GetDlgItem(hwndDialog, IDC_KHOAA);
        txtMSV = GetDlgItem(hwndDialog, IDC_MASV);
        txtHoten = GetDlgItem(hwndDialog, IDC_HOTEN);
        checkTin = GetDlgItem(hwndDialog, IDC_CHECK_TIN);
        checkTA = GetDlgItem(hwndDialog, IDC_CHECK_TA);
        checkGT = GetDlgItem(hwndDialog, IDC_CHECK_GT);
        checkTriet = GetDlgItem(hwndDialog, IDC_CHECK_TRIET);
        lstSV = GetDlgItem(hwndDialog, IDC_LIST_DSSV);
        btnXoa = GetDlgItem(hwndDialog, IDC_BUTTON_XOA);

        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("60"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("61"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("62"));
        SendMessage(cboKhoa, CB_INSERTSTRING, -1, (LPARAM)TEXT("63"));
        
        SendMessage(cboKhoaa, CB_INSERTSTRING, -1, (LPARAM)TEXT("Kinh te"));
        SendMessage(cboKhoaa, CB_INSERTSTRING, -1, (LPARAM)TEXT("Cong nghe"));
        SendMessage(cboKhoaa, CB_INSERTSTRING, -1, (LPARAM)TEXT("Xay dung"));
        SendMessage(cboKhoaa, CB_INSERTSTRING, -1, (LPARAM)TEXT("Giao thong"));
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_LIST_DSSV:
            lIndex = (int) SendMessage(lstSV, CB_GETCURSEL, 0, 0);
            if (lIndex >= 0) {
                EnableWindow(btnXoa, true);
            }
            break;
        case IDC_BUTTON_XOA:
            if (MessageBox(NULL, TEXT("Bạn có chắc muốn xóa không?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES) {
                SendMessage(lstSV, LB_DELETESTRING, lIndex, 0);
            }
            break;
        case IDC_BUTTON_DANGKY:
            TCHAR ketqua[255];
            lenMSV = GetWindowText(txtMSV, msv, 30);
            if (lenMSV == 0)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập MSV"), TEXT("Lỗi"), MB_OK);
                SetFocus(txtMSV);
                return 0;
            }
            if (lenMSV != 8)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập đúng 8 ký tự MSV"), TEXT("Lỗi"), MB_OK);
                SetFocus(txtMSV);
                return 0;
            }

            lenHT = GetWindowText(txtHoten, ht, 30);
            if (lenHT == 0)
            {
                MessageBox(NULL, TEXT("Bạn phải nhập họ tên"), TEXT("Lỗi"), MB_OK);
                SetFocus(txtHoten);
                return 0;
            }
            
            GetWindowText(txtMSV, msv, 30);
            GetWindowText(txtHoten, ht, 30);
            GetWindowText(cboKhoa, khoa, 30);
            GetWindowText(cboKhoaa, khoaa, 30);
            if (SendMessage(checkTin, BM_GETCHECK, 0, 0) == TRUE) {
                wsprintf(monhoc, L"%s | %s", monhoc, TEXT("Tin"));
                count++;
            }
            if (SendMessage(checkGT, BM_GETCHECK, 0, 0) == TRUE) {
                wsprintf(monhoc, L"%s | %s", monhoc, TEXT("Giai tich"));
                count++;
            }
            if (SendMessage(checkTA, BM_GETCHECK, 0, 0) == TRUE) {
                wsprintf(monhoc, L"%s | %s", monhoc, TEXT("Tieng anh"));
                count++;
            }
            if (SendMessage(checkTriet, BM_GETCHECK, 0, 0) == TRUE) {
                wsprintf(monhoc, L"%s | %s", monhoc, TEXT("Triet"));
                count++;
            }
            if (count < 2) {
                MessageBox(NULL, TEXT("Bạn phải chọn ít nhất 2 môn"), TEXT("Lỗi"), MB_OK);
                wsprintf(monhoc, L"%s", TEXT(""));
                return 0;
            }
            

            wsprintf(ketqua, L"%s|%s|%s|%s|%s", msv, ht, khoa, khoaa, monhoc);
            SendMessage(lstSV, LB_INSERTSTRING, -1, (LPARAM) ketqua);
            count = 0;
        case IDC_BUTTON_LAMLAI:
            SetWindowText(txtMSV, TEXT(""));
            SetWindowText(txtHoten, TEXT(""));
            SendMessage(checkGT, BM_SETCHECK, 0, 0);
            SendMessage(checkTA, BM_SETCHECK, 0, 0);
            SendMessage(checkTriet, BM_SETCHECK, 0, 0);
            SendMessage(checkTin, BM_SETCHECK, 0, 0);
            SendMessage(cboKhoa, CB_SETCURSEL, -1, 0);
            SendMessage(cboKhoaa, CB_SETCURSEL, -1, 0);
            break;
        case IDC_BUTTON_THOAT:
            if (MessageBox(NULL, TEXT("Bạn chắc chắn muốn thoát?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES) {
                DestroyWindow(hwndDialog);
            }
            break;
        default:
            break;
        }

        break;
    case WM_CLOSE:
        DestroyWindow(hwndDialog);
        break;
    default:
        break;
    }
    return false;
}
