// ------------------------------------------------------------------
//  Author: Martin Jasinski
//      TEST_PROJECT
//
// ------------------------------------------------------------------
// Assume Unicode
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif


#include "mj_header.h"

// ------------------------------------------------------------------
//  MAIN PROGRAM
// ------------------------------------------------------------------
int WINAPI WinMain (    HINSTANCE hThisInstance,
                        HINSTANCE hPrevInstance,
                        LPSTR lpszArgument,
                        int nCmdShow )
{
    /*  Make the class name into a global variable  */
    TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

    //HWND hWnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hMainWin = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Press Button to Show Webcam"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
        );

    HWND web_button = CreateWindow (
            "BUTTON",  // Predefined class; Unicode assumed
            "OK",      // Button text
            WS_VISIBLE | WS_CHILD,  // Styles
            10,         // x position
            10,         // y position
            100,        // Button width
            100,        // Button height
            hMainWin,     // Parent window
            (HMENU) ID_BUTTON,
            NULL,
            NULL
        );      // Pointer not needed.

    /* Make the window visible on the screen */
    ShowWindow (hMainWin, nCmdShow);


    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

// ------------------------------------------------------------------
//This function is called by the Windows function DispatchMessage()
// ------------------------------------------------------------------
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
        {
            if (LOWORD(wParam) == ID_BUTTON)
                // Open the Webcamera
                mj_Webcam(ON);
            break;
        }
        case WM_CLOSE:
        {
            DestroyWindow(hMainWin);
            break;
        }

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}


