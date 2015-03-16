////////////////////////////////////////////////////////////////////////////
//		SQL Database MMF Extension
//		(c) 2004-2005, Jim St. Jean
//	
//		MAIN OBJECT ROUTINES - Header file
//
//
////////////////////////////////////////////////////////////////////////////
//
//  Originally generated using FireMonkeySDK
//

// Unique Object identifier "XJSJ" - an eXtension made by JSJ
#define IDENTIFIER	0x584A534A

// Database engine
#include	"sqldb.h"

//Routine count definitions
#define	CND_LAST	2
#define	ACT_LAST	7
#define	EXP_LAST    12


// --------------------------------
// EDIT OBJECT DATA STRUCTURE
// --------------------------------
/*
Info from Tigs' Extension Tutorial Part 1:
 The Edit Data structure which stores data at edit-time, while the user is 
 modifying the frame and object in Multimedia Fusion. This structure starts off 
 with typedef struct tagEDATA_V1.
*/
typedef struct tagEDATA_V1
{
	extHeader		eHeader;
	short			sx;
	short			sy;
	short			swidth;
	short			sheight;

} EDITDATA;
typedef EDITDATA _far *			LPEDATA;

// Object versions
#define	KCX_CURRENT_VERSION			1



// ------------------------------------
// GLOBAL RUNNING OBJECT DATA STRUCTURE
// ------------------------------------
struct GlobalData
{
//	char	Name[OINAME_SIZE+1];		// This is the name of the global object

	sqldb *db;							// global named object for shared database instance
};


// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
/*
Info from Tigs' Extension Tutorial Part 1:
 Main.h  includes the definition of the Run Data structure. 
 The Run Data structure is probably the most important structure for your extension. 
 All your extension's variables and data for use at runtime must be kept here. 
 If someone makes two instances of your extension, then MMF allocates two Run Data 
 structures so they can work seperately. MMF passes a pointer to this structure 
 nearly everywhere: rdPtr.
*/
typedef struct tagRDATA
{
	headerObject	rHo;		// Header
	rVal			rov;		// Alterable values
//	sqlite *db;					// local database instance (future enh.)
	int numrows;				// Number of rows in result
	int numcols;				// Number of columns in result
	int currrow;				// Current row in result
	int currcol;				// Current col in result
	char **results;				// Results of queury
	char *errmsg;				// error message
	int err;					// error value
} RUNDATA;
typedef	RUNDATA	_far *			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags
// -------------
#define	OEFLAGS      OEFLAG_VALUES
#define	OEPREFS      			0

// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100

 