// main.cpp ???????

#ifndef _MAIN_H_
#define _MAIN_H_

#include "version.h"

//---------------------------------------------------------------------------//
// ?? ��????define)�L?                                                //
//---------------------------------------------------------------------------//
#define DEF_APPNAME		"�ӣ���������"				//???????���q
#ifdef _NEW_RESOMODE
#define DEF_APPSIZEX	800 	 						//?��??WINDOWS???
#define DEF_APPSIZEY	600								//?��??WINDOWS?��?
//#define DEF_APPSIZEX	1024	 						//?��??WINDOWS???
//#define DEF_APPSIZEY	768								//?��??WINDOWS?��?
#else
#define DEF_APPSIZEX	640							//?��??WINDOWS???
#define DEF_APPSIZEY	480								//?��??WINDOWS?��?
#endif
//#define DEF_APPSIZEX	320								//?��??WINDOWS???
//#define DEF_APPSIZEY	240								//?��??WINDOWS?��?

#define SCREEN_WIDTH_CENTER			DEF_APPSIZEX/2
#define SCREEN_HEIGHT_CENTER		DEF_APPSIZEY/2

//---------------------------------------------------------------------------//
// ?? ��????????�L?                                               //
//---------------------------------------------------------------------------//

//int PASCAL WinMain( HINSTANCE 		hInstance, 	HINSTANCE 		hPrevInstance, 	LPSTR lpCmdLine, 	int nCmdShow );	// ?????

//long CALLBACK PASCAL WindMsgProc( HWND hWnd, unsigned int message, WPARAM wParam, LPARAM lParam );				//??????????
bool SystemTask( void );																		// ??????????

// ?????��?
//extern HWND hWnd;		// ?????????
extern bool WindowMode;		// ????????
extern int ResoMode;
extern int LowResoCmdFlag;		// ??�T��????????
extern int	CmdShow;	// WinMain??????????????
//extern LPSTR CmdLine; 	// WinMain?????????????????????
//extern HANDLE hMutex;	// �i??�h???????????????

extern char realBinName[];
extern char adrnBinName[];
extern char sprBinName[];
extern char sprAdrnBinName[];
#ifdef _READ16BITBMP
extern char realtrueBinName[];
extern char adrntrueBinName[];
#endif
//add jeffrey
extern struct gameserver gmsv[];
extern struct gamegroup  gmgroup[];
//end


#ifdef _DEBUG
extern bool offlineFlag;
extern char DebugKey0[ 256 ];		
extern char DebugKey1[ 256 ];		
extern char DebugKey2[ 256 ];		
#endif

#endif

