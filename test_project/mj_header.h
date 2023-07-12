// ------------------------------------------------------------------
//  Author: Martin Jasinski
//      mj_Main.h
//
// ------------------------------------------------------------------
#ifndef MJ_MAIN_H_INCLUDED
#define MJ_MAIN_H_INCLUDED

// ------------------------------------------------------------------
//  INCLUDES
// ------------------------------------------------------------------
#include <iostream>

#include <tchar.h>
#include <windows.h>
#include <winuser.h>


#include <stdio.h>
#include "wincon.h"     //Console functions

#include "mj_lib.h"

// ------------------------------------------------------------------
//  GLOBAL VARIABLES
// ------------------------------------------------------------------
//Handle to the Main window
HWND hMainWin = NULL;

// ------------------------------------------------------------------
//  FUNCTION PROTOTYPES
// ------------------------------------------------------------------
void mj_Webcam(int);

//Declare Windows procedure
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

#endif // MJ_MAIN_H_INCLUDED
// ------------------------------------------------------------------
//  END
// ------------------------------------------------------------------
