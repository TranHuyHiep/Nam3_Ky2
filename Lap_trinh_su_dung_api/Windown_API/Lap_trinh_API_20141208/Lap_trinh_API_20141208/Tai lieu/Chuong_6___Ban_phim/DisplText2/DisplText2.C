/*----------------------------------------------------
   DisplText2.c -- Display text program No. 3
                 Luu Xuan Duan, 2009
  ----------------------------------------------------*/

#include <windows.h>
#include "DisplText2.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szAppName[] = TEXT ("SysMets2") ;
     HWND         hwnd ;
     MSG          msg ;
     WNDCLASS     wndclass ;

     wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))  
     {
          MessageBox (NULL, TEXT ("This program requires Windows NT!"), 
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }

     hwnd = CreateWindow (szAppName, TEXT ("Get System Metrics No. 2"),
                          WS_OVERLAPPEDWINDOW | WS_VSCROLL,
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
     static int  cxChar, cxCaps, cyChar, cyClient, iVscrollPos=0 ;
	 BOOL flgFirstUse = TRUE;
     HDC         hdc ;
     int         i, y ;
     PAINTSTRUCT ps ;
     TCHAR       szBuffer[10] ;
     TEXTMETRIC  tm ;
	 INT max, min;

     switch (message)
     {
     case WM_CREATE:
          hdc = GetDC (hwnd) ;

          GetTextMetrics (hdc, &tm) ;
          cxChar = tm.tmAveCharWidth ;
          cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2 ;
          cyChar = tm.tmHeight + tm.tmExternalLeading ;

          ReleaseDC (hwnd, hdc) ;
		//	SetScrollRange (hwnd, SB_VERT, 0, NUMLINES - 1, FALSE) ;
          //iVscrollPos = 0;
		  //SetScrollPos   (hwnd, SB_VERT, iVscrollPos, TRUE) ;
          
          return 0 ;

     case WM_SIZE:
          cyClient = HIWORD (lParam) ;
			
		  /*if (flgFirstUse) {
				iVscrollPos		= 0;
				flgFirstUse		= FALSE;
		  }
			else {
			   GetScrollRange(hwnd, SB_VERT, &min, &max);
				iVscrollPos *= (NUMLINES - 1 - cyClient / cyChar) / max;
			}*/
		  SetScrollRange (hwnd, SB_VERT, 0, NUMLINES - 1 - cyClient / cyChar, TRUE) ;
		   //iVscrollPos = max (0, min( iVscrollPos, NUMLINES - 1 - cyClient / cyChar));
		  iVscrollPos = 0;
          SetScrollPos   (hwnd, SB_VERT, iVscrollPos, TRUE) ;
		  InvalidateRect (hwnd, NULL, TRUE) ;
          return 0 ;

     case WM_VSCROLL:
          switch (LOWORD (wParam))
          {
          case SB_LINEUP:
               iVscrollPos -= 1 ;
               break ;
     
          case SB_LINEDOWN:
               iVscrollPos += 1 ;
               break ;
     
          case SB_PAGEUP:
               iVscrollPos -= cyClient / cyChar ;
               break ;
     
          case SB_PAGEDOWN:
               iVscrollPos += cyClient / cyChar ;
               break ;
     
          case SB_THUMBPOSITION:
               iVscrollPos = HIWORD (wParam) ;

				//SetScrollRange (hwnd, SB_VERT, 0, NUMLINES / 2, TRUE) ;		


               break ;
     
          default :
               break ;
          }

          iVscrollPos = max (0, min (iVscrollPos, NUMLINES - 1 - cyClient / cyChar)) ;

          if (iVscrollPos != GetScrollPos (hwnd, SB_VERT))
          {
               SetScrollPos (hwnd, SB_VERT, iVscrollPos, TRUE) ;
               InvalidateRect (hwnd, NULL, TRUE) ;
          }
          return 0 ;
	 case WM_KEYDOWN:
          switch (wParam)
          {
          case VK_HOME:
               SendMessage (hwnd, WM_VSCROLL, SB_TOP, 0) ;
               break ;
               
          case VK_END:
               SendMessage (hwnd, WM_VSCROLL, SB_BOTTOM, 0) ;
               break ;
               
          case VK_PRIOR:
               SendMessage (hwnd, WM_VSCROLL, SB_PAGEUP, 0) ;
               break ;
               
          case VK_NEXT:
               SendMessage (hwnd, WM_VSCROLL, SB_PAGEDOWN, 0) ;
               break ;
               
          case VK_UP:
               SendMessage (hwnd, WM_VSCROLL, SB_LINEUP, 0) ;
               break ;

          case VK_DOWN:
               SendMessage (hwnd, WM_VSCROLL, SB_LINEDOWN, 0) ;
               break ;
          }
          return 0 ;

     case WM_PAINT:
          hdc = BeginPaint (hwnd, &ps) ;
     
          for (i = 0 ; i < NUMLINES ; i++)
          {
               y = cyChar * (i - iVscrollPos) ;
     
               TextOut (hdc, 10, y + 20,
                        lyric[i],
                        lstrlen (lyric[i])) ;
 
          }
          EndPaint (hwnd, &ps) ;
          return 0 ;

     case WM_DESTROY:
          PostQuitMessage (0) ;
          return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}

