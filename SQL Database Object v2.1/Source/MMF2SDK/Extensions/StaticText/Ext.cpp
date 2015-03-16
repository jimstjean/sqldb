// ============================================================================
//
// Multimedia Fusion Static Text object
// 
// ============================================================================

// To define if you use the new MMF features
#define	IN_EXT_VERSION2

#define COXSDK	// Internal

// ASSERT
#define WANT_ASSERT
#ifdef _DEBUG
//#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif;

#include "include.h"
#include "props.h"

// Object identifier "STT0"
// This identifier must be unique! You must change it!
// Just find another name and convert it into ASCII codes
#define IDENTIFIER	0x53545430

// Compatibility with PRO version
#define IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20 && ((v->mvGetVersion() & MMFVERFLAG_MASK) & MMFVERFLAG_PRO) != 0)
//#define IS_COMPATIBLE(v) (TRUE)

// Prototype of setup procedure
LRESULT CALLBACK MyWindowProc(HWND hWnd, UINT msgType, WPARAM wParam, LPARAM lParam);

// Instance of kcx
HINSTANCE hInstLib;
//HINSTANCE hInstanceApp;

char szEmptyString[] = "";

#define ID_STATICTEXT	2001

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// 0-Menu identifier
// 1-Display string identifier
// 2-Code
// 3-Flags
// 4-Number of parameters
// 5-Type of parameter #1
// 6-Type of parameter #2
// etc...
// x-Title of parameter 1 entry box
// x+1-Title of parameter 2 entry box
// etc...
// x+n-Title of parameter n entry box

// Definitions of parameters for each condition
eventInformations2 conditionsInfos[]=
		{
		IDMN_CONDITIONS_LCLICK, IDS_CONDITION_LCLICK, CND_LCLICK,						0, 0,
		IDMN_CONDITIONS_RCLICK, IDS_CONDITION_RCLICK, CND_RCLICK,						0, 0,
		IDMN_CONDITIONS_DBLCLICK, IDS_CONDITION_DBLCLICK, CND_DBLCLICK,					0, 0,
		IDMN_CONDITIONS_ISVISIBLE, IDS_CONDITION_ISVISIBLE, CND_ISVISIBLE,				EVFLAGS_ALWAYS|EVFLAGS_NOTABLE, 0,
		};

// Definitions of parameters for each action
eventInformations2 actionsInfos[]=
		{
		IDMN_ACTION_SHOW, IDS_ACTION_SHOW, ACT_SHOW,									0, 0, 
		IDMN_ACTION_HIDE, IDS_ACTION_HIDE, ACT_HIDE,									0, 0, 
		IDMN_ACTION_SETTEXT, IDS_ACTION_SETTEXT, ACT_SETTEXT,							0, 1, PARAM_EXPSTRING, IDS_SETTEXT,
		IDMN_ACTION_SETWIDTH, IDS_ACTION_SETWIDTH, ACT_SETWIDTH,						0, 1, PARAM_EXPRESSION, IDS_SETWIDTH,
		IDMN_ACTION_SETHEIGHT, IDS_ACTION_SETHEIGHT, ACT_SETHEIGHT,						0, 1, PARAM_EXPRESSION, IDS_SETHEIGHT,
		IDMN_ACTION_SETTEXTCOLOR, IDS_ACTION_SETTEXTCOLOR, ACT_SETTEXTCOLOR,			0, 1, PARAM_COLOUR, 0,
		IDMN_ACTION_SETBACKCOLOR, IDS_ACTION_SETBACKCOLOR, ACT_SETBACKCOLOR,			0, 1, PARAM_COLOUR, 0,
		};

// Definitions of parameters for each expression
eventInformations2 expressionsInfos[]=
		{
		IDMN_EXPRESSIONS_GETWIDTH, IDS_EXPRESSION_GETWIDTH, EXP_GETWIDTH,				0, 0, 
		IDMN_EXPRESSIONS_GETHEIGHT, IDS_EXPRESSION_GETHEIGHT, EXP_GETHEIGHT,			0, 0, 
		IDMN_EXPRESSIONS_GETTEXT, IDS_EXPRESSION_GETTEXT, EXP_GETTEXT,					EXPFLAG_STRING, 0, 
		};


#ifndef RUN_ONLY

// PROPERTIES /////////////////////////////////////////////////////////////////

enum {
	PROPID_SETTINGS = PROPID_EXTITEM_CUSTOM_FIRST,
	PROPID_STYLES,	
	PROPID_BACKCOLOR,	
	PROPID_TEXT,
	PROPID_BORDER_GROUP,
	PROPID_BORDER,
	PROPID_CLIENT,
	PROPID_SINGLELINE,
	PROPID_VCENTER,
	PROPID_STATIC,
	PROPID_PATHELLIPSIS,
	PROPID_ENDELLIPSIS,
	PROPID_VISIBLE
};

LPCSTR StylesList[] = {
	(LPCSTR)0,								// Reserved
	MAKEINTRESOURCE(IDS_LEFT),	
	MAKEINTRESOURCE(IDS_CENTER),	
	MAKEINTRESOURCE(IDS_RIGHT),	
	NULL
};

PropData Properties[] = {
	PropData_EditString	(PROPID_TEXT,		IDS_PROP_TEXT,			IDS_PROP_TEXT_INFO),
	PropData_ComboBox	(PROPID_STYLES,		IDS_PROP_STYLES,		IDS_PROP_STYLES_INFO, StylesList),
	PropData_Color		(PROPID_BACKCOLOR,	IDS_PROP_BACKCOLOR,		IDS_PROP_BACKCOLOR_INFO),
//	PropData_CheckBox	(PROPID_SINGLELINE, IDS_PROP_SINGLELINE,	IDS_PROP_SINGLELINE_INFO),
	PropData_CheckBox	(PROPID_VCENTER,	IDS_PROP_VCENTER,		IDS_PROP_VCENTER_INFO),
	PropData_CheckBox	(PROPID_PATHELLIPSIS,IDS_PROP_PATHELLIPSIS,	IDS_PROP_PATHELLIPSIS_INFO),
	PropData_CheckBox	(PROPID_ENDELLIPSIS,IDS_PROP_ENDELLIPSIS,	IDS_PROP_ENDELLIPSIS_INFO),

	PropData_Group		(PROPID_BORDER_GROUP,IDS_PROP_BORDERGROUP,	IDS_PROP_BORDERGROUP),
	PropData_CheckBox	(PROPID_BORDER,		IDS_PROP_BORDER,		IDS_PROP_BORDER_INFO,),
	PropData_CheckBox	(PROPID_CLIENT,		IDS_PROP_CLIENT,		IDS_PROP_CLIENT_INFO),
	PropData_CheckBox	(PROPID_STATIC,		IDS_PROP_STATIC,		IDS_PROP_STATIC_INFO),
	PropData_CheckBox	(PROPID_VISIBLE,	IDS_PROP_VISIBLE,		IDS_PROP_VISIBLE_INFO),

	PropData_End()
};

