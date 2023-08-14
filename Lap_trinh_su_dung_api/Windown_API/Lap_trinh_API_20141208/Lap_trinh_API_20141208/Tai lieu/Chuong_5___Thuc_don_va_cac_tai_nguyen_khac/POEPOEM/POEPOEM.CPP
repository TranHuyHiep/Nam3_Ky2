/*-------------------------------------------
   POEPOEM.C -- Demonstrates Custom Resource
                (c) Charles Petzold, 1998
  -------------------------------------------*/

#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

HINSTANCE hInst ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     TCHAR    szAppName [16], szCaption [64], szErrMsg [64] ;
     HWND     hwnd ;
     MSG      msg ;
     WNDCLASS wndclass ;
     
     hInst					= hInstance;
	 
	 LoadString (hInstance, IDS_APPNAME, szAppName, 
                            sizeof (szAppName) / sizeof (TCHAR)) ;

     LoadString (hInstance, IDS_CAPTION, szCaption, 
                            sizeof (szCaption) / sizeof (TCHAR)) ;
        
     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (hInstance, szAppName) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;
     
     if (!RegisterClass (&wndclass))
     {
          LoadStringA (hInstance, IDS_APPNAME, (char *) szAppName, 
                                  sizeof (szAppName)) ;

          LoadStringA (hInstance, IDS_ERRMSG, (char *) szErrMsg, 
                                  sizeof (szErrMsg)) ;


          MessageBoxA (NULL, (char *) szErrMsg, 
                             (char *) szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, szCaption,
                          WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     static char  * pText;
     static HGLOBAL hResource;
     static HWND    hScroll ;
     static int     iPosition, cxChar, cyChar, cyClient, iNumLines, xScroll ;

     HDC            hdc ;
     PAINTSTRUCT    ps ;
     RECT           rect ;
     TEXTMETRIC     tm ;

     switch (message)
     {
     case WM_CREATE :
          hdc = GetDC (hwnd) ;
          GetTextMetrics (hdc, &tm) ;
          cxChar = tm.tmAveCharWidth ;
          cyChar = tm.tmHeight + tm.tmExternalLeading ;
          ReleaseDC (hwnd, hdc) ;
          
          hResource = LoadResource (hInst, 
                      FindResource (hInst, TEXT ("ANNABELLEE"),
                                           TEXT ("MYTEXT"))) ;
          
          pText = (char *) LockResource (hResource) ;
          iNumLines = 0 ;
		  
		  //Calculate the number of lines
		  while (*pText != '\\' && *pText != '\0')
          {
               if (*pText == '\n')
                    iNumLines ++ ;
               pText = AnsiNext (pText) ;
			   //pText++;
          }
          *pText = '\0' ;

          return 0 ;
          
     case WM_SIZE :
          MoveWindow (hScroll, LOWORD (lParam) - xScroll, 0,
                      xScroll, cyClient = HIWORD (lParam), TRUE) ;
          SetFocus (hwnd) ;
          return 0 ;
          
     case WM_SETFOCUS :
          SetFocus (hScroll) ;
          return 0 ;
          
     case WM_PAINT :
          hdc = BeginPaint (hwnd, &ps) ;
               
          pText = (char *) LockResource (hResource) ;
               
          GetClientRect (hwnd, &rect) ;
          rect.left += cxChar ;
          rect.top  += cyChar * (1 - iPosition) ;
          DrawText (hdc, pText, -1, &rect, DT_EXTERNALLEADING) ;

          EndPaint (hwnd, &ps) ;
          return 0 ;
               
     case WM_DESTROY :
          FreeResource (hResource) ;
          PostQuitMessage (0) ;
          return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}

