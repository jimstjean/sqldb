//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 																														    //
// 																														    //
//		KLIK & CREATE : external object																						//
// 																														    //
// 																														    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_VISIBLE					0
#define	CND_ENABLE					1
#define	CND_CANUNDO					2
#define	CND_MODIFIED				3
#define	CND_HAVEFOCUS				4
#define	CND_ISNUMBER				5
#define	CND_ISSELECTED				6
#define	CND_LAST					7



// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_LOADTEXT				0
#define	ACT_LOADTEXTSELECT			1
#define	ACT_SAVETEXT				2
#define	ACT_SAVETEXTSELECT			3
#define	ACT_SETTEXT					4
#define	ACT_REPLACESELECTION		5
#define	ACT_CUT						6
#define	ACT_COPY					7
#define	ACT_PASTE					8
#define	ACT_CLEAR					9
#define	ACT_UNDO					10
#define	ACT_CLEARUNDOBUFFER			11
#define	ACT_SHOW					12
#define	ACT_HIDE					13
#define	ACT_SETFONTSELECT			14
#define	ACT_SETCOLORSELECT			15
#define	ACT_ACTIVATE				16
#define	ACT_ENABLE					17
#define	ACT_DISABLE					18
#define	ACT_READONLYON				19
#define	ACT_READONLYOFF				20
#define	ACT_TEXTMODIFIED			21
#define	ACT_TEXTNOTMODIFIED			22
#define	ACT_LIMITTEXTSIZE			23
#define	ACT_SETPOSITION				24
#define	ACT_SETXPOSITION			25
#define	ACT_SETYPOSITION			26
#define	ACT_SETSIZE					27
#define	ACT_SETXSIZE				28
#define	ACT_SETYSIZE				29
#define	ACT_DESACTIVATE				30
#define	ACT_SCROLLTOTOP				31
#define	ACT_SCROLLTOLINE			32
#define	ACT_SCROLLTOEND				33
#define	ACT_SETCOLOR				34
#define	ACT_SETBKDCOLOR				35
#define	ACT_LAST					36



// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_GETTEXT					0
#define	EXP_GETSELECTION			1
#define	EXP_GETXPOSITION			2
#define	EXP_GETYPOSITION			3
#define	EXP_GETXSIZE				4
#define	EXP_GETYSIZE				5
#define	EXP_GETVALUE				6
#define	EXP_GETFIRSTLINE			7
#define	EXP_GETLINECOUNT			8
#define	EXP_GETCOLOR				9
#define	EXP_GETBKDCOLOR				10
#define	EXP_LAST                   	11


// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
#pragma pack(push,_PACK_CNCS_EXT)  
#pragma pack(2)

typedef struct tagEDATA
{
	extHeader		eHeader;

	short			sSizeX;
	short			sSizeY;
	LOGFONT16		lfEditFont;
	COLORREF 		crefCustColor [16];
	COLORREF		crefEditFontColor;
	COLORREF		crefEditFontBkColor;
	char			szEditFontStyle [40];
	long			lFlags;
	long			ebtnSecu [4];

} editData;

typedef editData	_far *			fpedata;

#pragma pack(pop,_PACK_CNCS_EXT)




// Object flags
#define	EDIT_HSCROLLBAR			0x0001
#define	EDIT_HSCROLLAUTOSCROLL	0x0002
#define	EDIT_VSCROLLBAR			0x0004
#define	EDIT_VSCROLLAUTOSCROLL	0x0008
#define	EDIT_READONLY			0x0010
#define	EDIT_MULTILINE			0x0020
#define	EDIT_PASSWORD			0x0040
#define	EDIT_BORDER				0x0080
#define	EDIT_HIDEONSTART		0x0100
#define	EDIT_UPPERCASE			0x0200
#define	EDIT_LOWERCASE			0x0400
#define	EDIT_TABSTOP			0x0800
#define	EDIT_SYSCOLOR			0x1000
#define	EDIT_3DLOOK				0x2000
#define	EDIT_TRANSP				0x4000
#define	EDIT_JUSTCREATED		0x8000

// Object versions
#define	KCX_VERSION_0				0
#define	KCX_CURRENT_VERSION			0



// -----------------------------
// RUNNING OBJECT DATA STRUCTURE
// -----------------------------
typedef struct tagRDATA
{
	headerObject 	rHo;					// Header
	rCom			rc;						// Structure commune pour les mouvements/animations
	rMvt			rm;						// Structure de mouvements

	int				numOfWindows;			// 1!
	HWND			hWnd;		
	
	LOGFONT16		lfEditFont;
	COLORREF 		crefCustColor [16];
	COLORREF		crefEditFontColor;
	COLORREF		crefEditFontBkColor;
	char			szEditFontStyle [40];
	HFONT			hFont;
	HBRUSH			hBrush;
	long			lFlags;
	short			sVisible;
	short			sEnable;
	HGLOBAL			hglb;
	long			InitEditWinWidth;
	long			InitEditWinHeight;
	WNDPROC			lpfnOldComboProc;
	DWORD			dwOldEditWinStyle;

} runData;

typedef	runData		_far *		fprdata;

typedef struct tagrTable
{
	HWND			hwndHandle;
	fprdata			rdPtr;
} rTable;

// Debugger
enum
{
	DB_STRING
};

// Size when editing the object under level editor
#define	MAX_EDITSIZE	sizeof(editData)



// Default flags
#define	OEFLAGS      			(OEFLAG_WINDOWPROC | OEFLAG_DISPLAYINFRONT | OEFLAG_MOVEMENTS | OEFLAG_TEXT)
#define	OEPREFS      			(OEPREFS_GLOBAL | OEPREFS_SCROLLINGINDEPENDANT)



// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
#define	WINDOWPROC_PRIORITY			100





                    