#endif






// ============================================================================
//
// OBJECT HANDLING ROUTINES WHEN GAME IS RUNNED	
// 
// ============================================================================

// --------------------
// GetRunObjectDataSize
// --------------------
// Returns the size of the runtime datazone of the object
// 
ushort WINAPI DLLExport GetRunObjectDataSize(fprh rhPtr, LPEDATA edPtr)
{
	return(sizeof(RUNDATA));
}

/*
// ---------------
// StartApp
// ---------------
void WINAPI DLLExport StartApp(mv _far *knpV, DWORD dwReserved)
{
}

// ---------------
// StartFrame
// ---------------
void WINAPI DLLExport StartFrame(mv _far *knpV, DWORD dwReserved, int nFrame)
{
}

// ---------------
// EndFrame
// ---------------
void WINAPI DLLExport EndFrame(mv _far *knpV, DWORD dwReserved, int nFrame)
{
}

// ---------------
// EndApp
// ---------------
void WINAPI DLLExport EndApp(mv _far *knpV, DWORD dwReserved)
{
}
*/


// ---------------
// CreateRunObject
// ---------------
// The routine where the object is actually created
// 
short WINAPI DLLExport CreateRunObject(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr)
{
	// To get rhPtr
    LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;

	// Get parameters
	rdPtr->rHo.hoImgWidth = edPtr->sx;
	rdPtr->rHo.hoImgHeight = edPtr->sy;
	rdPtr->hBackBrush=CreateSolidBrush(edPtr->backColor);
	rdPtr->backColor=edPtr->backColor;
	rdPtr->fontColor=edPtr->fontColor;

	DWORD style=edPtr->styles;
	switch (edPtr->alignement)
	{
	case 0:
		style|=SS_LEFT;
		break;
	case 1:
		style|=SS_CENTER;
		break;
	case 2:
		style|=SS_RIGHT;
		break;
	}

	rdPtr->hWnd = CreateWindowEx(edPtr->exStyles, "STATIC", edPtr->text, WS_CHILD | SS_NOTIFY | style, 
						rdPtr->rHo.hoX - rhPtr->rhWindowX, rdPtr->rHo.hoY - rhPtr->rhWindowY, rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, 
						rhPtr->rhHEditWin, (HMENU)ID_STATICTEXT, rhPtr->rh4.rh4Instance, NULL);

	if (edPtr->styles&WS_VISIBLE)
		rdPtr->bVisible=TRUE;
	else
		rdPtr->bVisible=FALSE;

	if ( rdPtr->hWnd )
	{
		// Insert C&C structures
		rdPtr->WindowNumber = 1;
		rdPtr->rHo.hoOffsetToWindows=(short)((fpchar)&rdPtr->WindowNumber-(fpchar)rdPtr);
		callRunTimeFunction(rdPtr, RFUNCTION_SUBCLASSWINDOW, 0, 0);

		// Branch window procedure
		SetWindowLong(rdPtr->hWnd, GWL_USERDATA, (long)rdPtr);
		rdPtr->OldWindowProc=(WNDPROC)SetWindowLong(rdPtr->hWnd, GWL_WNDPROC, (long)MyWindowProc);

		// Create & set font
        rdPtr->hFont = CreateFontIndirect(&edPtr->textLf);
		SendMessage(rdPtr->hWnd, WM_SETFONT, (WPARAM)rdPtr->hFont, MAKELONG(TRUE, 0));

		rdPtr->styles=edPtr->styles;

		InvalidateRect(rdPtr->hWnd, NULL, TRUE);
	}

	// No errors
	return 0;
}

// ----------------
// DestroyRunObject
// ----------------
// Destroys the run-time object
// 
short WINAPI DLLExport DestroyRunObject(LPRDATA rdPtr, long fast)
{
	// Detruit le controle
	DestroyWindow(rdPtr->hWnd);
	rdPtr->hWnd=0;

	// Detruit la fonte
	if (rdPtr->hFont!=0)
	{
		DeleteObject(rdPtr->hFont);
		rdPtr->hFont=0;
	}
	// Detruit la brush
	if (rdPtr->hBackBrush)
	{
		DeleteObject(rdPtr->hBackBrush);
	}

	// No errors
	return 0;
}


// ----------------
// HandleRunObject
// ----------------
// Called (if you want) each loop, this routine makes the object live
// 
short WINAPI DLLExport HandleRunObject(LPRDATA rdPtr)
{
	if (rdPtr->clickFlag)
	{
		if (rdPtr->clickFlag&CLICKFLAG_LBUTTON)
		{
			callRunTimeFunction(rdPtr, RFUNCTION_PUSHEVENTSTOP, CND_LCLICK, 0);
			rdPtr->clickFlag&=~CLICKFLAG_LBUTTON;
		}
		if (rdPtr->clickFlag&CLICKFLAG_RBUTTON)
		{
			callRunTimeFunction(rdPtr, RFUNCTION_PUSHEVENTSTOP, CND_RCLICK, 0);
			rdPtr->clickFlag&=~CLICKFLAG_RBUTTON;
		}
		if (rdPtr->clickFlag&CLICKFLAG_DBLCLICK)
		{
			callRunTimeFunction(rdPtr, RFUNCTION_PUSHEVENTSTOP, CND_DBLCLICK, 0);
			rdPtr->clickFlag&=~CLICKFLAG_DBLCLICK;
		}
	}
	return 0;
}

