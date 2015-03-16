//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		Multimedia Fusion: edit text object																					//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Indicates we are in the COXSDK folder
#define COXSDK

// General CCX includes
#include	"ccxhdr.h"
#include	"ccx.h"

// Specific to this kcx
#include	<commdlg.h>
#include	<assert.h>
#include	"ext.h"
#include	"props.h"
#include	"extrc.h"
//#include "..\..\hlp\cnc2hlpobj.hm"


// Instance of kcx
HINSTANCE	hInstLib;


// Data for object
char	szNullString[] = "";
#define	IDENTIFIER			0x457A3030			// "EZ00"

// Compatibility avec version MMF
#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MMF_BUILD_DEMO && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20)


// Name of Prop that contains rdPtr
char		prop_ad[] =		"krdp";


// Function prototypes
short WINAPI  DisplayRunObject(fprdata rdPtr);
LRESULT CALLBACK NewEditProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Definitions of parameters for each condition
infosEvents	conditionsInfos[]=
		{
		{CND_VISIBLE,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_ENABLE,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_CANUNDO,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_MODIFIED,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_HAVEFOCUS,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_ISSELECTED,	EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		{CND_ISNUMBER,		EVFLAGS_ALWAYS+EVFLAGS_NOTABLE,	0,				0,					0,				0},
		};

// Definitions of parameters for each action
infosEvents	actionsInfos[]=
		{
		{ACT_LOADTEXT,			0,		PARAM_FILENAME,			0,					M_TEXTTITLE,	M_TEXTFILTER},
		{ACT_LOADTEXTSELECT,	0,		0,						0,					0,  			0},
		{ACT_SAVETEXT,			0,		PARAM_FILENAME,			0,					M_TEXTTITLE, 	M_TEXTFILTER},
		{ACT_SAVETEXTSELECT,	0,		0,						0,					0,  			0},
		{ACT_SETTEXT,			0,		PARAM_EXPSTRING,		0,					0,			 	0},
		{ACT_REPLACESELECTION,	0,		PARAM_EXPSTRING,		0,					0,			 	0},
		{ACT_CUT,				0,		0,						0,					0,  			0},
		{ACT_COPY,				0,		0,						0,					0,  			0},
		{ACT_PASTE,				0,		0,						0,					0,  			0},
		{ACT_CLEAR,				0,		0,						0,					0,  			0},
		{ACT_UNDO,				0,		0,						0,					0,  			0},
		{ACT_CLEARUNDOBUFFER,	0,		0,						0,					0,  			0},
		{ACT_SHOW,				0,		0,						0,					0,  			0},
		{ACT_HIDE,				0,		0,						0,					0,  			0},
		{ACT_SETFONTSELECT,		0,		0,						0,					0,  			0},
		{ACT_SETCOLORSELECT,	0,		0,						0,					0,  			0},
		{ACT_ACTIVATE,			0,		0,						0,					0,  			0},
		{ACT_ENABLE,			0,		0,						0,					0,  			0},
		{ACT_DISABLE,			0,		0,						0,					0,  			0},
		{ACT_READONLYON,		0,		0,						0,					0,  			0},
		{ACT_READONLYOFF,		0,		0,						0,					0,  			0},
		{ACT_TEXTMODIFIED,		0,		0,						0,					0,  			0},
		{ACT_TEXTNOTMODIFIED,	0,		0,						0,					0,  			0},
		{ACT_LIMITTEXTSIZE,		0,		PARAM_EXPRESSION,		0,					0,  			0},
		{ACT_SETPOSITION,		0,		PARAM_POSITION,			0,					0,  			0},
		{ACT_SETXPOSITION,		0,		PARAM_EXPRESSION,		0,					0,  			0},
		{ACT_SETYPOSITION,		0,		PARAM_EXPRESSION,		0,					0,  			0},
		{ACT_SETSIZE,			0,		PARAM_EXPRESSION,		PARAM_EXPRESSION,	0,  			0},
		{ACT_SETXSIZE,			0,		PARAM_EXPRESSION,		0,					0,  			0},
		{ACT_SETYSIZE,			0,		PARAM_EXPRESSION,		0,					0,  			0},
		{ACT_DESACTIVATE,		0,		0,						0,					0,  			0},
		{ACT_SCROLLTOTOP,		0,		0,						0,					0,  			0},
		{ACT_SCROLLTOLINE,		0,		PARAM_EXPRESSION,		0,					IDS_ENTERLINE,  			0},
		{ACT_SCROLLTOEND,		0,		0,						0,					0,  			0},
		{ACT_SETCOLOR,			0,		PARAM_COLOUR,			0,					0,  			0},
		{ACT_SETBKDCOLOR,		0,		PARAM_COLOUR,			0,					0,  			0},
		};

// Definitions of parameters for each expression
infosEvents	expressionsInfos[]=
		{
		{EXP_GETTEXT,		0,		0,						0,					0,				0},
		{EXP_GETSELECTION,	0,		0,						0,					0,				0},
		{EXP_GETVALUE,		0,		0,						0,					0,				0},
		{EXP_GETXPOSITION,	0,		0,						0,					0,				0},
		{EXP_GETYPOSITION,	0,		0,						0,					0,				0},
		{EXP_GETXSIZE,		0,		0,						0,					0,				0},
		{EXP_GETYSIZE,		0,		0,						0,					0,				0},
		{EXP_GETFIRSTLINE,	0,		0,						0,					0,				0},
		{EXP_GETLINECOUNT,	0,		0,						0,					0,				0},
		{EXP_GETCOLOR,		0,		0,						0,					0,				0},
		{EXP_GETBKDCOLOR,	0,		0,						0,					0,				0},
		};

#ifndef RUN_ONLY

// PROPERTIES /////////////////////////////////////////////////////////////////
enum {
	PROPID_SETTINGS = PROPID_EXTITEM_CUSTOM_FIRST,
	PROPID_MULTILINE,
	PROPID_TABSTOP,
	PROPID_PASSWORD,
	PROPID_SYSTEMCOLORS,
	PROPID_TRANSPARENT, 
	PROPID_BORDER, 
	PROPID_HIDEONSTART, 
	PROPID_READONLY,
	PROPID_3DLOOK,
	PROPID_GENERAL,
	PROPID_SCROLLING,
	PROPID_HSCROLLBAR, 
	PROPID_HAUTOSCROLL,
	PROPID_VSCROLLBAR, 
	PROPID_VAUTOSCROLL,
	PROPID_MISC,
	PROPID_CASE,
	PROPID_BACKGROUND
};

LPCSTR CaseList[] = {
	(LPCSTR)0,								// Reserved
	MAKEINTRESOURCE(IDS_CASE_NONE),	
	MAKEINTRESOURCE(IDS_CASE_UPPERCASE),	
	MAKEINTRESOURCE(IDS_CASE_LOWERCASE),	
	NULL
};


// Properties
PropData Properties[] = {
//	PropData_Folder(PROPID_SETTINGS, IDS_PROP_SETTINGS, IDS_PROP_SETTINGS_INFO),

		PropData_Group(PROPID_GENERAL, IDS_PROP_GENERAL, IDS_PROP_GENERAL),
		PropData_CheckBox(PROPID_MULTILINE, IDS_PROP_MULTILINE, IDS_PROP_MULTILINE_INFO),
		PropData_CheckBox(PROPID_TABSTOP, IDS_PROP_TABSTOP, IDS_PROP_TABSTOP_INFO),
		PropData_CheckBox(PROPID_PASSWORD, IDS_PROP_PASSWORD, IDS_PROP_PASSWORD_INFO),
		PropData_CheckBox(PROPID_SYSTEMCOLORS, IDS_PROP_SYSTEMCOLORS, IDS_PROP_SYSTEMCOLORS_INFO),
		PropData_CheckBox(PROPID_TRANSPARENT, IDS_PROP_TRANSPARENT, IDS_PROP_TRANSPARENT_INFO),
		PropData_CheckBox(PROPID_BORDER, IDS_PROP_BORDER, IDS_PROP_BORDER_INFO),
		PropData_CheckBox(PROPID_HIDEONSTART, IDS_PROP_HIDEONSTART, IDS_PROP_HIDEONSTART_INFO),
		PropData_CheckBox(PROPID_READONLY, IDS_PROP_READONLY, IDS_PROP_READONLY_INFO),
		PropData_CheckBox(PROPID_3DLOOK, IDS_PROP_3DLOOK, IDS_PROP_3DLOOK_INFO),

		PropData_Group(PROPID_SCROLLING, IDS_PROP_SCROLLING, IDS_PROP_SCROLLING),
		PropData_CheckBox(PROPID_HSCROLLBAR, IDS_PROP_HSCROLLBAR, IDS_PROP_HSCROLLBAR_INFO),
		PropData_CheckBox(PROPID_HAUTOSCROLL, IDS_PROP_HAUTOSCROLL, IDS_PROP_HAUTOSCROLL_INFO),
		PropData_CheckBox(PROPID_VSCROLLBAR, IDS_PROP_VSCROLLBAR, IDS_PROP_VSCROLLBAR_INFO),
		PropData_CheckBox(PROPID_VAUTOSCROLL, IDS_PROP_VAUTOSCROLL, IDS_PROP_VAUTOSCROLL_INFO),

		PropData_Group(PROPID_MISC, IDS_PROP_MISC, IDS_PROP_MISC),
		PropData_ComboBox(PROPID_CASE, IDS_PROP_CASE, IDS_PROP_CASE_INFO, CaseList),
		PropData_Color(PROPID_BACKGROUND, IDS_PROP_BACKGROUND, IDS_PROP_BACKGROUND_INFO),
//	PropData_Folder_End(),
	PropData_End()
};

WORD DbTree[]=
{
	DB_STRING|DB_EDITABLE,
	DB_END
};

#endif // RUN_ONLY



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ChooseFont16																			//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL ChooseFont16(CHOOSEFONT _far * cfPtr)
{
	BOOL				ret;
	LOGFONT				lf;
	LOGFONT16 _far *	lfPtr;

	lfPtr=(LOGFONT16 _far *)cfPtr->lpLogFont;
	LogFont16To32(&lf, lfPtr);
	cfPtr->lpLogFont = &lf;
	ret=ChooseFont(cfPtr);
	LogFont32To16(lfPtr, &lf);
	cfPtr->lpLogFont = (LOGFONT _far *)lfPtr;
	return ret;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		OBJECT HANDLING ROUTINES WHEN GAME IS RUNNED																		//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetRdPtr																				//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////
fprdata GetRdPtr(HWND hwnd, fprh rhPtr)
{
	return (fprdata)GetProp(hwnd, (LPCSTR)rhPtr->rh4.rh4AtomRd);
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetRunObjectDataSize																	//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

ushort WINAPI  GetRunObjectDataSize(fprh rhPtr, fpedata edPtr)
{
	// Debug assertion
    assert(rhPtr != NULL);
    assert(edPtr != NULL);

	// Return the size of the run data structure
	return (sizeof(runData));
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		CreateRunObject									    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  CreateRunObject(fprdata rdPtr, fpedata edPtr, fpcob cobPtr)
{            
    fprh						rhPtr;
    DWORD						dwStyle, dwStyleEx;
    int							a;
    WORD						wTabSpacing=0;
	RECT				editWinRect;
    
	// Debug assertion
    assert(rdPtr != NULL);
    assert(edPtr != NULL);
    assert(cobPtr != NULL);
    
	// To get rhPtr
    rhPtr = rdPtr->rHo.hoAdRunHeader;
	WinGetLogRect(rhPtr->rhIdEditWin, &editWinRect);
	rdPtr->InitEditWinWidth=editWinRect.right;
	rdPtr->InitEditWinHeight=editWinRect.bottom;

	// Get parameters
	rdPtr->rHo.hoImgWidth = edPtr->sSizeX;
	rdPtr->rHo.hoImgHeight = edPtr->sSizeY;
	memcpy(&rdPtr->lfEditFont, &edPtr->lfEditFont, sizeof(LOGFONT16));
	rdPtr->crefEditFontColor = edPtr->crefEditFontColor;
	rdPtr->crefEditFontBkColor = edPtr->crefEditFontBkColor;
	strcpy(edPtr->szEditFontStyle, rdPtr->szEditFontStyle);
	rdPtr->lFlags = edPtr->lFlags;
	
	// Set parameters
	for (a = 0; a < 16; a++)
		rdPtr->crefCustColor[a] = RGB(255, 255, 255);
	rdPtr->sEnable = 1;

	// Compute style
	if ((edPtr->lFlags & EDIT_TABSTOP) != 0)
		rdPtr->rHo.hoOEFlags|=OEFLAG_TABSTOP;
	else
		rdPtr->rHo.hoOEFlags&=~OEFLAG_TABSTOP;
		
	dwStyle = WS_CHILDWINDOW;	// | WS_CLIPSIBLINGS;
	if ((edPtr->lFlags & EDIT_HSCROLLBAR) != 0)
		dwStyle |= WS_HSCROLL;
	if ((edPtr->lFlags & EDIT_HSCROLLAUTOSCROLL) != 0)
		dwStyle |= ES_AUTOHSCROLL;
	if ((edPtr->lFlags & EDIT_VSCROLLBAR) != 0)
		dwStyle |= WS_VSCROLL;
	if ((edPtr->lFlags & EDIT_VSCROLLAUTOSCROLL) != 0)
		dwStyle |= ES_AUTOVSCROLL;
	if ((edPtr->lFlags & EDIT_READONLY) != 0)
		dwStyle |= ES_READONLY;
	if ((edPtr->lFlags & EDIT_MULTILINE) != 0)
		dwStyle |= ES_MULTILINE;
	if ((edPtr->lFlags & EDIT_PASSWORD) != 0)
		dwStyle |= ES_PASSWORD;
	if ((edPtr->lFlags & EDIT_BORDER) != 0)
		dwStyle |= WS_BORDER;
	if ((edPtr->lFlags & EDIT_UPPERCASE) != 0)
		dwStyle |= ES_UPPERCASE;
	if ((edPtr->lFlags & EDIT_LOWERCASE) != 0)
		dwStyle |= ES_LOWERCASE;

	dwStyleEx = 0;
	if ((edPtr->lFlags & EDIT_3DLOOK) != 0)
		dwStyleEx |= WS_EX_CLIENTEDGE;
//	if ((edPtr->lFlags & EDIT_TRANSP) != 0)
//		dwStyleEx |= WS_EX_TRANSPARENT;
	
	// Create window
	rdPtr->hWnd = CreateWindowEx(dwStyleEx, "EDIT", NULL, dwStyle, rdPtr->rHo.hoX - rhPtr->rhWindowX, rdPtr->rHo.hoY - rhPtr->rhWindowY, rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, rhPtr->rhHEditWin, NULL, rhPtr->rh4.rh4Instance, NULL);
	if (0 == (edPtr->lFlags & EDIT_HIDEONSTART))
	{
		rdPtr->sVisible = 1;
//		DisplayRunObject(rdPtr);
//		ShowWindow(rdPtr->hWnd,SW_SHOW);
		rdPtr->lFlags |= EDIT_JUSTCREATED;
	}
	else
		rdPtr->sVisible = 0;

	if (rdPtr->hWnd != NULL)
	{
		// Branch C&C structures
		rdPtr->numOfWindows=1;
		rdPtr->rHo.hoOffsetToWindows=(short)((fpchar)&rdPtr->numOfWindows-(fpchar)rdPtr);
		callRunTimeFunction(rdPtr, RFUNCTION_SUBCLASSWINDOW, 0, 0);
		
		// Create & set font
        rdPtr->hFont = CreateFontIndirect16(&rdPtr->lfEditFont);
		SendMessage(rdPtr->hWnd, WM_SETFONT, (WPARAM)rdPtr->hFont, MAKELONG(TRUE, 0));

		// Create brush
		rdPtr->hBrush = NULL;
		if ( (rdPtr->lFlags & (EDIT_SYSCOLOR | EDIT_TRANSP)) == 0 )
			rdPtr->hBrush = CreateSolidBrush(rdPtr->crefEditFontBkColor);

		// Subclass control
		rdPtr->lpfnOldComboProc = NULL;
		if ((edPtr->lFlags & (EDIT_TABSTOP | EDIT_TRANSP)) != 0 ||
			(edPtr->lFlags & EDIT_MULTILINE) == 0 )
			rdPtr->lpfnOldComboProc = (WNDPROC)SetWindowLong(rdPtr->hWnd, GWL_WNDPROC, (LONG)NewEditProc);

		// Transparent? must remove the CLIPCHILDREN style of the parent window
		if ( (edPtr->lFlags & EDIT_TRANSP) != 0 )
		{
//			rdPtr->dwOldEditWinStyle = GetWindowLong (rhPtr->rhHEditWin, GWL_STYLE);
//			SetWindowLong (rhPtr->rhHEditWin, GWL_STYLE, rdPtr->dwOldEditWinStyle & (~WS_CLIPCHILDREN));
			InvalidateRect( rdPtr->hWnd, NULL, TRUE );
		}
	}

	// Ok
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		DestroyRunObject								    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  DestroyRunObject(fprdata rdPtr, long fast)
{
    fprh rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Destroy
	if (rdPtr->hWnd != NULL)
	{
		// Transparent? restore the style of the parent window
//		if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
//			SetWindowLong (rhPtr->rhHEditWin, GWL_STYLE, rdPtr->dwOldEditWinStyle);

		if ( rdPtr->lpfnOldComboProc != NULL )
			SetWindowLong(rdPtr->hWnd, GWL_WNDPROC, (LONG)rdPtr->lpfnOldComboProc);
		DestroyWindow(rdPtr->hWnd);
	}
	
	// Destroy font
	if (rdPtr->hFont != NULL)
		DeleteObject(rdPtr->hFont);

	// Destroy brush
	if (rdPtr->hBrush != NULL)
		DeleteObject(rdPtr->hBrush);

	// Free memory
	if (rdPtr->hglb != NULL)
	{
		GlobalUnlock(rdPtr->hglb);
		GlobalFree(rdPtr->hglb);
		rdPtr->hglb = NULL;
	}

	// OK
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		HandleRunObject									    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  HandleRunObject(fprdata rdPtr)
{    
   	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		DisplayRunObject								    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  DisplayRunObject(fprdata rdPtr)
{
    fprh rhPtr;
	int trueX;
	int trueY;
	int trueWidth;
	int trueHeight;
	float ratioX;
	float ratioY;
	RECT editWinRect;
	RECT rc;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
    
    rhPtr = rdPtr->rHo.hoAdRunHeader;
	GetClientRect(rhPtr->rhHEditWin,&editWinRect);
	if ((rhPtr->rhApp->m_hdr.gaFlags & GA_STRETCH)!=0 && 
		((rdPtr->InitEditWinWidth!=editWinRect.right) || (rdPtr->InitEditWinHeight!=editWinRect.bottom)))
	{
		ratioX=((float)editWinRect.right)/((float)rdPtr->InitEditWinWidth);
		ratioY=((float)editWinRect.bottom)/((float)rdPtr->InitEditWinHeight);
		trueX=(int)(ratioX*((float)(rdPtr->rHo.hoX - rhPtr->rhWindowX)));
		trueY=(int)(ratioY*((float)(rdPtr->rHo.hoY - rhPtr->rhWindowY)));
		trueWidth=(int)(ratioX*((float)rdPtr->rHo.hoImgWidth));
		trueHeight=(int)(ratioY*((float)rdPtr->rHo.hoImgHeight));
	}
	else
	{
		trueX=(rdPtr->rHo.hoX - rhPtr->rhWindowX);
		trueY=(rdPtr->rHo.hoY - rhPtr->rhWindowY);
		trueWidth=rdPtr->rHo.hoImgWidth;
		trueHeight=rdPtr->rHo.hoImgHeight;
	}
	GetWindowRect(rdPtr->hWnd, &rc);
	MapWindowPoints(NULL, GetParent(rdPtr->hWnd), (LPPOINT)&rc, 2);
	if ( rc.left != trueX || rc.top != trueY || (rc.right-rc.left) != trueWidth || (rc.bottom-rc.top) != trueHeight )
		SetWindowPos(rdPtr->hWnd, 0, trueX, trueY, trueWidth, trueHeight, SWP_NOZORDER);

	if ( rdPtr->lFlags & EDIT_JUSTCREATED )
	{
		WORD w;

		rdPtr->lFlags &= ~EDIT_JUSTCREATED;
		w = WinGetFlags (rhPtr->rhIdEditWin);
		WinSetFlags (rhPtr->rhIdEditWin, (WORD)(w | WF_NOPAINT));
		ShowWindow(rdPtr->hWnd, SW_SHOW);
		UpdateWindow (rdPtr->hWnd);
		if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
			InvalidateRect(rdPtr->hWnd, NULL, TRUE);
		WinSetFlags (rhPtr->rhIdEditWin, w);
	}

	// Ok
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ReInitRunObject									   				 						//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ReInitRunObject(fprdata rdPtr)
{
	// Debug assertion
    assert(rdPtr != NULL);

	// Ok
	return 0;
}
                   





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		PauseRunObject									  				  						//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  PauseRunObject(fprdata rdPtr)
{
	// Debug assertion
    assert(rdPtr != NULL);

	// Ok
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ContinueRunObject											    						//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ContinueRunObject(fprdata rdPtr)
{
	// Debug assertion
    assert(rdPtr != NULL);

	// Ok
	return 0;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		HANDLING																											//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ChangeRunData																			//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ChangeRunData(fprdata rdOld, fprdata rdNew)
{            
	// Debug assertion
    assert(rdOld != NULL);
    assert(rdNew != NULL);
	return 0; 
}



fprdata GetRdPtrEdit(HWND hwnd)
{
	ATOM atm = GlobalFindAtom(prop_ad);
	return (fprdata) GetProp (hwnd, (LPCSTR)atm);
}



// Edit subclass proc.
LRESULT CALLBACK NewEditProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	fprdata	rdPtr = GetRdPtrEdit(hWnd);
	if ( rdPtr == NULL || IDENTIFIER != rdPtr->rHo.hoIdentifier )
		return 0L;

	switch (message) {

	// Ne pas envoyer le message WM_CHAR au contrôle s'il a le style TABSTOP
	case WM_CHAR:
		if ( wParam == VK_TAB && (rdPtr->lFlags & EDIT_TABSTOP) != 0 )
			return 0L;
		if ( wParam == VK_RETURN && (rdPtr->lFlags & EDIT_MULTILINE) == 0 )
			return 0L;
//		if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
//			InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_ERASEBKGND:
		if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
		{
			fprh rhPtr = rdPtr->rHo.hoAdRunHeader;
			if ( rhPtr != NULL )
			{
//				int xLog = rdPtr->rHo.hoX - rhPtr->rhWindowX;
//				int yLog = rdPtr->rHo.hoY - rhPtr->rhWindowY;
//				int lg = rdPtr->rHo.hoImgWidth;
//				int ht = rdPtr->rHo.hoImgHeight;
				HDC hdcLog;

				npWin idEditWin = NULL;
				HWND hEditWin = GetParent(hWnd);
				if ( rhPtr->rh4.rh4Mv != NULL && hEditWin == rhPtr->rh4.rh4Mv->mvHEditWin )
					idEditWin = rhPtr->rh4.rh4Mv->mvIdEditWin;
//				else
//					idEditWin = WinSearch(hEditWin);
				if ( idEditWin == NULL )
					break;

				if ( (hdcLog = WinGetHDCLog (idEditWin)) != NULL )
				{
					HDC hdc = (HDC)wParam;	//GetDC(hWnd);
					if ( hdc != NULL )
					{
						RECT rc;
						HPALETTE hop2 = NULL;
						if ( rhPtr->rh4.rh4Mv != NULL && rhPtr->rh4.rh4Mv->mvScrMode == SM_8 && rhPtr->rh4.rh4Mv->mvHPal256 != 0 )
						{
							hop2 = SelectPalette (hdc, rhPtr->rh4.rh4Mv->mvHPal256, 1);
							RealizePalette (hdc);
						}

//						BitBlt (hdc, 0, 0, lg, ht, hdcLog, xLog, yLog, SRCCOPY);

						GetClientRect(hWnd, &rc);
						MapWindowPoints(hWnd, hEditWin, (LPPOINT)&rc, 2);
						BitBlt (hdc, 0, 0, rc.right-rc.left, rc.bottom-rc.top, hdcLog, rc.left, rc.top, SRCCOPY);

						if ( hop2 )
							SelectPalette (hdc, hop2, 1);
						//ReleaseDC(hWnd, hdc);
					}
					WinReleaseHDCLog (idEditWin, hdcLog);
				}
				return 1;
			}
/*
			HRGN hRgn;
			HRGN hRgnOld;
			POINT  pt;
			HWND hWndParent = GetParent(hWnd);
			pt.x = 0;
			pt.y = 0;

			MapWindowPoints(hWnd, hWndParent, &pt, 1);
			OffsetWindowOrgEx((HDC)wParam, pt.x, pt.y, &pt);
//			SelectClipRgn((HDC)wParam, NULL);
			SendMessage(hWndParent, WM_ERASEBKGND, wParam, 0);
			SetWindowOrgEx((HDC)wParam, pt.x, pt.y, NULL);

			return TRUE; */
		}
		break;
	}

   // Call original combo box procedure to handle other combo messages.
   return CallWindowProc (rdPtr->lpfnOldComboProc, hWnd, message, wParam, lParam);
} 




//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		WindowProc    																			//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

LRESULT CALLBACK  WindowProc(fprh rhPtr, HWND hWnd, UINT msgType, WPARAM wParam, LPARAM lParam)
{
	fprdata					rdPtr;

	// If pause, out
//	if (rhPtr->rh2.rh2PauseCompteur != 0)
//		return 0;

	// It's for me ?
	switch (msgType)
	{
		case WM_CTLCOLOREDIT:
		case WM_CTLCOLORSTATIC:
			// It's for me ???
			if ((rdPtr = GetRdPtr((HWND)lParam, rhPtr)) != NULL && rdPtr->rHo.hoIdentifier==IDENTIFIER)
			{
				if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
				{
					SetBkMode( (HDC) wParam, TRANSPARENT );
					if ( (rdPtr->lFlags & EDIT_SYSCOLOR) == 0 )
						SetTextColor((HDC)wParam, rdPtr->crefEditFontColor);
					rhPtr->rh4.rh4KpxReturn = (long)GetStockObject( NULL_BRUSH );
					return REFLAG_MSGRETURNVALUE;
				}

				if ( (rdPtr->lFlags & EDIT_SYSCOLOR) == 0 )
				{
					SetTextColor((HDC)wParam, rdPtr->crefEditFontColor);
					SetBkMode((HDC)wParam, OPAQUE);
					SetBkColor((HDC)wParam, rdPtr->crefEditFontBkColor);
					rhPtr->rh4.rh4KpxReturn = (long)rdPtr->hBrush;
					return REFLAG_MSGRETURNVALUE;
				}
			}
			break;

		case WM_COMMAND:
			if ( EN_UPDATE == wmCommandNotif )
			{
				if ((rdPtr = GetRdPtr((HWND)lParam, rhPtr)) != NULL && rdPtr->rHo.hoIdentifier==IDENTIFIER)
				{
					if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 && wmCommandHCtl == rdPtr->hWnd )
					{
						InvalidateRect( rdPtr->hWnd, NULL, TRUE );
					}
				}
			}
			break;

		default:
			break;
	}

	// Sniff, Not for me ...
	return 0;

	// 0-> nothing done, should continue
	// REFLAG_MSGCATCHED-> message dispatch should go on to other objects 
	// REFLAG_MSGHANDLED-> message dispatch should stop
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		TEXT ROUTINES																										//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI GetRunObjectFont(fprdata rdPtr, LOGFONT* pLf)
{
	LogFont16To32(pLf, &rdPtr->lfEditFont);
}
void WINAPI SetRunObjectFont(fprdata rdPtr, LOGFONT* pLf, RECT* pRc)
{
	HFONT hFont = CreateFontIndirect(pLf);
	if (hFont!=0)
	{
		LogFont32To16(&rdPtr->lfEditFont, pLf);

		if (rdPtr->hFont != 0)
			DeleteObject(rdPtr->hFont);
		rdPtr->hFont=hFont;

		SendMessage(rdPtr->hWnd, WM_SETFONT, (WPARAM)rdPtr->hFont, MAKELONG(TRUE, 0));
	}
	if (pRc!=NULL)
	{
		rdPtr->rHo.hoImgWidth=pRc->right;
		rdPtr->rHo.hoImgHeight=pRc->bottom;
		rdPtr->rHo.hoRect.right=rdPtr->rHo.hoRect.left+pRc->right;
		rdPtr->rHo.hoRect.bottom=rdPtr->rHo.hoRect.top+pRc->bottom;
		SetWindowPos(rdPtr->hWnd, 0, 0, 0, rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
	}
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);
}
COLORREF WINAPI GetRunObjectTextColor(fprdata rdPtr, LOGFONT* pLf)
{
	return rdPtr->crefEditFontColor;
}
void WINAPI SetRunObjectTextColor(fprdata rdPtr, COLORREF rgb)
{
	rdPtr->lFlags&=~EDIT_SYSCOLOR;
	rdPtr->crefEditFontColor=rgb;
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		CONDITION ROUTINES																									//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		IsVisible										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  IsVisible(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if ((rdPtr->hWnd != NULL) && (rdPtr->sVisible != 0))
		return TRUE;
	else
		return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		IsNumber										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  IsNumber(fprdata rdPtr, long param1, long param2)
{
	char	strBuf[40];
	int		uiTextSize;
	
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	uiTextSize = GetWindowText(rdPtr->hWnd, strBuf, 39);

	if (uiTextSize > 37)
		return FALSE;
	if (strspn(strBuf, "+-0123456789" )!=0)
		return TRUE;
	else
		return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		IsSelected										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  IsSelected(fprdata rdPtr, long param1, long param2)
{
	LRESULT		l;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	l=SendMessage(rdPtr->hWnd, EM_GETSEL, 0, 0);
	if (HIWORD(l) > LOWORD(l))
		return TRUE;

	return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		IsEnable										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  IsEnable(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if ((rdPtr->hWnd != NULL) && (rdPtr->sEnable != 0))
		return TRUE;
	else
		return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		HaveFocus										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  HaveFocus(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd == GetFocus())
		return TRUE;
	else
		return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		CanUndo											    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  CanUndo(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (SendMessage(rdPtr->hWnd, EM_CANUNDO, 0, 0))
		return TRUE;
	else
		return FALSE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		WasModified										    									//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  WasModified(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (SendMessage(rdPtr->hWnd, EM_GETMODIFY, 0, 0))
		return TRUE;
	else
		return FALSE;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		ACTION ROUTINES																										//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		LoadText									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  LoadText(fprdata rdPtr, long param1, long param2)
{
//	fprh			rhPtr;
//	HFILE			hFile;
	
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	// To get rhPtr
//	rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Open file
/*
	// En mode plugin, d'abord le charger si nécessaire
#if defined(VITALIZE)
	{
		NPSTR fname = (NPSTR)LocalAlloc(LPTR, _MAX_PATH);
		hFile = HFILE_ERROR;
		if ( fname )
		{
			_fstrcpy(fname, (LPSTR)param1);
			rhPtr->rh4.rh4Mv->mvLoadNetFile (fname);
			hFile = _lopen((LPSTR)fname, READ);
			LocalFree((HLOCAL)fname);
		}
	}
#else
	hFile = _lopen((LPSTR)param1, OF_READ);
#endif

	// Open file
	if (HFILE_ERROR != hFile)
	{
		UINT			uiTextSize;
		HGLOBAL			hglb;
		LPSTR			buffer;
		UINT			maxSize = 64000;

		if ((hglb = GlobalAlloc(GPTR, maxSize)) != NULL)
		{
			// Lock mem
			buffer = (LPSTR)GlobalLock(hglb);
	
			// Read file
			uiTextSize = _lread(hFile, buffer, (UINT)maxSize);
		
			// Set text
			if ((uiTextSize != HFILE_ERROR) && (uiTextSize != 0))
				SetWindowText(rdPtr->hWnd, buffer);
		
			// Unlock & free memory
			GlobalUnlock(hglb);
			GlobalFree(hglb);
		}

		_lclose(hFile);
	}
*/

	DWORD dwSize;
	LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;
	HANDLE hFile = rhPtr->rh4.rh4Mv->mvOpenHFile((LPCSTR)param1, &dwSize, 0);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		if ( dwSize != 0 )
		{
			LPSTR pBuf = (LPSTR)calloc(dwSize+1, 1);
			if ( pBuf != NULL )
			{
				DWORD dwRead;
				ReadFile(hFile, pBuf, dwSize, &dwRead, NULL);
				if ( dwRead == dwSize )
				{
					pBuf[dwSize] = 0;

					// Note: dans MMF 1 il y a une limitation à 64000 - virée ici, voir ce qui se passe quand on charge un texte de plus de 64 Kb
					SetWindowText(rdPtr->hWnd, pBuf);
				}
				free(pBuf);
			}
		}
		rhPtr->rh4.rh4Mv->mvCloseHFile(hFile);
	}

	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		LoadTextSelect								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  LoadTextSelect(fprdata rdPtr, long param1, long param2)
{
    fprh				rhPtr;
	OPENFILENAME		ofn;
	NPSTR				szFilter, szFile, szFileTitle;
	int					i;
	
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
    
	// To get rhPtr
    rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Allocate memory
	if (NULL == (szFilter = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
		return 0;
	if (NULL == (szFile = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
	{
		LocalFree((HLOCAL)szFilter);
		return 0;
	}
	if (NULL == (szFileTitle = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
	{
		LocalFree((HLOCAL)szFile);
		LocalFree((HLOCAL)szFilter);
		return 0;
	}

	// Load filter string & setup file string
	LoadString(hInstLib, M_TEXTFILTER, szFilter, _MAX_PATH);

	_fstrcpy(szFileTitle, "*.txt;*.asc");
	_fstrcpy(szFile, szFileTitle);
	_fstrcat(szFilter, szFileTitle);

	// Compute Filter string
	for (i=0; szFilter[i] != '\0'; i++)
	{
    	if ('|' == szFilter[i])
    		szFilter[i] = '\0';
    }

	// Load title string
	LoadString(hInstLib, M_TEXTTITLE, szFileTitle, _MAX_PATH);

	// Set correct parameters
	_fmemset((LPVOID)&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = rhPtr->rhHEditWin;
	ofn.lpstrFilter = szFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = _MAX_PATH;
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFileTitle = _MAX_PATH;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Pause
	callRunTimeFunction(rdPtr, RFUNCTION_PAUSE, 0, 0);

	// Open dialog box
	if (GetOpenFileName(&ofn ))
	{
		HFILE			hFile;

		// Open file
		hFile = _lopen(ofn.lpstrFile, READ);
		if ( HFILE_ERROR != hFile )
		{
			UINT			uiTextSize;
			HGLOBAL			hglb;
			LPSTR			buffer;
			UINT			maxSize = 64000;

			if ((hglb = GlobalAlloc(GPTR, maxSize)) != NULL)
			{
				// Lock mem
				buffer = (LPSTR)GlobalLock(hglb);

				// Read file
				uiTextSize = _lread(hFile, buffer, (UINT)maxSize);
	
				// Set text
				if ((uiTextSize != HFILE_ERROR) && (uiTextSize != 0))
					SetWindowText(rdPtr->hWnd, buffer);
	
				// Unlock & free memory
				GlobalUnlock(hglb);
				GlobalFree(hglb);
			}

			_lclose(hFile);
		}
	}

	// Continue
	callRunTimeFunction(rdPtr, RFUNCTION_CONTINUE, 0, 0);

	// Clean up memory
	LocalFree((HLOCAL)szFileTitle);
	LocalFree((HLOCAL)szFile);
	LocalFree((HLOCAL)szFilter);

	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SaveText									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SaveText(fprdata rdPtr, long param1, long param2)
{
#if !defined(VITALIZE)
	HFILE			hFile;
	OFSTRUCT		OpenFileStruct;
	UINT			uiTextSize;
	HGLOBAL			hglb;
	LPSTR			buffer;
	
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	// Get text size
	uiTextSize = GetWindowTextLength(rdPtr->hWnd) + 1;

	// Alloc memory
	if ((hglb = GlobalAlloc(GPTR, uiTextSize)) != NULL)
	{
		// Lock mem
		buffer = (LPSTR)GlobalLock(hglb);
	
		// Get text
		GetWindowText(rdPtr->hWnd, buffer, uiTextSize);

		// Open file
		hFile = OpenFile((LPSTR)param1, &OpenFileStruct, OF_CREATE | OF_WRITE);
		if (HFILE_ERROR != hFile)
		{
			// Write file
			_lwrite(hFile, buffer, uiTextSize);
			_lclose(hFile);
		}
		
		// Unlock & free memory
		GlobalUnlock(hglb);
		GlobalFree(hglb);
	}

#endif // VITALIZE
	// ok
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SaveTextSelect								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SaveTextSelect(fprdata rdPtr, long param1, long param2)
{
#if !defined(VITALIZE)
    fprh				rhPtr;
	OPENFILENAME		ofn;
	NPSTR				szFilter, szFile, szFileTitle;
	int					i;
    
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	// To get rhPtr
    rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Allocate memory
	if (NULL == (szFilter = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
		return 0;
	if (NULL == (szFile = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
	{
		LocalFree((HLOCAL)szFilter);
		return 0;
	}
	if (NULL == (szFileTitle = (NPSTR)LocalAlloc(LPTR, _MAX_PATH)))
	{
		LocalFree((HLOCAL)szFile);
		LocalFree((HLOCAL)szFilter);
		return 0;
	}

	// Load filter string & setup file string
	LoadString(hInstLib, M_TEXTFILTER, szFilter, _MAX_PATH);

	_fstrcpy(szFileTitle, "*.txt;*.asc");
	_fstrcpy(szFile, szFileTitle);
	_fstrcat(szFilter, szFileTitle);

	// Compute Filter string
	for (i=0; szFilter[i] != '\0'; i++)
	{
    	if ('|' == szFilter[i])
    		szFilter[i] = '\0';
    }

	// Load title string
	LoadString(hInstLib, M_TEXTTITLE, szFileTitle, _MAX_PATH);

	// Set correct parameters
	_fmemset((LPVOID)&ofn, 0, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = rhPtr->rhHEditWin;
	ofn.lpstrFilter = szFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = _MAX_PATH;
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFileTitle = _MAX_PATH;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST;

	// Pause
	callRunTimeFunction(rdPtr, RFUNCTION_PAUSE, 0, 0);

	// Open dialog box
	if (GetSaveFileName(&ofn))
	{
		HFILE			hFile;
		OFSTRUCT		OpenFileStruct;
		UINT			uiTextSize;
		HGLOBAL			hglb;
		LPSTR		buffer;
		
		// To get rhPtr
	    rhPtr = rdPtr->rHo.hoAdRunHeader;
	
		// Get text size
		uiTextSize = GetWindowTextLength(rdPtr->hWnd) + 1;
	
		// Alloc memory
		if ((hglb = GlobalAlloc(GPTR, uiTextSize)) != NULL)
		{
			// Lock mem
			buffer = (LPSTR)GlobalLock(hglb);
		
			// Get text
			GetWindowText(rdPtr->hWnd, buffer, uiTextSize);
	
			// Open file
			hFile = OpenFile(ofn.lpstrFile, &OpenFileStruct, OF_CREATE | OF_WRITE);
			if (HFILE_ERROR != hFile)
			{
				// Write file
				_lwrite(hFile, buffer, uiTextSize);
				_lclose(hFile);
			}
			
			// Unlock & free memory
			GlobalUnlock(hglb);
			GlobalFree(hglb);
		}
	}

	// Continue
	callRunTimeFunction(rdPtr, RFUNCTION_CONTINUE, 0, 0);

	// Clean up memory
	LocalFree((HLOCAL)szFileTitle);
	LocalFree((HLOCAL)szFile);
	LocalFree((HLOCAL)szFilter);
#endif // VITALIZE
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetText										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetText(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL && param1 != 0)
	{
		LPSTR pText = (LPSTR)param1;
		SetWindowText(rdPtr->hWnd, (LPSTR)param1);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ReplaceSelection							    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ReplaceSelection(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_REPLACESEL, 0, (LPARAM)(LPSTR)param1);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Cut											    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Cut( fprdata rdPtr, long param1, long param2 )
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, WM_CUT, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Copy										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Copy(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, WM_COPY, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Paste										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Paste(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, WM_PASTE, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Clear										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Clear(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, WM_CLEAR, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Undo										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Undo(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, WM_UNDO, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ClearUndoBuffer								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ClearUndoBuffer(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_EMPTYUNDOBUFFER, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Show										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Show(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
	{
		rdPtr->sVisible = 1;
		ShowWindow(rdPtr->hWnd, SW_SHOW);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Hide										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Hide(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	if (rdPtr->hWnd != NULL)
	{
		rdPtr->sVisible = 0;
		ShowWindow(rdPtr->hWnd, SW_HIDE);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetFontSelect								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetFontSelect(fprdata rdPtr, long param1, long param2)
{
	fprh				rhPtr;
	CHOOSEFONT 			cf;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);
	
	// To get rhPtr
    rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Set up
	_fmemset(&cf, 0, sizeof(CHOOSEFONT));
	cf.lStructSize = sizeof(CHOOSEFONT);
	cf.hwndOwner = rhPtr->rhHEditWin;
	cf.lpLogFont = (LPLOGFONT)&rdPtr->lfEditFont;
	cf.Flags = CF_SCREENFONTS | CF_EFFECTS | CF_INITTOLOGFONTSTRUCT;
	cf.rgbColors = rdPtr->crefEditFontColor;
	cf.nFontType = SCREEN_FONTTYPE;
	cf.lpszStyle = (fpchar)rdPtr->szEditFontStyle;

	// Pause
	callRunTimeFunction(rdPtr, RFUNCTION_PAUSE, 0, 0);

	// Choose font
	if (ChooseFont16(&cf) != 0)
	{
		rdPtr->crefEditFontColor = cf.rgbColors;

		// Destroy font
		if (rdPtr->hFont != NULL)
			DeleteObject(rdPtr->hFont);

		// Create & set font
        rdPtr->hFont = CreateFontIndirect16(&rdPtr->lfEditFont);
		SendMessage(rdPtr->hWnd, WM_SETFONT, (WPARAM)rdPtr->hFont, MAKELONG(TRUE, 0));
	}

	// Continue
	callRunTimeFunction(rdPtr, RFUNCTION_CONTINUE, 0, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetColorSelect								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetColorSelect(fprdata rdPtr, long param1, long param2)
{
    fprh				rhPtr;
	CHOOSECOLOR			cc;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	// To get rhPtr
    rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Set up
	_fmemset(&cc, 0, sizeof(CHOOSECOLOR));
	cc.lStructSize = sizeof(CHOOSECOLOR);
	cc.hwndOwner = rhPtr->rhHEditWin;
	cc.rgbResult = rdPtr->crefEditFontBkColor;
	cc.lpCustColors = rdPtr->crefCustColor;
	cc.Flags = CC_RGBINIT;

	// Pause
	callRunTimeFunction(rdPtr, RFUNCTION_PAUSE, 0, 0);

	// Choose font
	if (ChooseColor(&cc))
	{
		if (rdPtr->hBrush != NULL)
			DeleteObject(rdPtr->hBrush);
		rdPtr->crefEditFontBkColor = cc.rgbResult;
		rdPtr->hBrush = CreateSolidBrush(rdPtr->crefEditFontBkColor);
		rdPtr->lFlags &= ~EDIT_SYSCOLOR;
		InvalidateRect(rdPtr->hWnd, NULL, TRUE);
	}

	// Continue
	callRunTimeFunction(rdPtr, RFUNCTION_CONTINUE, 0, 0);
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetBkdColor									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetBkdColor(fprdata rdPtr, long param1, long param2)
{
	if ( (rdPtr->lFlags & EDIT_TRANSP) != 0 )
		return 0;

	// Set background color
	rdPtr->crefEditFontBkColor = param1;

	// Recréer la brosse pour le fond
	if (rdPtr->hBrush != NULL)
		DeleteObject(rdPtr->hBrush);
	rdPtr->hBrush = CreateSolidBrush(param1);

	// S'il y avait le flag "couleurs systeme", alors récupérer la couleur courante du texte
	if ( (rdPtr->lFlags & EDIT_SYSCOLOR) != 0 )
	{
		rdPtr->crefEditFontColor = GetSysColor(COLOR_WINDOWTEXT);

		// Supprimer le flag "Couleurs systeme"
		rdPtr->lFlags &= ~EDIT_SYSCOLOR;
	}

	// Réafficher
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);

	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetColor									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetColor(fprdata rdPtr, long param1, long param2)
{
	// Set Text Color
	rdPtr->crefEditFontColor = param1;

	// S'il y avait le flag "couleurs systeme", alors récupérer la couleur courante du fond
	if ( (rdPtr->lFlags & EDIT_SYSCOLOR) != 0 )
	{
		if ( (rdPtr->lFlags & EDIT_TRANSP) == 0 )
		{
			rdPtr->crefEditFontBkColor = GetSysColor(COLOR_WINDOW);

			// Recréer la brosse pour le fond
			if (rdPtr->hBrush != NULL)
				DeleteObject(rdPtr->hBrush);
			rdPtr->hBrush = CreateSolidBrush(rdPtr->crefEditFontBkColor);
		}

		// Supprimer le flag "Couleurs systeme"
		rdPtr->lFlags &= ~EDIT_SYSCOLOR;
	}

	// Réafficher
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);

	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Activate									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Activate(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SetFocus(rdPtr->hWnd);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Desactivate									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Desactivate(fprdata rdPtr, long param1, long param2)
{
    fprh						rhPtr;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	// To get editwin handle
    rhPtr = rdPtr->rHo.hoAdRunHeader;
	SetFocus( rhPtr->rhHEditWin );
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Enable										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Enable(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		rdPtr->sEnable = 1;
		EnableWindow(rdPtr->hWnd, TRUE);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Disable										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  Disable(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		rdPtr->sEnable = 0;
		EnableWindow(rdPtr->hWnd, FALSE);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ReadOnlyOn									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ReadOnlyOn(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_SETREADONLY, TRUE, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ReadOnlyOff									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ReadOnlyOff(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_SETREADONLY, FALSE, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		TextModified								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  TextModified(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_SETMODIFY, TRUE, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		LimitTextSize								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  LimitTextSize(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_LIMITTEXT, (WPARAM)param1, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		TextNotModified								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  TextNotModified(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		SendMessage(rdPtr->hWnd, EM_SETMODIFY, FALSE, 0);
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetPosition									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetPosition(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		callRunTimeFunction(rdPtr, RFUNCTION_SETPOSITION, (int)(short)HIWORD(param1), (int)(short)LOWORD(param1));
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetXPosition								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetXPosition(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		callRunTimeFunction(rdPtr, RFUNCTION_SETPOSITION, param1, rdPtr->rHo.hoY);
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetYPosition								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetYPosition(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		callRunTimeFunction(rdPtr, RFUNCTION_SETPOSITION, rdPtr->rHo.hoX, param1);
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetSize										    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetSize(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		rdPtr->rHo.hoImgWidth = (short)param1;
		rdPtr->rHo.hoImgHeight = (short)param2;
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetXSize									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetXSize(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		rdPtr->rHo.hoImgWidth = (short)param1;
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ScrollToTop									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ScrollToTop(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		int nTopLine = SendMessage(rdPtr->hWnd, EM_GETFIRSTVISIBLELINE, 0, 0);
//		int nLineCount = SendMessage(rdPtr->hWnd, EM_GETLINECOUNT, 0, 0);
		if ( nTopLine != 0 )
			SendMessage(rdPtr->hWnd, EM_LINESCROLL, (WPARAM)0, (LPARAM)-nTopLine);
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ScrollToLine								    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ScrollToLine(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		int nTopLine = SendMessage(rdPtr->hWnd, EM_GETFIRSTVISIBLELINE, 0, 0);
		if ( nTopLine != param1 )
			SendMessage(rdPtr->hWnd, EM_LINESCROLL, (WPARAM)0, (LPARAM)param1-nTopLine);
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		ScrollToEnd									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  ScrollToEnd(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		int nLineCount = SendMessage(rdPtr->hWnd, EM_GETLINECOUNT, 0, 0);
		if ( nLineCount <= 1 )
		{
			SendMessage(rdPtr->hWnd, EM_LINESCROLL, (WPARAM)0, (LPARAM)0);
			return 0;
		}

		// Determiner la hauteur d'une ligne (galère, mais bon...)
//		int nTopLine = SendMessage(rdPtr->hWnd, EM_GETFIRSTVISIBLELINE, 0, 0);
//		SendMessage(rdPtr->hWnd, EM_LINESCROLL, (WPARAM)0, (LPARAM)nLineCount-nTopLine);

		SendMessage(rdPtr->hWnd, WM_VSCROLL, (WPARAM)SB_BOTTOM, 0);
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetYSize									    										//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  SetYSize(fprdata rdPtr, long param1, long param2)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
	{
		rdPtr->rHo.hoImgHeight = (short)param1;
		callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
	return 0;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		EXPRESSION ROUTINES																									//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetNumber
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetValue(fprdata rdPtr, long param1)
{
	npchar	strBuf;
	long	l;
	
	strBuf=(npchar)LocalAlloc(LPTR, 40);
	if (strBuf!=0)
	{
		GetWindowText(rdPtr->hWnd, strBuf, 39);
		l=atol(strBuf);
		LocalFree((HLOCAL)strBuf);
	}
	return l;
}	
	

//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetText												    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetText(fprdata rdPtr, long param1)
{
	UINT			uiTextSize;
	LPSTR			buffer;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// Free memory
	if (rdPtr->hglb != NULL)
	{
		GlobalUnlock(rdPtr->hglb);
		GlobalFree(rdPtr->hglb);
		rdPtr->hglb = NULL;
	}

	// Get text size
	uiTextSize = GetWindowTextLength(rdPtr->hWnd);

	// Alloc memory
	if ( uiTextSize != 0 )
	{
		if ((rdPtr->hglb = GlobalAlloc(GPTR, uiTextSize+1)) != NULL)
		{
			// Lock mem
			buffer = (LPSTR)GlobalLock(rdPtr->hglb);

			// Get text
			GetWindowText(rdPtr->hWnd, buffer, uiTextSize+1);
			buffer[uiTextSize] = 0;

			// Return pointer
			return (long)buffer;
		}
	}

	// ok
	return (long)(LPCSTR)szNullString;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetSelection										    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetSelection(fprdata rdPtr, long param1)
{
	UINT			uiTextSize;
	char _far*		text;
	DWORD 			dwResult;
	uint			wStart, wEnd;
	HGLOBAL			hg=0;
	long			size;
	LPSTR		buffer=0;

	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	// Free memory
	if (rdPtr->hglb != NULL)
	{
		GlobalUnlock(rdPtr->hglb);
		GlobalFree(rdPtr->hglb);
		rdPtr->hglb = NULL;
	}

	// Get selection
	text=(LPSTR)szNullString;
	size=GetWindowTextLength(rdPtr->hWnd);
	if ( size > 0 )
	{
		dwResult = SendMessage(rdPtr->hWnd, EM_GETSEL, 0, 0);
		wStart =LOWORD(dwResult);
		wEnd=HIWORD(dwResult);
		uiTextSize = wEnd - wStart;
		if ( (long)uiTextSize > 0 ) 
		{
			hg=	GlobalAlloc(GPTR, size+2);
			if (hg!=0)
			{
				buffer=(LPSTR)GlobalLock(hg);
				GetWindowText(rdPtr->hWnd, buffer, (int)size+2);

				if ((rdPtr->hglb = GlobalAlloc(GPTR, uiTextSize+2)) != NULL)
				{
					text = (LPSTR)GlobalLock(rdPtr->hglb);
					_fmemcpy(text, buffer + wStart, uiTextSize);
					text[uiTextSize] = 0;
				}
			}
		}
	}

	// Libere les buffers
	if (buffer!=0) GlobalUnlock(hg);
	if (hg!=0) GlobalFree(hg);

	// Ok
	rdPtr->rHo.hoFlags |= HOF_STRING;
	return (long)text;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetXPosition										    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetXPosition(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		return rdPtr->rHo.hoX;

    return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetYPosition										    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetYPosition(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if ( rdPtr->hWnd != NULL)
		return rdPtr->rHo.hoY;
    return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetXSize											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetXSize(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		return rdPtr->rHo.hoImgWidth;
    return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetYSize											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetYSize(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		return rdPtr->rHo.hoImgHeight;
    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetFirstLine											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetFirstLine(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		return SendMessage(rdPtr->hWnd, EM_GETFIRSTVISIBLELINE, 0, 0);
    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetLineCount											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetLineCount(fprdata rdPtr, long param1)
{
	// Debug assertion
    assert(rdPtr != NULL);
    assert(rdPtr->hWnd != NULL);

	if (rdPtr->hWnd != NULL)
		return SendMessage(rdPtr->hWnd, EM_GETLINECOUNT, 0, 0);
    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetColor											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetColor(fprdata rdPtr, long param1)
{
	COLORREF color = rdPtr->crefEditFontColor;
	if ( (rdPtr->lFlags & EDIT_SYSCOLOR) != 0 )
		color = GetSysColor(COLOR_WINDOWTEXT);

    return color;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		GetBkdColor											    								//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long WINAPI  GetBkdColor(fprdata rdPtr, long param1)
{
	COLORREF color = rdPtr->crefEditFontBkColor;
	if ( (rdPtr->lFlags & EDIT_SYSCOLOR) != 0 )
		color = GetSysColor(COLOR_WINDOW);

    return color;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		RETURN THE POPUP MENUS TO OPEN UNDER EVENT EDITOR																	//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef RUN_ONLY



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		menucpy																				    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void menucpy(HMENU hTargetMenu, HMENU hSourceMenu)
{
	int			n, id, nMn;
	NPSTR		strBuf;
	HMENU		hSubMenu;
	
	nMn = GetMenuItemCount(hSourceMenu);
	strBuf = (NPSTR)LocalAlloc(LPTR, 80);
	for (n = 0; n < nMn; n++)
	{
		if (0 == (id = GetMenuItemID(hSourceMenu, n)))
			AppendMenu(hTargetMenu, MF_SEPARATOR, 0, 0L);
		else
		{
			GetMenuString(hSourceMenu, n, strBuf, 80, MF_BYPOSITION);
			if (id != -1)
				AppendMenu(hTargetMenu, GetMenuState(hSourceMenu, n, MF_BYPOSITION), id, strBuf);
			else
			{
				hSubMenu = CreatePopupMenu();
				AppendMenu(hTargetMenu, MF_POPUP | MF_STRING, (uint)hSubMenu, strBuf);
				menucpy(hSubMenu, GetSubMenu(hSourceMenu, n));
			}
		}
	}
	LocalFree((HLOCAL)strBuf);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetPopupMenu																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

HMENU GetPopupMenu(short mn)
{
	HMENU	hMn, hSubMenu, hPopup = NULL;

	if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL)
	{
		if ((hSubMenu = GetSubMenu(hMn, 0)) != NULL)
		{
			if ((hPopup = CreatePopupMenu()) != NULL)
				menucpy(hPopup, hSubMenu);
		}
		DestroyMenu(hMn);
	}
	return hPopup;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetConditionMenu																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

HMENU WINAPI  GetConditionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return GetPopupMenu(MN_CONDITIONS);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetActionMenu																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

HMENU WINAPI  GetActionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return GetPopupMenu(MN_ACTIONS);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetExpressionMenu																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

HMENU WINAPI  GetExpressionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return GetPopupMenu(MN_EXPRESSIONS);
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		RETURN THE TEXT TO BE DISPLAYED AS TITLE FOR PARAMETERS INPUT														//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetCodeTitle																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void GetCodeTitle(WORD s, short mn, short entryId, LPSTR strBuf, WORD maxLen)
{
	HMENU		hMn;

	// Debug assertion
    assert(strBuf != NULL);

	// If a special string is to be returned
	if (s != 0)
		LoadString(hInstLib, s, strBuf, maxLen);
	else
	{
		// Otherwise, returns the menu option 
		if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL)
		{
			GetMenuString(hMn, entryId, strBuf, maxLen, MF_BYCOMMAND);
			DestroyMenu(hMn);
		}
	}
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetConditionTitle																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetConditionTitle(mv _far *knpV, short code, short param, fpchar strBuf, short maxLen)
{
	// Debug assertion
    assert(knpV != NULL);
    assert(strBuf != NULL);

	GetCodeTitle(conditionsInfos[code].paramTitle[param], MN_CONDITIONS, (short)(ID_MENUCONDITIONS + code), strBuf, maxLen);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetActionTitle																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetActionTitle(mv _far *knpV, short code, short param, fpchar strBuf, short maxLen)
{
	// Debug assertion
    assert(knpV != NULL);
    assert(strBuf != NULL);

	GetCodeTitle(actionsInfos[code].paramTitle[param], MN_ACTIONS, (short)(ID_MENUACTIONS + code), strBuf, maxLen);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetExpressionTitle																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetExpressionTitle(mv _far *knpV, short code, fpchar strBuf, short maxLen)
{
	// Debug assertion
    assert(knpV != NULL);
    assert(strBuf != NULL);

	GetCodeTitle (expressionsInfos[code].paramTitle[0], MN_EXPRESSIONS, (short)(ID_MENUEXPRESSIONS + code), strBuf, maxLen);
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		CONVERTS A MENU ID TO INTERNAL EVENT CODE																			//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetConditionCodeFromMenu															    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  GetConditionCodeFromMenu(mv _far *knpV, short menuId)
{
	// Debug assertion
    assert(knpV != NULL);

	if (menuId >= ID_MENUCONDITIONS && menuId < ID_MENUCONDITIONS + CND_LAST)
	{
		return menuId - ID_MENUCONDITIONS;
	}
	return -1;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetActionCodeFromMenu																    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  GetActionCodeFromMenu(mv _far *knpV, short menuId)
{
	// Debug assertion
    assert(knpV != NULL);

	if (menuId >= ID_MENUACTIONS && menuId < ID_MENUACTIONS + ACT_LAST)
	{
		return menuId - ID_MENUACTIONS;
	}
	return -1;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetExpressionCodeFromMenu															    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  GetExpressionCodeFromMenu(mv _far *knpV, short menuId)
{
	// Debug assertion
    assert(knpV != NULL);

	if (menuId >= ID_MENUEXPRESSIONS && menuId < ID_MENUEXPRESSIONS + EXP_LAST)
	{
		return menuId - ID_MENUEXPRESSIONS;
	}
	return -1;
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		RETURNS INFORMATIONS ABOUT ONE EVENT																				//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetConditionInfos																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

infosEvents _far * WINAPI  GetConditionInfos(mv _far *knpV, short code)
{
	// Debug assertion
    assert(knpV != NULL);

	return &conditionsInfos[code];
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetActionInfos																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

infosEvents _far * WINAPI  GetActionInfos(mv _far *knpV, short code)
{
	// Debug assertion
    assert(knpV != NULL);

	return &actionsInfos[code];
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetExpressionInfos																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

infosEvents _far * WINAPI  GetExpressionInfos(mv _far *knpV, short code)
{
	// Debug assertion
    assert(knpV != NULL);

	return &expressionsInfos[code];
}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		RETURN THE DISPLAY STRING OF AN EVENT																				//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetConditionString																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetConditionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{
	// Check compatibility
	if ( !IS_COMPATIBLE(knpV) )
	{
		strcpy(strPtr, "EditBox: This object is not compatible with this version of MMF");
		return;
	}

	LoadString(hInstLib, M_DISPCONDITIONS+code, strPtr, maxLen);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetActionString																		    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetActionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{            
	// Check compatibility
	if ( !IS_COMPATIBLE(knpV) )
	{
		strcpy(strPtr, "EditBox: This object is not compatible with this version of MMF");
		return;
	}

	LoadString(hInstLib, M_DISPACTIONS + code, strPtr, maxLen);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		GetExpressionString																	    //
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetExpressionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{            
	// Check compatibility
	if ( !IS_COMPATIBLE(knpV) )
	{
		strcpy(strPtr, "EditBox: This object is not compatible with this version of MMF");
		return;
	}

	LoadString(hInstLib, M_DISPEXPRESSIONS + code, strPtr, maxLen);
}



// --------------------
//
// MMF 1.5 : Text functions
//
// --------------------
DWORD WINAPI  GetTextCaps(mv _far *knpV, fpedata edPtr)
{
	return (TEXT_FONT | TEXT_COLOR);
}

BOOL WINAPI  GetTextFont(mv _far *knpV, fpedata edPtr, LPLOGFONT plf, LPSTR pStyle, UINT cbSize)
{
	plf->lfHeight = edPtr->lfEditFont.lfHeight;
	plf->lfWidth = edPtr->lfEditFont.lfWidth;
	plf->lfEscapement = edPtr->lfEditFont.lfEscapement;
	plf->lfOrientation = edPtr->lfEditFont.lfOrientation;
	plf->lfWeight = edPtr->lfEditFont.lfWeight;
	plf->lfItalic = edPtr->lfEditFont.lfItalic;
	plf->lfUnderline = edPtr->lfEditFont.lfUnderline;
	plf->lfStrikeOut = edPtr->lfEditFont.lfStrikeOut;
	plf->lfCharSet = edPtr->lfEditFont.lfCharSet;
	plf->lfOutPrecision = edPtr->lfEditFont.lfOutPrecision;
	plf->lfClipPrecision = edPtr->lfEditFont.lfClipPrecision;
	plf->lfQuality = edPtr->lfEditFont.lfQuality;
	plf->lfPitchAndFamily = edPtr->lfEditFont.lfPitchAndFamily;
	memcpy(plf->lfFaceName, edPtr->lfEditFont.lfFaceName, LF_FACESIZE);
	strncpy(pStyle, edPtr->szEditFontStyle, min(40,cbSize));

	return TRUE;
}

BOOL WINAPI  SetTextFont(mv _far *knpV, fpedata edPtr, LPLOGFONT plf, LPCSTR pStyle)
{
	edPtr->lfEditFont.lfHeight = (short)plf->lfHeight;
	edPtr->lfEditFont.lfWidth = (short)plf->lfWidth;
	edPtr->lfEditFont.lfEscapement = (short)plf->lfEscapement;
	edPtr->lfEditFont.lfOrientation = (short)plf->lfOrientation;
	edPtr->lfEditFont.lfWeight = (short)plf->lfWeight;
	edPtr->lfEditFont.lfItalic = plf->lfItalic;
	edPtr->lfEditFont.lfUnderline = plf->lfUnderline;
	edPtr->lfEditFont.lfStrikeOut = plf->lfStrikeOut;
	edPtr->lfEditFont.lfCharSet = plf->lfCharSet;
	edPtr->lfEditFont.lfOutPrecision = plf->lfOutPrecision;
	edPtr->lfEditFont.lfClipPrecision = plf->lfClipPrecision;
	edPtr->lfEditFont.lfQuality = plf->lfQuality;
	edPtr->lfEditFont.lfPitchAndFamily = plf->lfPitchAndFamily;
	memcpy(edPtr->lfEditFont.lfFaceName, plf->lfFaceName, LF_FACESIZE);
	strncpy(edPtr->szEditFontStyle, pStyle, 40);

	return TRUE;
}

COLORREF WINAPI  GetTextClr(mv _far *knpV, fpedata edPtr)
{
	return edPtr->crefEditFontColor;
}

void WINAPI  SetTextClr(mv _far *knpV, fpedata edPtr, COLORREF color)
{
	edPtr->crefEditFontColor = color;
	edPtr->lFlags &= ~EDIT_SYSCOLOR;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Create object																			//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////
int Get_ZoneHeight(mv _far *knpV, fpedata edPtr)
{
	TEXTMETRIC	tm;
	HDC			wDC;
	HFONT		hFont, oldFont;
	
	// Trouve la taille par defaut de la zone
	wDC=GetDC(NULL);
	if (wDC!=NULL)
	{
		hFont=CreateFontIndirect16(&edPtr->lfEditFont);
		if (hFont!=0)
		{
			oldFont=(HFONT)SelectObject(wDC, hFont);
			GetTextMetrics(wDC, &tm);
			SelectObject(wDC, oldFont);
			DeleteObject(hFont);
		}
		ReleaseDC(NULL,wDC);
	}
	if ( (edPtr->lFlags & EDIT_3DLOOK) == 0 )
		return tm.tmHeight+2;
	else
		return tm.tmHeight+7;
}
int WINAPI  CreateObject(mv _far *knpV, fpLevObj loPtr, fpedata edPtr)
{
	char			a;

	// Debug assertion
    assert(knpV != NULL);
    assert(loPtr != NULL);
    assert(edPtr != NULL);

	// Check compatibility
	if ( !IS_COMPATIBLE(knpV) )
		return -1;

	// Set default object flags
	// Default font = MS Sans Serif / 8
	if ( knpV->mvGetDefaultFont != NULL )
	{
		LOGFONT	lf;
		knpV->mvGetDefaultFont(&lf, edPtr->szEditFontStyle, 40);

		edPtr->lfEditFont.lfHeight = (short)lf.lfHeight;
		edPtr->lfEditFont.lfWidth = (short)lf.lfWidth;
		edPtr->lfEditFont.lfEscapement = (short)lf.lfEscapement;
		edPtr->lfEditFont.lfOrientation = (short)lf.lfOrientation;
		edPtr->lfEditFont.lfWeight = (short)lf.lfWeight;
		edPtr->lfEditFont.lfItalic = lf.lfItalic;
		edPtr->lfEditFont.lfUnderline = lf.lfUnderline;
		edPtr->lfEditFont.lfStrikeOut = lf.lfStrikeOut;
		edPtr->lfEditFont.lfCharSet = lf.lfCharSet;
		edPtr->lfEditFont.lfOutPrecision = lf.lfOutPrecision;
		edPtr->lfEditFont.lfClipPrecision = lf.lfClipPrecision;
		edPtr->lfEditFont.lfQuality = lf.lfQuality;
		edPtr->lfEditFont.lfPitchAndFamily = lf.lfPitchAndFamily;
		memcpy(edPtr->lfEditFont.lfFaceName, lf.lfFaceName, LF_FACESIZE);
	}
	else
	{
		edPtr->lfEditFont.lfWidth = 0;
		edPtr->lfEditFont.lfHeight = 8;
		_fstrcpy((LPSTR)edPtr->lfEditFont.lfFaceName, "SYSTEM");
	}

	edPtr->crefEditFontColor = RGB(0, 0, 0);
	edPtr->crefEditFontBkColor = RGB(255, 255, 255);
	for (a = 0; a < 16; a++)
		edPtr->crefCustColor[a] = RGB(255, 255, 255);
	edPtr->lFlags = EDIT_BORDER|EDIT_TABSTOP|EDIT_3DLOOK;
	edPtr->sSizeX = 200;
	edPtr->sSizeY = Get_ZoneHeight(knpV, edPtr);

	return 0;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetEditSize																				//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL WINAPI DLLExport SetEditSize(LPMV mv, fpedata edPtr, int cx, int cy)
{
	WORD sy;

	// New x size
	if (0 == (edPtr->lFlags & EDIT_HSCROLLBAR))
		edPtr->sSizeX = cx;
	else
		if (cx >= 80)
			edPtr->sSizeX = cx;
		else
			edPtr->sSizeX = 80;

	// New y size
	if (0 == (edPtr->lFlags & EDIT_VSCROLLBAR))
	{
		sy=(WORD)(WORD)Get_ZoneHeight(mv, edPtr);
		if (cy >= sy)
			edPtr->sSizeY = cy;
		else
			edPtr->sSizeY = sy;
	}
	else
		if (cy >= 12)
			edPtr->sSizeY = cy;
		else
			edPtr->sSizeY = 12;
	return TRUE;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Get object rectangle																	//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  GetObjectRect(mv _far *knpV, RECT _far *rc, fpLevObj loPtr, fpedata edPtr)
{
	// Debug assertion
    assert(knpV != NULL);
    assert(rc != NULL);
    assert(loPtr != NULL);
    assert(edPtr != NULL);

	// Returns size of the icon
	rc->right = rc->left + edPtr->sSizeX;
	rc->bottom = rc->top + edPtr->sSizeY;

	return;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		DrawRect																				//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void DrawRect(mv _far *knpV, int x, int y)
{
	POINT		point[3];

	// Debug assertion
    assert(knpV != NULL);

	// Draw gray rectangle
	WinFillRect(knpV->mvIdEditWin, x, y, x + 19, y + 19, RGB(200, 200, 200));
	
	// Select pen
	WinPen(knpV->mvIdEditWin, RGB(255, 255, 255), PS_SOLID, 1);
	
	// Draw box & 2 lines
	point[0].x = x + 1;
	point[0].y = y + 18;
	point[1].x = x + 1;
	point[1].y = y + 1;
	point[2].x = x + 18;
	point[2].y = y + 1;
	WinLine(knpV->mvIdEditWin, (POINT _far *)point, 2);
	
	// Select pen
	WinPen(knpV->mvIdEditWin, RGB(50, 50, 50), PS_SOLID, 1);
	
	// Draw box & 2 lines
	point[0].x = x;
	point[0].y = y + 19;
	point[1].x = x + 19;
	point[1].y = y + 19;
	point[2].x = x + 19;
	point[2].y = y;
	WinLine(knpV->mvIdEditWin, (POINT _far *)point, 2);
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Display object in Level Editor															//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

void WINAPI  EditorDisplay(mv _far *knpV, fpObjInfo oiPtr, fpLevObj loPtr, fpedata edPtr, RECT _far *rc)
{
	npchar		strBuf;
	HFONT 		hFont;
	int			m;
	RECT		rc2;
	COLORREF	bkdColor = edPtr->crefEditFontBkColor;
	COLORREF	textColor = edPtr->crefEditFontColor;
	if ( edPtr->lFlags & EDIT_SYSCOLOR )
	{
		bkdColor = GetSysColor(COLOR_WINDOW);
		textColor = GetSysColor(COLOR_WINDOWTEXT);
	}
		
	// Fill rectangle
	WinFillRect(knpV->mvIdEditWin, rc->left, rc->top, rc->right, rc->bottom, bkdColor);
	CopyRect(&rc2, rc);
	
	// Draw scroll bars
	if (((edPtr->lFlags & EDIT_HSCROLLBAR) != 0) && ((edPtr->lFlags & EDIT_VSCROLLBAR) != 0))
	{
		WinFillRect(knpV->mvIdEditWin, rc->left, rc->bottom - 19, rc->right - 19, rc->bottom, RGB( 240, 240, 240));
		WinFillRect(knpV->mvIdEditWin, rc->right - 19, rc->top, rc->right, rc->bottom - 39, RGB( 240, 240, 240));
		WinFillRect(knpV->mvIdEditWin, rc->right - 19, rc->bottom - 19, rc->right, rc->bottom, RGB( 200, 200, 200));
		DrawRect(knpV, rc->left, rc->bottom - 19);
		DrawRect(knpV, rc->right - 39, rc->bottom - 19);
		DrawRect(knpV, rc->left + ((rc->right - rc->left - 39) / 2), rc->bottom - 19);
		DrawRect(knpV, rc->right - 19, rc->top);
		DrawRect(knpV, rc->right - 19, rc->bottom - 39);
		DrawRect(knpV, rc->right - 19, rc->top + ((rc->bottom - rc->top - 39) / 2));

		// Border
		if ((edPtr->lFlags & EDIT_BORDER) != 0)
		{
			POINT		point[5];

			// Select pen
			WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_SOLID, 1);
				
			// Draw box & 2 lines
			point[0].x = rc->left;
			point[0].y = rc->top;
			point[1].x = rc->right - 20;
			point[1].y = rc->top;
			point[2].x = rc->right - 20;
			point[2].y = rc->bottom - 20;
			point[3].x = rc->left;
			point[3].y = rc->bottom - 20;
			point[4].x = rc->left;
			point[4].y = rc->top;
			WinLine(knpV->mvIdEditWin, (POINT _far *)point, 4);
		}
		rc2.right-=20, rc2.bottom-=20;			
	}
	else
	{
		// Draw x scroll bar
		if ((edPtr->lFlags & EDIT_HSCROLLBAR) != 0)
		{
			WinFillRect(knpV->mvIdEditWin, rc->left, rc->bottom-19, rc->right, rc->bottom, RGB(200, 200, 200));
			DrawRect(knpV, rc->left, rc->bottom - 19);
			DrawRect(knpV, rc->right - 19, rc->bottom - 19);
			DrawRect(knpV, rc->left + ((rc->right - rc->left - 19) / 2), rc->bottom - 19);

			// Border
			if ((edPtr->lFlags & EDIT_BORDER) != 0)
			{
				POINT		point[5];

				// Select pen
				WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_SOLID, 1);
				
				// Draw box & 2 lines
				point[0].x = rc->left;
				point[0].y = rc->top;
				point[1].x = rc->right;
				point[1].y = rc->top;
				point[2].x = rc->right;
				point[2].y = rc->bottom - 20;
				point[3].x = rc->left;
				point[3].y = rc->bottom - 20;
				point[4].x = rc->left;
				point[4].y = rc->top;
				WinLine(knpV->mvIdEditWin, (POINT _far *)point, 4);
			}
			rc2.right-=20;			
		}

		// Draw y scroll bar
		if ((edPtr->lFlags & EDIT_VSCROLLBAR) != 0)
		{
			WinFillRect(knpV->mvIdEditWin, rc->right - 19, rc->top, rc->right, rc->bottom, RGB(200, 200, 200));
			DrawRect(knpV, rc->right - 19, rc->top);
			DrawRect(knpV, rc->right - 19, rc->bottom - 19);
			DrawRect(knpV, rc->right - 19, rc->top + ((rc->bottom - rc->top - 19) / 2));

			// Border
			if ((edPtr->lFlags & EDIT_BORDER) != 0)
			{
				POINT		point[5];

				// Select pen
				WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_SOLID, 1);
				
				// Draw box & 2 lines
				point[0].x = rc->left;
				point[0].y = rc->top;
				point[1].x = rc->right - 20;
				point[1].y = rc->top;
				point[2].x = rc->right - 20;
				point[2].y = rc->bottom;
				point[3].x = rc->left;
				point[3].y = rc->bottom;
				point[4].x = rc->left;
				point[4].y = rc->top;
				WinLine(knpV->mvIdEditWin, (POINT _far *)point, 4);
			}
			rc2.bottom-=20;
		}

		// Dessine le tour
		if (edPtr->lFlags & EDIT_BORDER)
			WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_SOLID, 1);
		else
			WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_DOT, 1);
		WinRect(knpV->mvIdEditWin, rc);
	}
	
	// "Entry zone" text
    hFont=CreateFontIndirect16(&edPtr->lfEditFont);
    if (hFont!=0)
    {   
    	m=M_EDITORDISPLAY1; 
    	if (edPtr->lFlags&EDIT_MULTILINE)
			m = M_EDITORDISPLAY2;
		if ( (edPtr->lFlags & EDIT_3DLOOK) != 0 )
			rc2.top += 2;
		strBuf=(npchar)LocalAlloc(LPTR, 128);
		if (strBuf!=0)
		{
			LoadString(hInstLib, m, strBuf, 127);
	    	WinPasteText(knpV->mvIdEditWin, hFont, &rc2, (fpchar)strBuf, textColor, TA_LEFT|TA_TOP);
	    	LocalFree((HLOCAL)strBuf);
		}
    	DeleteObject(hFont);
	}
	
	// Hide on start
	if ((edPtr->lFlags & EDIT_HIDEONSTART) != 0)
	{
		HBRUSH		hBrush;
	
		// Hatch the windows
		hBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 0));
		WinGraphMode(knpV->mvIdEditWin, TRANSPARENT);
		WinFillBr(knpV->mvIdEditWin, rc->left, rc->top, rc->right, rc->bottom, hBrush);
		DeleteObject(hBrush);

		// Select pen
		WinPen(knpV->mvIdEditWin, RGB(0, 0, 0), PS_SOLID, 1);

		// Draw a box
		WinRect(knpV->mvIdEditWin, rc);
	}
}



void WINAPI	 GetObjInfos (mv _far *knpV,fpedata edPtr,fpchar ObjName,fpchar ObjAuteur,fpchar ObjCopyright,fpchar ObjComment,fpchar ObjHttp)
{
	LoadString(hInstLib, IDST_OBJNAME, (LPSTR)ObjName, 255);
	LoadString(hInstLib, IDST_AUTHOR,ObjAuteur,255);
	LoadString(hInstLib, IDST_COPYRIGHT,ObjCopyright,255);
	LoadString(hInstLib, IDST_COMMENT,ObjComment,255);
	LoadString(hInstLib, IDST_HTTP,ObjHttp,255);
}

LPCSTR WINAPI DLLExport GetHelpFileName()
{
	return "Edit.chm";
}


BOOL WINAPI DLLExport GetProperties(LPMV mV, fpedata edPtr, BOOL bMasterItem)
{
	mV->mvCallFunction(edPtr, EF_INSERTPROPS, (LPARAM)Properties, PROPID_TAB_GENERAL, TRUE);
//	mV->mvCallFunction(edPtr, EF_REMOVEPROP, nID);

	return TRUE;
}
/*
void WINAPI DLLExport ReleaseProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
}
*/

LPVOID WINAPI DLLExport GetPropValue(LPMV mV, fpedata edPtr, UINT nPropID)
{
	switch (nPropID) 
	{
	case PROPID_BACKGROUND:
		return new CPropDWordValue(edPtr->crefEditFontBkColor);
	case PROPID_CASE:
		{
			int n=0;
			if (edPtr->lFlags&EDIT_UPPERCASE)
				n=1;
			if (edPtr->lFlags&EDIT_LOWERCASE)
				n=2;
			return new CPropDWordValue(n);
		}
	}
	return NULL;
}

void WINAPI DLLExport SetPropValue(LPMV mV, fpedata edPtr, UINT nPropID, LPVOID lParam)
{
	BOOL bRefresh = TRUE;
	CPropValue* pValue = (CPropValue*)lParam;

	switch (nPropID) 
	{
	case PROPID_BACKGROUND:
		edPtr->crefEditFontBkColor=((CPropDWordValue*)pValue)->m_dwValue;
		break;
	case PROPID_CASE:
		edPtr->lFlags&=~(EDIT_UPPERCASE|EDIT_LOWERCASE);
		switch (((CPropDWordValue*)pValue)->m_dwValue)
		{
		case 0:
			break;
		case 1:
			edPtr->lFlags|=EDIT_UPPERCASE;
			break;
		case 2:
			edPtr->lFlags|=EDIT_LOWERCASE;
			break;
		}
		break;
	default:
		bRefresh = FALSE;
		break;
	}
	if ( bRefresh )
		mV->mvCallFunction(edPtr, EF_INVALIDATEOBJECT, 0, 0, 0);
}

BOOL WINAPI DLLExport GetPropCheck(LPMV mV, fpedata edPtr, UINT nPropID)
{
	switch (nPropID) 
	{
	case PROPID_MULTILINE:
		return (edPtr->lFlags&EDIT_MULTILINE?TRUE:FALSE);
	case PROPID_TABSTOP:
		return (edPtr->lFlags&EDIT_TABSTOP?TRUE:FALSE);
	case PROPID_PASSWORD:
		return (edPtr->lFlags&EDIT_PASSWORD?TRUE:FALSE);
	case PROPID_SYSTEMCOLORS:
		return (edPtr->lFlags&EDIT_SYSCOLOR?TRUE:FALSE);
	case PROPID_TRANSPARENT:
		return (edPtr->lFlags&EDIT_TRANSP?TRUE:FALSE);
	case PROPID_BORDER:
		return (edPtr->lFlags&EDIT_BORDER?TRUE:FALSE);
	case PROPID_HIDEONSTART:
		return (edPtr->lFlags&EDIT_HIDEONSTART?TRUE:FALSE);
	case PROPID_READONLY:
		return (edPtr->lFlags&EDIT_READONLY?TRUE:FALSE);
	case PROPID_3DLOOK:
		return (edPtr->lFlags&EDIT_3DLOOK?TRUE:FALSE);
	case PROPID_HSCROLLBAR:
		return (edPtr->lFlags&EDIT_HSCROLLBAR?TRUE:FALSE);
	case PROPID_HAUTOSCROLL:
		return (edPtr->lFlags&EDIT_HSCROLLAUTOSCROLL?TRUE:FALSE);
	case PROPID_VSCROLLBAR:
		return (edPtr->lFlags&EDIT_VSCROLLBAR?TRUE:FALSE);
	case PROPID_VAUTOSCROLL:
		return (edPtr->lFlags&EDIT_VSCROLLAUTOSCROLL?TRUE:FALSE);
	}
	return NULL;
}

void WINAPI DLLExport SetPropCheck(LPMV mV, fpedata edPtr, UINT nPropID, BOOL nCheck)
{
	BOOL bRefresh = TRUE;
	switch (nPropID) 
	{
	case PROPID_HSCROLLBAR:
		edPtr->lFlags&=~EDIT_HSCROLLBAR;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_HSCROLLBAR;
		break;
	case PROPID_HAUTOSCROLL:
		edPtr->lFlags&=~EDIT_HSCROLLAUTOSCROLL;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_HSCROLLAUTOSCROLL;
		break;
	case PROPID_VSCROLLBAR:
		edPtr->lFlags&=~EDIT_VSCROLLBAR;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_VSCROLLBAR;
		break;
	case PROPID_VAUTOSCROLL:
		edPtr->lFlags&=~EDIT_VSCROLLAUTOSCROLL;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_VSCROLLAUTOSCROLL;
		break;
	case PROPID_MULTILINE:
		edPtr->lFlags&=~EDIT_MULTILINE;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_MULTILINE;
		mV->mvCallFunction(edPtr, EF_REFRESHPROP, PROPID_TRANSPARENT, 0, 0);
		mV->mvCallFunction(edPtr, EF_REFRESHPROP, PROPID_VSCROLLBAR, 0, 0);
		mV->mvCallFunction(edPtr, EF_REFRESHPROP, PROPID_VAUTOSCROLL, 0, 0);
		break;
	case PROPID_TABSTOP:
		edPtr->lFlags&=~EDIT_TABSTOP;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_TABSTOP;
		break;
	case PROPID_PASSWORD:
		edPtr->lFlags&=~EDIT_PASSWORD;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_PASSWORD;
		break;
	case PROPID_SYSTEMCOLORS:
		edPtr->lFlags&=~EDIT_SYSCOLOR;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_SYSCOLOR;
		break;
	case PROPID_TRANSPARENT:
		edPtr->lFlags&=~EDIT_TRANSP;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_TRANSP;
		break;
	case PROPID_BORDER:
		edPtr->lFlags&=~EDIT_BORDER;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_BORDER;
		break;
	case PROPID_HIDEONSTART:
		edPtr->lFlags&=~EDIT_HIDEONSTART;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_HIDEONSTART;
		break;
	case PROPID_READONLY:
		edPtr->lFlags&=~EDIT_READONLY;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_READONLY;
		break;
	case PROPID_3DLOOK:
		edPtr->lFlags&=~EDIT_3DLOOK;
		if ( nCheck == 1) 
			edPtr->lFlags|=EDIT_3DLOOK;
		break;
	default:
		bRefresh = FALSE;
		break;
	}
	if ( bRefresh )
		mV->mvCallFunction(edPtr, EF_INVALIDATEOBJECT, 0, 0, 0);
}

BOOL WINAPI DLLExport IsPropEnabled(LPMV mV, fpedata edPtr, UINT nPropID)
{
	switch (nPropID)
	{
	case PROPID_VSCROLLBAR:
	case PROPID_VAUTOSCROLL:
	case PROPID_TRANSPARENT:
		return (edPtr->lFlags&EDIT_MULTILINE)?TRUE:FALSE;
	}
	return TRUE;
}

LPWORD WINAPI DLLExport GetDebugTree(fprdata rdPtr)
{
	return DbTree;
}

void WINAPI DLLExport GetDebugItem(LPSTR pBuffer, fprdata rdPtr, int id)
{
	if (id==DB_STRING)
	{
		char pTemp[DB_BUFFERSIZE];
		char pString[DB_BUFFERSIZE];
		LoadString(hInstLib, IDS_DBSTRING, pString, DB_BUFFERSIZE);
		GetWindowText(rdPtr->hWnd, pTemp, DB_BUFFERSIZE);
		wsprintf(pBuffer, pString, pTemp);
	}
}

void WINAPI DLLExport EditDebugItem(fprdata rdPtr, int id)
{
	if (id==DB_STRING)
	{
		EditDebugInfo dbi;
		char buffer[256];

		GetWindowText(rdPtr->hWnd, buffer, 256);
		dbi.pText=buffer;
		dbi.lText=256;
		dbi.pTitle=NULL;
		long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITTEXT, 0, (LPARAM)&dbi);
		if (ret)
		{
			SetWindowText(rdPtr->hWnd, dbi.pText);
		}
	}
}


//==================================================================//
//																	//
//				Functions not called in run only					//
//																	//
//==================================================================//
#else	// RUN_ONLY


DWORD WINAPI  GetTextCaps(mv _far *knpV, fpedata edPtr)
{
	return 0;
}

BOOL WINAPI  GetTextFont(mv _far *knpV, fpedata edPtr, LPLOGFONT plf, LPSTR pStyle, UINT cbSize)
{
	return TRUE;
}

BOOL WINAPI  SetTextFont(mv _far *knpV, fpedata edPtr, LPLOGFONT plf, LPCSTR pStyle)
{
	return TRUE;
}

COLORREF WINAPI  GetTextClr(mv _far *knpV, fpedata edPtr)
{
	return 0;
}

void WINAPI  SetTextClr(mv _far *knpV, fpedata edPtr, COLORREF color)
{
}


void WINAPI	 GetObjInfos (mv _far *knpV,fpedata edPtr,fpchar ObjName,fpchar ObjAuteur,fpchar ObjCopyright,fpchar ObjComment,fpchar ObjHttp)
{
}

LPCSTR WINAPI DLLExport GetHelpFileName()
{
	return NULL;
}

HMENU WINAPI  GetConditionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return NULL;
}

HMENU WINAPI  GetActionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return NULL;
}

HMENU WINAPI  GetExpressionMenu(mv _far *knpV, fpObjInfo oiPtr, fpedata edPtr)
{
	return NULL;
}

void WINAPI  GetConditionTitle(mv _far *knpV, short code, short param, fpchar strBuf, short maxLen)
{
}

void WINAPI  GetActionTitle(mv _far *knpV, short code, short param, fpchar strBuf, short maxLen)
{
}

void WINAPI  GetExpressionTitle(mv _far *knpV, short code, fpchar strBuf, short maxLen)
{
}

short WINAPI  GetConditionCodeFromMenu(mv _far *knpV, short menuId)
{
	return -1;
}

short WINAPI  GetActionCodeFromMenu(mv _far *knpV, short menuId)
{
	return -1;
}

short WINAPI  GetExpressionCodeFromMenu(mv _far *knpV, short menuId)
{
	return -1;
}

infosEvents _far * WINAPI  GetConditionInfos(mv _far *knpV, short code)
{
	return NULL;
}

infosEvents _far * WINAPI  GetActionInfos(mv _far *knpV, short code)
{
	return NULL;
}

infosEvents _far * WINAPI  GetExpressionInfos(mv _far *knpV, short code)
{
	return NULL;
}

void WINAPI  GetConditionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{
}

void WINAPI  GetActionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{
}

void WINAPI  GetExpressionString(mv _far *knpV, short code, fpchar strPtr, short maxLen)
{
}

int WINAPI  CreateObject(mv _far *knpV, fpLevObj loPtr, fpedata edPtr)
{
	return 0;
}

int WINAPI  ExportTexts ( HFILE hf, fpedata edPtr, LPVOID lpFncs )
{
	return 0;
}

int WINAPI  ImportTexts ( HFILE hf, fpedata edPtr, LPVOID lpFncs )
{
	return 0;
}

void WINAPI  GetObjectRect(mv _far *knpV, RECT FAR *rc, fpLevObj loPtr, fpedata edPtr)
{
}

void WINAPI  EditorDisplay(mv _far *knpV, fpObjInfo oiPtr, fpLevObj loPtr, fpedata edPtr, RECT FAR *rc)
{
}

BOOL WINAPI DLLExport SetEditSize(LPMV mv, fpedata edPtr, int cx, int cy)
{
	return FALSE;
}

BOOL WINAPI DLLExport GetProperties(LPMV mV, fpedata edPtr, BOOL bMasterItem)
{
	return FALSE;
}

LPVOID WINAPI DLLExport GetPropValue(LPMV mV, fpedata edPtr, UINT nPropID)
{
	return NULL;
}

void WINAPI DLLExport SetPropValue(LPMV mV, fpedata edPtr, UINT nPropID, LPVOID lParam)
{
}

BOOL WINAPI DLLExport GetPropCheck(LPMV mV, fpedata edPtr, UINT nPropID)
{
	return FALSE;
}

void WINAPI DLLExport SetPropCheck(LPMV mV, fpedata edPtr, UINT nPropID, BOOL nCheck)
{
}

BOOL WINAPI DLLExport IsPropEnabled(LPMV mV, fpedata edPtr, UINT nPropID)
{
	return FALSE;
}

LPWORD WINAPI DLLExport GetDebugTree(fprdata rdPtr)
{
	return NULL;
}

void WINAPI DLLExport GetDebugItem(LPSTR pBuffer, fprdata rdPtr, int id)
{
}

void WINAPI DLLExport EditDebugItem(fprdata rdPtr, int id)
{
}



#endif	// RUN_ONLY


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Library entry point																		//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL WINAPI DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
		// DLL is attaching to the address space of the current process.
		case DLL_PROCESS_ATTACH:
			hInstLib = hDLL; // Store HINSTANCE
			break;

		// A new thread is being created in the current process.
		case DLL_THREAD_ATTACH:
			break;

		// A thread is exiting cleanly.
		case DLL_THREAD_DETACH:
			break;

		// The calling process is detaching the DLL from its address space.
	    case DLL_PROCESS_DETACH:
	    	// Virer les objets??
			break;
	}

	return TRUE;
}





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Demande d'infos a propos de l'objet														//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" DWORD WINAPI  GetInfos(int info)
{
	switch (info)
	{
		case KGI_VERSION:
			return EXT_VERSION1;
#ifdef VITALIZE
		case KGI_PLUGIN:
			return EXT_PLUGIN_VERSION2;		// Return plug-in version
		case KGI_ATX_CONTROL:
			return EXT_ATXCTRL_VERSION1;		// Return ActiveX version
#endif

		default:
			return 0;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Update Object's Version																	//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////
	
HGLOBAL WINAPI  UpdateEditStructure(mv __far *knpV, void __far * OldEdPtr)
{
	return NULL;
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		RETURNS ADRESSES OF JUMP TABLES AND INFORMATIONS ABOUT THE RUN-OBJECT												//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		Jump table to conditions																//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long ( WINAPI * ConditionJumps[] ) (fprdata rdPtr,long param1,long param2) = 
			{ 
			IsVisible,
			IsEnable,
			CanUndo,
			WasModified,
			HaveFocus,
			IsNumber,
			IsSelected,
			0
			};
	




//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		Jump table to actions																	//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short ( WINAPI * ActionJumps[] ) (fprdata rdPtr,long param1,long param2) =
			{
			LoadText,
			LoadTextSelect,
			SaveText,
			SaveTextSelect,
			SetText,
			ReplaceSelection,
			Cut,
			Copy,
			Paste,
			Clear,
			Undo,
			ClearUndoBuffer,
			Show,
			Hide,
			SetFontSelect,
			SetColorSelect,
			Activate,
			Enable,
			Disable,
			ReadOnlyOn,
			ReadOnlyOff,
			TextModified,
			TextNotModified,
			LimitTextSize,
			SetPosition,
			SetXPosition,
			SetYPosition,
			SetSize,
			SetXSize,
			SetYSize,
			Desactivate,
			ScrollToTop,
			ScrollToLine,
			ScrollToEnd,
			SetColor,
			SetBkdColor,
			0
			};
	




//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		Jump table to expressions																//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

long ( WINAPI * ExpressionJumps[] ) (fprdata rdPtr,long param) = 
			{     
			GetText,
			GetSelection,
			GetXPosition,
			GetYPosition,
			GetXSize,
			GetYSize,
			GetValue,
			GetFirstLine,
			GetLineCount,
			GetColor,
			GetBkdColor,
			0
			};





//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
// 		get infos on object																		//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

short WINAPI  GetRunObjectInfos(mv _far *knpV, fpKpxRunInfos infoPtr)
{            

	infoPtr->conditions = (LPBYTE)ConditionJumps;
	infoPtr->actions = (LPBYTE)ActionJumps;
	infoPtr->expressions = (LPBYTE)ExpressionJumps;
	
	infoPtr->numOfConditions = CND_LAST;
	infoPtr->numOfActions = ACT_LAST;
	infoPtr->numOfExpressions = EXP_LAST;
	
	infoPtr->editDataSize = MAX_EDITSIZE;
	infoPtr->editFlags = OEFLAGS;

	infoPtr->windowProcPriority = WINDOWPROC_PRIORITY;
		
	// Voir la documentation des CCX
	infoPtr->editPrefs = OEPREFS;

	// Un identifier de nom, qui sera reperable en mode runtime (ce que tu voulais je crois)		
	infoPtr->identifier=IDENTIFIER;
	
	// La version courante de l'extension, voir plus loin
	infoPtr->version = KCX_CURRENT_VERSION;
	
	return TRUE;
}
