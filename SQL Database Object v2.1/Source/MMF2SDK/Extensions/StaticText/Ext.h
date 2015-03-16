
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		CLICK & CREATE : external object																						//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_LCLICK							0
#define	CND_RCLICK							1
#define	CND_DBLCLICK						2
#define CND_ISVISIBLE						3
#define	CND_LAST							4

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_HIDE					0
#define ACT_SHOW					1
#define ACT_SETWIDTH				2
#define ACT_SETHEIGHT				3
#define ACT_SETTEXT					4
#define ACT_SETTEXTCOLOR			5
#define ACT_SETBACKCOLOR			6
#define	ACT_LAST					7

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES 
// -------------------------------
#define	EXP_GETWIDTH						0
#define EXP_GETHEIGHT						1
#define EXP_GETTEXT							2
#define	EXP_LAST							3

// ------------------------------
// DEFINITION OF OTHER ID & VARS
// ------------------------------

#define	ID_MENUCONTROL				1000


// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------

#pragma pack(push,_PACK_CNCS_EXT)  
#pragma pack(2)

typedef struct tagEDATA_V0
{
	extHeader		eHeader;
	int				sx;
	int				sy;

	DWORD			styles;
	DWORD			exStyles;

	// Font
	LOGFONT			textLf;
	char			textFnStyle[40];

	COLORREF		fontColor;
	COLORREF		backColor;
	DWORD			alignement;

	char			text[2];
} EDITDATA;
typedef EDITDATA _far *			LPEDATA;

#pragma pack(pop,_PACK_CNCS_EXT)

// Object versions
#define	KCX_CURRENT_VERSION			0


// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
#define CLICKFLAG_LBUTTON		0x0001
#define CLICKFLAG_RBUTTON		0x0002
#define CLICKFLAG_DBLCLICK		0x0004
typedef struct tagRDATA
{
	headerObject 	rHo;					// Header
	rCom			rc;
	rMvt			rm;
	rVal			rv;

	int				WindowNumber;			// If your application uses a sub window
	HWND			hWnd;					// you need to define these values

	HFONT			hFont;
	HBRUSH			hBackBrush;
	COLORREF		backColor;
	COLORREF		fontColor;

	DWORD			styles;

	WNDPROC			OldWindowProc;
	int				ItemClick;
	int				ColumnClick;
	int				nCurrentSelected;
	
	DWORD			LClickCount;
	DWORD			RClickCount;
	DWORD			DblClickCount;
	DWORD			clickFlag;

	BOOL			bVisible;	
} RUNDATA;
typedef	RUNDATA	_far *			LPRDATA;


// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE		32767			//sizeof(EDITDATA)		// Size of the datazone while editing. Better make it large

// Default flags	Please refer at the documentation for more information
// -------------
#define	OEFLAGS				(OEFLAG_WINDOWPROC | OEFLAG_VALUES | OEFLAG_MOVEMENTS | OEFLAG_TEXT)
#define OEPREFS				0
 


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100



// EDIT TEXT CLASS //////////////////////////////////////////////////
class CEditText
{
public:
	CEditText(LPCSTR pEditText);
	~CEditText();
	BOOL Create(int idd, HWND hWndParent);
	BOOL OnInitDialog();
	void OnOK();
	void OnCancel();

	HWND m_hWnd;
	LPSTR m_editText;
};