// ----------------------
// GetImageInfosRunObject
// ----------------------
// Returns the current size of the object
// Only necessary if the size of your object can change in runtime. Otherwise, 
// remove this routine...
short WINAPI DLLExport GetImageInfosRunObject (LPRDATA rdPtr)
{
	return TRUE;
}

// ----------------
// DisplayRunObject
// ----------------
// Draw the object in the application screen.
// 
short WINAPI DLLExport DisplayRunObject(LPRDATA rdPtr)
{
	fprh rhPtr = rdPtr->rHo.hoAdRunHeader;
	RECT rc;
	GetWindowRect(rdPtr->hWnd, &rc);

	HWND hParent = GetParent(rdPtr->hWnd);
	if ( hParent != NULL )
	{
		ScreenToClient(hParent, (LPPOINT)&rc.left);
		ScreenToClient(hParent, (LPPOINT)&rc.right);
	}

	if ( rc.left != rdPtr->rHo.hoX - rhPtr->rhWindowX ||
		 rc.top != rdPtr->rHo.hoY - rhPtr->rhWindowY ||
		 rc.right - rc.left != rdPtr->rHo.hoImgWidth || 
		 rc.bottom - rc.top != rdPtr->rHo.hoImgHeight )
	{
		SetWindowPos(rdPtr->hWnd, 0, 
					rdPtr->rHo.hoX - rhPtr->rhWindowX, rdPtr->rHo.hoY - rhPtr->rhWindowY, 
					rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, SWP_NOZORDER);
	}

	// Ok
  	return 0;
}


// ----------------
// ReInitRunObject
// ----------------
// Re-initialize the object after a fade-in. 
// 
short WINAPI DLLExport ReInitRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}


// ----------------
// PauseRunObject
// ----------------
// Enters the pause mode
// 
short WINAPI DLLExport PauseRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}


// -----------------
// ContinueRunObject
// -----------------
// Quits the pause mode
// 
short WINAPI DLLExport ContinueRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}


// -----------------
// ChangeRunData
// -----------------
// Called when the address of the runtime structure changes
// 
short WINAPI DLLExport ChangeRunData(LPRDATA rdOld, LPRDATA rdNew)
{            
	// OK
	return 0; 
}

// Detournement de la routine de window du controle
////////////////////////////////////////////////////
LRESULT CALLBACK MyWindowProc(HWND hWnd, UINT msgType, WPARAM wParam, LPARAM lParam)
{
	LPRDATA rdPtr=(LPRDATA)GetWindowLong(hWnd, GWL_USERDATA);
	LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;

	switch (msgType)
	{
	case WM_LBUTTONDOWN:
		{
			rdPtr->LClickCount = rhPtr->rh4.rh4EventCount;
			rdPtr->clickFlag|=CLICKFLAG_LBUTTON;
		}
		break;
	case WM_RBUTTONDOWN:
		{
			rdPtr->RClickCount = rhPtr->rh4.rh4EventCount;
			rdPtr->clickFlag|=CLICKFLAG_RBUTTON;
		}
		break;
	case WM_LBUTTONDBLCLK:
		{
			rdPtr->DblClickCount = rhPtr->rh4.rh4EventCount;
			rdPtr->clickFlag|=CLICKFLAG_DBLCLICK;
		}
		break;
	}
	return CallWindowProc(rdPtr->OldWindowProc, hWnd, msgType, wParam, lParam);
}
// Fonction de detournement de la fonction Windows principale
/////////////////////////////////////////////////////////////
LPRDATA GetRdPtr(HWND hwnd, fprh rhPtr)
{
	return (LPRDATA)GetProp(hwnd, (LPCSTR)rhPtr->rh4.rh4AtomRd);
}

LRESULT CALLBACK DLLExport WindowProc(fprh rhPtr, HWND hWnd, UINT msgType, WPARAM wParam, LPARAM lParam)
{
	LPRDATA rdPtr = NULL;

	// It's for me ?
	switch (msgType)
	{
	case WM_CTLCOLORSTATIC:
		{
			HWND hWndControl=(HWND)lParam;
			rdPtr=GetRdPtr(hWndControl, rhPtr);
			if (rdPtr==NULL) 
				break;
			HDC hDC=(HDC)wParam;
			SelectObject(hDC, rdPtr->hBackBrush);
			SetBkColor(hDC, rdPtr->backColor);
			SetTextColor(hDC, rdPtr->fontColor);
			rhPtr->rh4.rh4KpxReturn = (long)rdPtr->hBackBrush;
			return REFLAG_MSGRETURNVALUE;
		}
		break;
	}

	return 0;
}

