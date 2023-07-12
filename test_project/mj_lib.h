// ------------------------------------------------------------------
//  Author: Martin Jasinski
//      mj_Lib.h
//
// ------------------------------------------------------------------
#ifndef MJ_LIB_H_INCLUDED
#define MJ_LIB_H_INCLUDED


// ------------------------------------------------------------------
//  DEFINE
// ------------------------------------------------------------------
#define ID_BUTTON 1201

#define ON 1
#define OFF 0


// ------------------------------------------------------------------
//  INCLUDE
// ------------------------------------------------------------------
#include <tchar.h>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>

#include <opencv2\highgui\highgui.hpp> // OPENCV2
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;
// ------------------------------------------------------------------
//  FUNCTIONS
// ------------------------------------------------------------------

LRESULT CALLBACK wj_WindowProc ( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



#endif // MJ_LIB_H_INCLUDED
// ------------------------------------------------------------------
//  END
// ------------------------------------------------------------------