// ============================================================================
//
// TEXT ROUTINES
// 
// ============================================================================
void WINAPI GetRunObjectFont(LPRDATA rdPtr, LPLOGFONT pLf)
{
	GetObject(rdPtr->hFont, sizeof(LOGFONT), pLf);
}
void WINAPI SetRunObjectFont(LPRDATA rdPtr, LPLOGFONT pLf, RECT* pRc)
{
	HFONT hFont = CreateFontIndirect(pLf);
	if (hFont!=0)
	{
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
COLORREF WINAPI GetRunObjectTextColor(LPRDATA rdPtr)
{
	return rdPtr->fontColor;
}
void WINAPI SetRunObjectTextColor(LPRDATA rdPtr, COLORREF rgb)
{
	rdPtr->fontColor=rgb;
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);
}

// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Condition_LClick(LPRDATA rdPtr, long param1, long param2)
{
	// Si condition placee en premier: toujours vrai!
	if (rdPtr->rHo.hoFlags & HOF_TRUEEVENT)
		return TRUE;

	// Si condition en second, regarder le numero de la boucle
    LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;
	if (rhPtr->rh4.rh4EventCount == rdPtr->LClickCount)
		return TRUE;

	return FALSE;
}
long WINAPI DLLExport Condition_RClick(LPRDATA rdPtr, long param1, long param2)
{
	// Si condition placee en premier: toujours vrai!
	if (rdPtr->rHo.hoFlags & HOF_TRUEEVENT)
		return TRUE;

	// Si condition en second, regarder le numero de la boucle
    LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;
	if (rhPtr->rh4.rh4EventCount == rdPtr->RClickCount)
		return TRUE;

	return FALSE;
}
long WINAPI DLLExport Condition_DblClick(LPRDATA rdPtr, long param1, long param2)
{
	// Si condition placee en premier: toujours vrai!
	if (rdPtr->rHo.hoFlags & HOF_TRUEEVENT)
		return TRUE;

	// Si condition en second, regarder le numero de la boucle
    LPRH rhPtr = rdPtr->rHo.hoAdRunHeader;
	if (rhPtr->rh4.rh4EventCount == rdPtr->DblClickCount)
		return TRUE;

	return FALSE;
}
long WINAPI DLLExport Condition_IsVisible(LPRDATA rdPtr, long param1, long param2)
{
	return rdPtr->bVisible;
}

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport Action_Hide(LPRDATA rdPtr, long param1, long param2)
{
	ShowWindow(rdPtr->hWnd, SW_HIDE);
	rdPtr->bVisible=FALSE;
	return 0;
}
short WINAPI DLLExport Action_Show(LPRDATA rdPtr, long param1, long param2)
{
	ShowWindow(rdPtr->hWnd, SW_SHOW);
	rdPtr->bVisible=TRUE;
	return 0;
}

// Largeur et hauteur
//////////////////////
short WINAPI DLLExport Action_SetWidth(LPRDATA rdPtr, long param1, long param2)
{
	if (param1>0)
		rdPtr->rHo.hoImgWidth = (int)param1;

	callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	return 0;
}

short WINAPI DLLExport Action_SetHeight(LPRDATA rdPtr, long param1, long param2)
{
	if (param1>0)
		rdPtr->rHo.hoImgHeight = (int)param1;

	callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	return 0;
}

short WINAPI DLLExport Action_SetText(LPRDATA rdPtr, long param1, long param2)
{
	LPSTR pStr=(LPSTR)param1;
	SetWindowText(rdPtr->hWnd, pStr);
	return 0;
}

short WINAPI DLLExport Action_SetTextColor(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->fontColor=param1;
	
	InvalidateRect(rdPtr->hWnd, NULL, TRUE);
	return 0;
}

short WINAPI DLLExport Action_SetBackColor(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->backColor=param1;
	DeleteObject(rdPtr->hBackBrush);
	rdPtr->hBackBrush=CreateSolidBrush(rdPtr->backColor);

	InvalidateRect(rdPtr->hWnd, NULL, TRUE);
	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Expression_GetWidth(LPRDATA rdPtr,long param1)
{
	return rdPtr->rHo.hoImgWidth;
}
		
long WINAPI DLLExport Expression_GetHeight(LPRDATA rdPtr,long param1)
{
	return rdPtr->rHo.hoImgHeight;
}

long WINAPI DLLExport Expression_GetText(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_STRING;

	int l=GetWindowTextLength(rdPtr->hWnd);

	LPSTR pDest=(LPSTR)callRunTimeFunction(rdPtr, RFUNCTION_GETSTRINGSPACE_EX, 0, l+4);

	if (pDest!=NULL)
	{
		GetWindowText(rdPtr->hWnd, pDest, l+1);
		return (long)pDest;
	}
	return (long)"";
}

// ============================================================================
//
// ROUTINES USED DURING EDITION-TIME
// 
// ============================================================================


// ============================================================================
//
// LIBRARY ENTRY & QUIT POINTS, 16 & 32 BITS
// 
// ============================================================================

// -----------------
// Entry points
// -----------------
// Usually you do not need to do any initialization here: you will prefer to 
// do them in "Initialize"

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
			break;
	}

	return TRUE;
}




// ============================================================================
//
// ROUTINES USED UNDER FRAME EDITOR
// 
// ============================================================================

// -----------------
// Initialize
// -----------------
// Where you want to do COLD-START initialization. Only called ONCE per application.
// 
int WINAPI DLLExport Initialize(mv _far *knpV, int quiet)
{
	// No errors
	return 0;
}

// -----------------
// Free
// -----------------
// Where you want to kill and initialized data opened in the above routine
// Called ONCE per application, just before freeing the DLL.
// 
int WINAPI DLLExport Free(mv _far *knpV)
{
//	CoUninitialize();

	// No errors
	return 0;
}


// -----------------
// Get Infos
// -----------------
// You should not change this routine.
// 
extern "C" DWORD WINAPI DLLExport GetInfos(int info)
{
	switch (info)
	{
		case KGI_VERSION:
			return EXT_VERSION2;
		case KGI_PRODUCT:
			return PRODUCT_VERSION_HOME;
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

// --------------------
// UpdateEditStructure
// --------------------
// For you to update your object structure to newer versions
// 
HGLOBAL WINAPI DLLExport UpdateEditStructure(mv __far *knpV, void __far * OldEdPtr)
{
	// We do nothing here
	return 0;
}

// --------------------
//
// MMF 1.5 : Text functions
//
// --------------------
DWORD WINAPI DLLExport GetTextCaps(mv _far *knpV, LPEDATA edPtr)
{
	return (TEXT_FONT | TEXT_COLOR);
}

BOOL WINAPI DLLExport GetTextFont(mv _far *knpV, LPEDATA edPtr, LPLOGFONT plf, LPSTR pStyle, UINT cbSize)
{
	memcpy(plf, &edPtr->textLf, sizeof(LOGFONT));
	strncpy(pStyle, edPtr->textFnStyle, min(40,cbSize));
	return TRUE;
}

BOOL WINAPI DLLExport SetTextFont(mv _far *knpV, LPEDATA edPtr, LPLOGFONT plf, LPCSTR pStyle)
{
	memcpy(&edPtr->textLf, plf, sizeof(LOGFONT));
	strncpy(edPtr->textFnStyle, pStyle, 40);
	return TRUE;
}

COLORREF WINAPI DLLExport GetTextClr(mv _far *knpV, LPEDATA edPtr)
{
	return edPtr->fontColor;
}

void WINAPI DLLExport SetTextClr(mv _far *knpV, LPEDATA edPtr, COLORREF color)
{
	edPtr->fontColor = color;
}

// --------------------
// CreateObject
// --------------------
// Called when you choose "Create new object". It should display the setup box 
// and initialize everything in the datazone.

int WINAPI DLLExport CreateObject(mv _far *knpV, fpLevObj loPtr, LPEDATA edPtr)
{
#ifdef EDITOR

	// Set default object flags
	edPtr->sx = 160;
	edPtr->sy = 32;

	edPtr->styles=WS_VISIBLE|WS_BORDER|SS_CENTERIMAGE;
	edPtr->exStyles=0;

	// Default font = MS Sans Serif / 8
	if ( knpV->mvGetDefaultFont != NULL )
	{
		knpV->mvGetDefaultFont(&edPtr->textLf, edPtr->textFnStyle, 40);
	}
	else
	{
		edPtr->textLf.lfWidth = 0;
		edPtr->textLf.lfHeight = 8;
		_fstrcpy(edPtr->textLf.lfFaceName, "SYSTEM");
	}

	edPtr->text[0]=0;
	edPtr->fontColor=RGB(0,0,0);
	edPtr->backColor=RGB(255,255,255);
	edPtr->alignement=0;

	edPtr->eHeader.extSize = sizeof(EDITDATA);

	return 0;
#else
	return 0;
#endif
}

// EDIT OPTION
BOOL WINAPI DLLExport EditObject (mv _far *mV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr)
{
	BOOL bOK=FALSE;

#ifdef EDITOR

	CEditText cet((LPCSTR)edPtr->text);
	if (cet.Create(IDD_EDITTEXT, mV->mvHEditWin))
	{
		LPSTR pStr = cet.m_editText;
		if (strlen(pStr)!=strlen(edPtr->text))
		{
			LPEDATA pNewPtr = (LPEDATA)mV->mvCallFunction(edPtr, EF_REALLOCEDITDATA, (LPARAM)edPtr, sizeof(EDITDATA)+strlen(pStr), 0);
			if (pNewPtr!=NULL)
			{
				edPtr=pNewPtr;
				strcpy(edPtr->text, pStr);
			}
		}
		else
			strcpy(edPtr->text, pStr);

		mvRefreshProp(mV, edPtr, PROPID_TEXT, FALSE);
		mV->mvCallFunction(edPtr, EF_INVALIDATEOBJECT, 0, 0, 0);
		bOK=TRUE;
	}
#endif

	return bOK;
}

// --------------------
// SelectPopup
// --------------------
// One of the option from the menu has been selected, and not a default menu option
// automatically handled by CC&C: this routine is then called.
//
int WINAPI DLLExport SelectPopup(mv _far *knpV, int modif, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr, fpushort lpParams, int maxParams)
{
#ifdef EDITOR
	if (MODIF_SIZE == modif)
	{
		edPtr->sx = lpParams[2];
		edPtr->sy = lpParams[3];
	}
#endif // EDITOR
	return 0;
}


#ifdef EDITOR

// --------------------
// SetupProc
// --------------------
// This routine is yours. You may even not need a setup dialog box.
// I have put it as an example...
// Window proc de la boite de dialogue d'edition du titre d'une colonne
// Colour selector


#endif // EDITOR

//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		SetEditSize																				//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL WINAPI DLLExport SetEditSize(LPMV mv, LPEDATA edPtr, int cx, int cy)
{
	edPtr->sx = cx;
	edPtr->sy = cy;
	return TRUE;
}


// --------------------
// GetObjectRect
// --------------------
// Returns the size of the rectangle of the object in the frame window
//
void WINAPI DLLExport GetObjectRect(mv _far *knpV, RECT FAR *rc, fpLevObj loPtr, LPEDATA edPtr)
{
	rc->right = rc->left + edPtr->sx;
	rc->bottom = rc->top + edPtr->sy;
	return;
}


// --------------------
// EditorDisplay
// --------------------
// Displays the object under the frame editor
//
void WINAPI DLLExport EditorDisplay(mv _far *knpV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr, RECT FAR *rc)
{
	// Get playfield surface
#ifndef RUN_ONLY
	LPSURFACE wSurf = WinGetSurface((int)knpV->mvIdEditWin);
	if ( wSurf != NULL )
	{
		int x = rc->left;
		int y = rc->top;
		int w = rc->right - rc->left;
		int h = rc->bottom - rc->top;

		// Displays a white rectangle
		wSurf->Fill(x, y, w, h, edPtr->backColor);
		
		if (edPtr->styles&WS_BORDER)
			wSurf->Rectangle(x, y, rc->right, rc->bottom, 1, BLACK);

		DWORD dtFlags=0;
		switch (edPtr->alignement)
		{
		case 0:
			dtFlags|=DT_LEFT;
			break;
		case 1:
			dtFlags|=DT_CENTER;
			break;
		case 2:
			dtFlags|=DT_RIGHT;
			break;
		}
		if (edPtr->styles&SS_CENTERIMAGE)
			dtFlags|=DT_VCENTER|DT_SINGLELINE;
		if (edPtr->styles&SS_ENDELLIPSIS)
			dtFlags|=DT_END_ELLIPSIS|DT_MODIFYSTRING;
		if (edPtr->styles&SS_PATHELLIPSIS)
			dtFlags|=DT_PATH_ELLIPSIS|DT_MODIFYSTRING;
		
		LPSTR pBuffer=(LPSTR)malloc(strlen(edPtr->text)+1);
		strcpy(pBuffer, edPtr->text);
		HFONT hf=CreateFontIndirect(&edPtr->textLf);
		wSurf->DrawText(pBuffer, strlen(pBuffer), rc, dtFlags, edPtr->fontColor, hf);
		DeleteObject(hf);
		free(pBuffer);
	}
#endif // RUN_ONLY
}


// --------------------
// PrepareToWriteObject
// --------------------
// Just before writing the datazone when saving the application, CC&C calls this routine.
// 
void WINAPI	DLLExport PrepareToWriteObject(mv _far *knpV, LPEDATA edPtr, fpObjInfo adoi)
{
	return;
}





// ============================================================================
//
// ROUTINES USED UNDER EVENT / TIME / STEP-THROUGH EDITOR
// You do not necessary need to change these routines
// 
// ============================================================================

// -----------------
// menucpy
// -----------------
// Internal routine used later, copy one menu onto another
// 
#ifdef EDITOR
void menucpy(HMENU hTargetMenu, HMENU hSourceMenu)
{
	int			n, id, nMn;
	NPSTR		strBuf;
	HMENU		hSubMenu;

	nMn = GetMenuItemCount(hSourceMenu);
	strBuf = (NPSTR)LocalAlloc(LPTR, 80);
	for (n=0; n<nMn; n++)
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
#endif // EDITOR

// -----------------
// GetPopupMenu
// -----------------
// Internal routine used later. Returns the first popup from a menu
// 
HMENU GetPopupMenu(short mn)
{
	HMENU	hPopup = NULL;

#ifdef EDITOR
	HMENU	hMn, hSubMenu;
	if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL)
	{
		if ((hSubMenu = GetSubMenu(hMn, 0)) != NULL)
		{
			if ((hPopup = CreatePopupMenu()) != NULL)
				menucpy(hPopup, hSubMenu);
		}
		DestroyMenu(hMn);
	}
#endif // EDITOR
	return hPopup;
}

// **************************** NEW EXTENSION V2 **********************************

// --------------------
// GetEventInformations
// --------------------
// Internal routine used later. Look for one event in one of the eventInfos array...
// No protection to go faster: you must properly enter the conditions/actions!
// 

// Extension V2
static LPEVENTINFOS2 GetEventInformations(LPEVENTINFOS2 eiPtr, short code)
{
	while (eiPtr->infos.code!=code)
		eiPtr = EVINFO2_NEXT(eiPtr);
	return eiPtr;
}


// ----------------------------------------------------
// GetConditionMenu / GetActionMenu / GetExpressionMenu
// ----------------------------------------------------
// Load the condition/action/expression menu from the resource, eventually
// enable or disable some options, and returns it to CC&C.
//
HMENU WINAPI DLLExport GetConditionMenu(mv _far *knpV, fpObjInfo oiPtr, LPEDATA edPtr)
{
	HMENU hm = NULL;
#ifdef EDITOR
	hm = GetPopupMenu(MN_CONDITIONS);
#endif
	return hm;
}

HMENU WINAPI DLLExport GetActionMenu(mv _far *knpV, fpObjInfo oiPtr, LPEDATA edPtr)
{
	HMENU hm = NULL;
#ifdef EDITOR
	hm = GetPopupMenu(MN_ACTIONS);
#endif
	return hm;
}

HMENU WINAPI DLLExport GetExpressionMenu(mv _far *knpV, fpObjInfo oiPtr, LPEDATA edPtr)
{
	HMENU hm = NULL;
#ifdef EDITOR
	hm = GetPopupMenu(MN_EXPRESSIONS);
#endif
	return hm;
}


// -------------------------------------------------------
// GetConditionTitle / GetActionTitle / GetExpressionTitle
// -------------------------------------------------------
// Returns the title of the dialog box displayed when entering
// parameters for the condition, action or expressions, if any.
// Here, we simply return the title of the menu option
//

void GetCodeTitle(LPEVENTINFOS2 eiPtr, short code, short param, short mn, LPSTR strBuf, WORD maxLen)
{
	HMENU	hMn;
	short	strID;

	// Finds event in array
	eiPtr=GetEventInformations(eiPtr, code);

	// If a special string is to be returned
//	if (eiPtr->infos.paramTitle[param]!=0)
	strID = EVINFO2_PARAMTITLE(eiPtr, param);
	if ( strID != 0 )
		LoadString(hInstLib, strID, strBuf, maxLen);
	else
	{
		// Otherwise, returns the menu option 
		if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL )
		{
			GetMenuString(hMn, eiPtr->menu, strBuf, maxLen, MF_BYCOMMAND);
			DestroyMenu(hMn);
		}
	}
}

void WINAPI DLLExport GetConditionTitle(mv _far *knpV, short code, short param, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)conditionsInfos, code, param, MN_CONDITIONS, strBuf, maxLen);
}
void WINAPI DLLExport GetActionTitle(mv _far *knpV, short code, short param, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)actionsInfos, code, param, MN_ACTIONS, strBuf, maxLen);
}
void WINAPI DLLExport GetExpressionTitle(mv _far *knpV, short code, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)expressionsInfos, code, 0, MN_EXPRESSIONS, strBuf, maxLen);
}

// Retourne le nom d'un parametre expression
void WINAPI DLLExport GetExpressionParam(mv _far *knpV, short code, short param, LPSTR strBuf, short maxLen)
{
	short		strID;

	// Finds event in array
	LPEVENTINFOS2 eiPtr=GetEventInformations((LPEVENTINFOS2)expressionsInfos, code);

	// If a special string is to be returned
	strID = EVINFO2_PARAMTITLE(eiPtr, param);
	if ( strID != 0 )
		LoadString(hInstLib, strID, strBuf, maxLen);
	else
		*strBuf=0;
}


// ----------------------------------------------------------------------------
// GetConditionCodeFromMenu / GetActionCodeFromMenu / GetExpressionCodeFromMenu
// ----------------------------------------------------------------------------
// From a menu ID, these routines returns the code of the condition,
// action or expression, as defined in the .H file
//

short WINAPI DLLExport GetConditionCodeFromMenu(mv _far *knpV, short menuId)
{
#ifdef EDITOR
	LPEVENTINFOS2	eiPtr;
	int				n;

	if ( !IS_COMPATIBLE(knpV) )
		return 0;

	for (n=CND_LAST, eiPtr=(LPEVENTINFOS2)conditionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0)
		return eiPtr->infos.code;
#endif
	return -1;
}

short WINAPI DLLExport GetActionCodeFromMenu(mv _far *knpV, short menuId)
{
#ifdef EDITOR
	LPEVENTINFOS2	eiPtr;
	int				n;

	if ( !IS_COMPATIBLE(knpV) )
		return 0;

	for (n=ACT_LAST, eiPtr=(LPEVENTINFOS2)actionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0)
		return eiPtr->infos.code;
#endif
	return -1;
}

short WINAPI DLLExport GetExpressionCodeFromMenu(mv _far *knpV, short menuId)
{
#ifdef EDITOR
	LPEVENTINFOS2	eiPtr;
	int				n;

	if ( !IS_COMPATIBLE(knpV) )
		return 0;

	for (n=EXP_LAST, eiPtr=(LPEVENTINFOS2)expressionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0)
		return eiPtr->infos.code;
#endif
	return -1;
}


// -------------------------------------------------------
// GetConditionInfos / GetActionInfos / GetExpressionInfos
// -------------------------------------------------------
// From a action / condition / expression code, returns 
// an infosEvents structure. 
//

LPINFOEVENTSV2 WINAPI DLLExport GetConditionInfos(mv _far *knpV, short code)
{
	return &GetEventInformations((LPEVENTINFOS2)conditionsInfos, code)->infos;
}

LPINFOEVENTSV2 WINAPI DLLExport GetActionInfos(mv _far *knpV, short code)
{
	return &GetEventInformations((LPEVENTINFOS2)actionsInfos, code)->infos;
}

LPINFOEVENTSV2 WINAPI DLLExport GetExpressionInfos(mv _far *knpV, short code)
{
	return &GetEventInformations((LPEVENTINFOS2)expressionsInfos, code)->infos;
}


// ----------------------------------------------------------
// GetConditionString / GetActionString / GetExpressionString
// ----------------------------------------------------------
// From a action / condition / expression code, returns 
// the string to use for displaying it under the event editor
//

void WINAPI DLLExport GetConditionString(mv _far *knpV, short code, LPSTR strPtr, short maxLen)
{
	LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)conditionsInfos, code)->string, strPtr, maxLen);
}

void WINAPI DLLExport GetActionString(mv _far *knpV, short code, LPSTR strPtr, short maxLen)
{
	LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)actionsInfos, code)->string, strPtr, maxLen);
}

void WINAPI DLLExport GetExpressionString(mv _far *knpV, short code, LPSTR strPtr, short maxLen)
{
	LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)expressionsInfos, code)->string, strPtr, maxLen);
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		PROPERTIES  																			//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL WINAPI DLLExport GetProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
#ifndef RUN_ONLY
	mV->mvCallFunction(edPtr, EF_INSERTPROPS, (LPARAM)Properties, PROPID_TAB_GENERAL, TRUE);
#endif // RUN_ONLY

	return TRUE;
}

LPVOID WINAPI DLLExport GetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	switch (nPropID) 
	{
	case PROPID_BACKCOLOR:
		return new CPropDWordValue(edPtr->backColor);
	case PROPID_TEXT:
		return new CPropDataValue(&edPtr->text[0]);
	case PROPID_STYLES:
		return new CPropDWordValue(edPtr->alignement);
	}
#endif // RUN_ONLY
	return NULL;
}
BOOL WINAPI DLLExport GetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	switch (nPropID)
	{
	case PROPID_BORDER:
		return (edPtr->styles&WS_BORDER)!=0;
	case PROPID_CLIENT:
		return (edPtr->exStyles&WS_EX_CLIENTEDGE)!=0;
	case PROPID_STATIC:
		return (edPtr->exStyles&WS_EX_STATICEDGE)!=0;
/*	case PROPID_SINGLELINE:
		return (edPtr->styles&SS_SINGLELINE)!=0;
*/	case PROPID_VCENTER:
		return (edPtr->styles&SS_CENTERIMAGE)!=0;
	case PROPID_PATHELLIPSIS:
		return (edPtr->styles&SS_PATHELLIPSIS)!=0;
	case PROPID_ENDELLIPSIS:
		return (edPtr->styles&SS_ENDELLIPSIS)!=0;
	case PROPID_VISIBLE:
		return (edPtr->styles&WS_VISIBLE)!=0;
	}
#endif // RUN_ONLY
	return FALSE;
}

void WINAPI DLLExport SetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID, LPVOID lParam)
{
#ifndef RUN_ONLY
	CPropValue* pValue = (CPropValue*)lParam;
	BOOL bRefresh = TRUE;

	switch (nPropID) 
	{
	case PROPID_STYLES:
		edPtr->alignement=((CPropDWordValue*)pValue)->m_dwValue;
		break;
	case PROPID_BACKCOLOR:
		edPtr->backColor=((CPropDWordValue*)pValue)->m_dwValue;
		break;
	case PROPID_TEXT:
		{
			LPSTR pStr = (LPSTR)((CPropDataValue*)pValue)->m_pData;
			if (strlen(pStr)!=strlen(edPtr->text))
			{
				LPEDATA pNewPtr = (LPEDATA)mV->mvCallFunction(edPtr, EF_REALLOCEDITDATA, (LPARAM)edPtr, sizeof(EDITDATA)+strlen(pStr), 0);
				if (pNewPtr!=NULL)
				{
					edPtr=pNewPtr;
					strcpy(edPtr->text, pStr);
				}
			}
			else
				strcpy(edPtr->text, pStr);
		}
		break;
	default:
		bRefresh = FALSE;
		break;
	}
	if ( bRefresh )
		mV->mvCallFunction(edPtr, EF_INVALIDATEOBJECT, 0, 0, 0);

#endif // RUN_ONLY
}

void WINAPI DLLExport SetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID, BOOL nCheck)
{
#ifndef RUN_ONLY
	BOOL bRefresh = TRUE;
	switch (nPropID)
	{
	case PROPID_BORDER:
		edPtr->styles&=~WS_BORDER;
		if (nCheck)
			edPtr->styles|=WS_BORDER;
		break;
	case PROPID_CLIENT:
		edPtr->exStyles&=~WS_EX_CLIENTEDGE;
		if (nCheck)
			edPtr->exStyles|=WS_EX_CLIENTEDGE;
		break;
	case PROPID_STATIC:
		edPtr->exStyles&=~WS_EX_STATICEDGE;
		if (nCheck)
			edPtr->exStyles|=WS_EX_STATICEDGE;
		break;
	case PROPID_PATHELLIPSIS:
		edPtr->styles&=~SS_PATHELLIPSIS;
		if (nCheck)
			edPtr->styles|=SS_PATHELLIPSIS;
		break;
	case PROPID_ENDELLIPSIS:
		edPtr->styles&=~SS_ENDELLIPSIS;
		if (nCheck)
			edPtr->styles|=SS_ENDELLIPSIS;
		break;
	case PROPID_VISIBLE:
		edPtr->styles&=~WS_VISIBLE;
		if (nCheck)
			edPtr->styles|=WS_VISIBLE;
		break;
/*	case PROPID_SINGLELINE:
		edPtr->styles&=~SS_SINGLELINE;
		if (nCheck)
			edPtr->styles|=SS_SINGLELINE;
		break;
*/
	case PROPID_VCENTER:
		edPtr->styles&=~SS_CENTERIMAGE;
		if (nCheck)
		{
			edPtr->styles|=SS_CENTERIMAGE;
//			mV->mvCallFunction(edPtr, EF_REFRESHPROP, PROPID_SINGLELINE, 0, 0);
		}
		break;
	default:
		bRefresh=FALSE;
		break;
	}
	if ( bRefresh )
		mV->mvCallFunction(edPtr, EF_INVALIDATEOBJECT, 0, 0, 0);
#endif // RUN_ONLY
}

// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = 
			{ 
			Condition_LClick,
			Condition_RClick,
			Condition_DblClick,
			Condition_IsVisible,
			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			Action_Hide,
			Action_Show,
			Action_SetWidth,
			Action_SetHeight,
			Action_SetText,
			Action_SetTextColor,
			Action_SetBackColor,
			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			Expression_GetWidth,
			Expression_GetHeight,
			Expression_GetText,
			0
			};


// ----------------------------------------------------------
// GetRunObjectInfos
// ----------------------------------------------------------
// Fills an information structure that tells CC&C everything
// about the object, its actions, conditions and expressions
// 

short WINAPI DLLExport GetRunObjectInfos(mv _far *knpV, fpKpxRunInfos infoPtr)
{            
	infoPtr->conditions = (LPBYTE)ConditionJumps;
	infoPtr->actions = (LPBYTE)ActionJumps;
	infoPtr->expressions = (LPBYTE)ExpressionJumps;

	infoPtr->numOfConditions = CND_LAST;
	infoPtr->numOfActions = ACT_LAST;
	infoPtr->numOfExpressions = EXP_LAST;

	infoPtr->editDataSize = MAX_EDITSIZE;
	infoPtr->editFlags= OEFLAGS;

	infoPtr->windowProcPriority = WINDOWPROC_PRIORITY;

	// See doc
	infoPtr->editPrefs = OEPREFS;

	// Identifier, for run-time identification
	infoPtr->identifier = IDENTIFIER;
	
	// Current version
	infoPtr->version = KCX_CURRENT_VERSION;
	
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		New C&C V2																				//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////


// Return object info - called by MMF when you select Objects / Information / About
void WINAPI	DLLExport GetObjInfos (mv _far *knpV, LPEDATA edPtr, LPSTR ObjName, LPSTR ObjAuthor, LPSTR ObjCopyright, LPSTR ObjComment, LPSTR ObjHttp)
{
	// Name
	LoadString(hInstLib, IDST_OBJNAME,ObjName, 255);

	// Author
	LoadString(hInstLib, IDST_AUTHOR,ObjAuthor,255);

	// Copyright
	LoadString(hInstLib, IDST_COPYRIGHT,ObjCopyright,255);

	// Comment
	LoadString(hInstLib, IDST_COMMENT,ObjComment,255);

	// Internet address
	LoadString(hInstLib, IDST_HTTP,ObjHttp,255);
}

LPCSTR WINAPI DLLExport GetHelpFileName()
{
	return "StaticText.chm";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// 																							    //
//		Edition of button text																	//
// 																							    //
//////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CALLBACK EditTextProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	CEditText* pDlg;

	pDlg=(CEditText*)GetWindowLong(hDlg,GWL_USERDATA);

	switch (uMsg)
	{
	case WM_INITDIALOG:
		pDlg=(CEditText*)lParam;
		pDlg->m_hWnd=hDlg;
		SetWindowLong(hDlg,GWL_USERDATA,(DWORD)pDlg);
		return(pDlg->OnInitDialog());

	case WM_COMMAND:
		{
			int wID = LOWORD(wParam);         // item, control, or accelerator identifier 
			switch (wID) 
			{
			case IDOK:	
				pDlg->OnOK();
				return TRUE;
			case IDCANCEL:
				pDlg->OnCancel();
				return TRUE;
			}
		}
	}
	return(FALSE);
}

CEditText::CEditText(LPCSTR pEditText)
{
	m_hWnd = NULL;

	m_editText = (LPSTR)calloc((pEditText == NULL) ? 1 : strlen(pEditText)+1, 1);
	if ( pEditText != NULL )
		strcpy(m_editText, pEditText);
}

CEditText::~CEditText()
{
	free(m_editText);
	m_editText = NULL;
}

BOOL CEditText::Create(int idd, HWND hWndParent)
{
	// Boite de dialogue
	return DialogBoxParam(hInstLib, MAKEINTRESOURCE(idd), hWndParent, EditTextProc, (LPARAM)this);
}

BOOL CEditText::OnInitDialog()
{
	SetDlgItemText(m_hWnd, IDC_ENTERTEXTEDIT, (LPCTSTR)m_editText);

	SetFocus(GetDlgItem(m_hWnd, IDC_ENTERTEXTEDIT));
	return FALSE;
}

void CEditText::OnOK()
{
	HWND hCtl = GetDlgItem(m_hWnd, IDC_ENTERTEXTEDIT);
	int lg = ::GetWindowTextLength(hCtl);

	free(m_editText);
	m_editText = (LPSTR)calloc(lg+1, 1);
	GetDlgItemText(m_hWnd, IDC_ENTERTEXTEDIT, m_editText, lg+1);

	EndDialog(m_hWnd, TRUE);
}

void CEditText::OnCancel()
{
	EndDialog(m_hWnd, FALSE);
}
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

