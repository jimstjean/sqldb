////////////////////////////////////////////////////////////////////////////
//		SQL Database MMF Extension
//		(c) 2004-2005, Jim St. Jean
//	
//		MAIN OBJECT ROUTINES - Source
//
//
////////////////////////////////////////////////////////////////////////////
//
//  Originally generated using FireMonkeySDK:
//
//	Use the handy transfer.bat file in the debug directory of the SDK to transfer the cox files to MMF (Close down any projects using the extension first)
//	You can get all sorts of crashes if your interface code is wrong so check everything thouroughly or pay later!
//	Check each condition, action and expression can be placed and make sure each expression is valid by using the validify button in the expression editor
//
//  What you still need to do :
//		Change the 3 extension build filenames (Project->Settings->V2Template32->Link)
//		Make your icons
//		Make your setup box
//		Fill out your extension info and author info in the string tables
//		Change your version info in the resource file
//		Change your IDENTIFIER, flags and prefrences in main.h
//		Change your runtime data and edittime data structures to suit your needs
//		Fill out all the required routines in Runtime.cpp and Edittime.cpp
//		Flesh out your actions, conditions and expressions
//		Write help files, examples and documentation!
//
//
// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
//
// ============================================================================

// Common Include
#include	"common.h"


// Declare the single database connection/pointer instance
// This variable will remain global between all instances of the object.
// Defined in Runtime.cpp, so it's external.
// JSJ NOTE: Current version implements global shared database pointer
extern GlobalData Global;


//
//	INFO ARRAYS
//
// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

/*
	The flags item for conditions can be:
	EVFLAGS_ALWAYS: Event always checked (equivalent to alwaysFlag in CICK)
	EVFLAGS_ALWAYS | EVFLAGS_NOTABLE: Event always checked and can be negated (alwaysNegFlag in CICK)
	0: Event routine not called, unless triggered by callRunTimeFunction (noFlag in CICK)

	The flags item for expressions can be:
	0: Returns an integer (retInt)
	EXPFLAG_STRING: Returns a string (retString)
	EXPFLAG_DOUBLE: Returns a float (retFloat)
*/


// CONDITIONS
short conditionsInfos[]=
	{ 
	CID_conditionOnSQLError,	CID_conditionOnSQLError,	0,	EVFLAGS_ALWAYS,	0,
	CID_conditionDBOpen,	CID_conditionDBOpen,	1,	EVFLAGS_ALWAYS | EVFLAGS_NOTABLE,	0,
	0 };

// ACTIONS
short actionsInfos[]=
	{ 
	AID_actionOpenFile,	AID_actionOpenFile,	0,	0,	1,	PARAM_EXPSTRING,	AP0ID_actionOpenFile,
	AID_actionOpenFileSelect,	AID_actionOpenFileSelect,	1,	0,	1,	PARAM_FILENAME,	AP0ID_actionOpenFileSelect,
	AID_actionCloseFile,	AID_actionCloseFile,	2,	0,	0,
	AID_actionRunSQL,	AID_actionRunSQL,	3,	0,	1,	PARAM_EXPSTRING,	AP0ID_actionRunSQL,
	AID_actionSetRow,	AID_actionSetRow,	4,	0,	1,	PARAM_EXPRESSION, AP0ID_actionSetRow,
	AID_actionSetCol,	AID_actionSetCol,	5,	0,	1,	PARAM_EXPRESSION, AP0ID_actionSetCol,
	AID_actionClearErr,	AID_actionClearErr,	6,	0,	0,	
	0 };


// EXPRESSIONS
short expressionsInfos[]=
	{ 
	EID_expressionData,	EID_expressionData,	0,	EXPFLAG_STRING,	0 ,
	EID_expressionColumnName,	EID_expressionColumnName,	1,	EXPFLAG_STRING,	0,
	EID_expressionRows,	EID_expressionRows,	2,	0,	0,
	EID_expressionCols,	EID_expressionCols,	3,	0,	0,
	EID_expressionErr,	EID_expressionErr,	4,	0,	0,
	EID_expressionErrMsg,	EID_expressionErrMsg,	5,	EXPFLAG_STRING,	0 ,
	EID_expressionDataRowCol,  EID_expressionDataRowCol, 6, EXPFLAG_STRING, 2, EXPPARAM_LONG,	EXPPARAM_LONG,	EP0ID_expressionDataRowCol,	EP1ID_expressionDataRowCol, 
	EID_expressionDataColbyName,  EID_expressionDataColbyName, 7, EXPFLAG_STRING, 1, EXPPARAM_STRING,	EP0ID_expressionDataColbyName, 
	EID_expressionDataRowColbyName,  EID_expressionDataRowColbyName, 8, EXPFLAG_STRING, 2, EXPPARAM_LONG,	EXPPARAM_STRING,	EP0ID_expressionDataRowColbyName,	EP1ID_expressionDataRowColbyName, 
	EID_expressionQuote,  EID_expressionQuote, 9, EXPFLAG_STRING, 1, EXPPARAM_STRING,	EP0ID_expressionQuote, 
	EID_expressionCurrRow,	EID_expressionCurrRow,	10,	0,	0,
	EID_expressionCurrCol,	EID_expressionCurrCol,	11,	0,	0,
	0 };


//============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

//----------------------------------------------------------------------------
// SQLERROR
//
// This function returns non-zero value if the previous SQL statement execution
//	resulted in an error
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  non-zero if there was an error
//

long WINAPI DLLExport conditionOnSQLError(LPRDATA rdPtr, long param1, long param2)
{
	return rdPtr->err;
}

//----------------------------------------------------------------------------
// DBOPEN
//
// This function returns non-zero value if a database is currently open
//	NOTE: The database is global to all SQL Database objects in the app
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  non-zero value if a database is open
//

long WINAPI DLLExport conditionDBOpen(LPRDATA rdPtr, long param1, long param2)
{
//	return (rdPtr->db!=NULL);		// future
	return (Global.db!=NULL);
}


//============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

//----------------------------------------------------------------------------
// OPENFILE
//
// This function opens a new database from a file name
//
// INPUT PARAMETERS
//	filename of database to open
//
// RESULT
//  potential error code and message
//
short WINAPI DLLExport actionOpenFile(LPRDATA rdPtr, long param1, long param2)
{
	char * p1=(LPSTR)param1;   //String is path of file

	// clear any previous error
	if (rdPtr->err != 0)
	{
		rdPtr->err=0;
		if (rdPtr->errmsg != NULL)
		{
			sqldb_freemem(rdPtr->errmsg);
			rdPtr->errmsg = NULL;
		}
	}

	// clear any previous results
	if (rdPtr->results != NULL) 
	{
		sqldb_free_table(rdPtr->results);
		rdPtr->results = NULL;
		rdPtr->currcol=0;
		rdPtr->currrow=0;
		rdPtr->numcols=0;
		rdPtr->numrows=0;
	}

	//  close any previous open SQLDB db handle 
	if (Global.db != NULL)
	{
		sqldb_close(Global.db);
		Global.db=NULL;
		//rdPtr->db = NULL;

	}

	if ((p1 != 0) && strlen(p1)>1)
	{
		// open the new database based on the file specified
		Global.db =  sqldb_open( p1, &rdPtr->errmsg);          
		//rdPtr->db = Global.db;
	}

	if (Global.db != NULL)
		rdPtr->err = SQLDB_OK;
	else
		rdPtr->err = SQLDB_NOTOK;

	return 0;

}

//----------------------------------------------------------------------------
// OPENFILESELECT
//
// This function opens a new database from a file name chosen from a selector
//  Identical to the previous function
//
// INPUT PARAMETERS
//	filename of database to open
//
// RESULT
//  potential error code and message
//
short WINAPI DLLExport actionOpenFileSelect(LPRDATA rdPtr, long param1, long param2)
{
	char * p1=(LPSTR)param1;   //String is path of file

	// clear any previous error
	if (rdPtr->err != 0)
	{
		rdPtr->err=0;
		if (rdPtr->errmsg != NULL)
		{
			sqldb_freemem(rdPtr->errmsg);
			rdPtr->errmsg = NULL;
		}
	}

	// clear any previous results
	if (rdPtr->results != NULL) 
	{
		sqldb_free_table(rdPtr->results);
		rdPtr->results = NULL;
		rdPtr->currcol=0;
		rdPtr->currrow=0;
		rdPtr->numcols=0;
		rdPtr->numrows=0;
	}

	//  close any previous open SQLDB db handle 
	if (Global.db != NULL)
	{
		sqldb_close(Global.db);
		Global.db=NULL;
		//rdPtr->db = NULL;

	}

	if ((p1 != 0) && (strlen(p1)>1))
	{
		// open the new database based on the file specified
		Global.db =  sqldb_open( p1, &rdPtr->errmsg);          
		//rdPtr->db = Global.db;
	}

	if (Global.db != NULL)
		rdPtr->err = SQLDB_OK;
	else
		rdPtr->err = SQLDB_NOTOK;

	return 0;

}

//----------------------------------------------------------------------------
// CLOSEFILE
//
// This function closed the open database
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  potential error code and message
//
short WINAPI DLLExport actionCloseFile(LPRDATA rdPtr, long param1, long param2)
{
	// If results already exist, free them now

	// clear any previous error
	if (rdPtr->err != 0)
	{
		rdPtr->err=0;
		if (rdPtr->errmsg != NULL)
		{
			sqldb_freemem(rdPtr->errmsg);
			rdPtr->errmsg = NULL;
		}
	}

	// clear any previous results
	if (rdPtr->results != NULL) 
	{
		sqldb_free_table(rdPtr->results);
		rdPtr->results = NULL;
		rdPtr->currcol=0;
		rdPtr->currrow=0;
		rdPtr->numcols=0;
		rdPtr->numrows=0;
	}

	// ensure have an open database, and if so, close it
	if (Global.db != NULL)
		sqldb_close(Global.db);
	//rdPtr->db = NULL;
	Global.db = NULL;

	return 0;
}

//----------------------------------------------------------------------------
// RUNSQL
//
// This function executes an SQL statement against the current open database
//
// INPUT PARAMETERS
//	p1 = SQL string to execute
//
// RESULT
//  current data set is populated with result matrix
//  number of rows and columns are set
//	current row and column indexes are set
//  potential error code and message
//
// Further explanation of result set structure and processing:
/*
This routine calls the SQLDB SQL exection function to obtain the result data and
save each row of the result in memory obtained from malloc(), 
and return all of the result after the query has finished. 

  int sqldb_get_table(
  sqldb*,              //* An open database 
  const char *sql,       //* SQL to be executed 
  char ***resultp,       // Result written to a char *[]  that this points to 
  int *nrow,             //* Number of result rows written here
  int *ncolumn,          //* Number of result columns written here 
  char **errmsg          //* Error msg written here 
  );


As an example, suppose the query result where this table:

        Name        | Age
        -----------------------
        Alice       | 43
        Bob         | 28
        Cindy       | 21

If the 3rd argument were &azResult then after the function returns azResult 
will contain the following data:

        azResult[0] = "Name";
        azResult[1] = "Age";
        azResult[2] = "Alice";
        azResult[3] = "43";
        azResult[4] = "Bob";
        azResult[5] = "28";
        azResult[6] = "Cindy";
        azResult[7] = "21";
 
Notice that there is an extra row of data containing the column headers. 
But the *nrow return value is still 3. *ncolumn is set to 2. In general, 
the number of values inserted into azResult will be ((*nrow) + 1)*(*ncolumn).

After the calling function has finished using the result, it should pass the 
result data pointer to sqldb_free_table() in order to release the memory 
that was malloc-ed. Because of the way the malloc() happens, the calling 
function must not try to call malloc() directly. Only sqldb_free_table() 
is able to release the memory properly and safely.
*/

short WINAPI DLLExport actionRunSQL(LPRDATA rdPtr, long param1, long param2)
{
	char * p1=(LPSTR)param1;

	// If a previous error existed, clear it now
	if (rdPtr->err != 0)
	{
		rdPtr->err=0;
		if (rdPtr->errmsg != NULL)
		{
			sqldb_freemem(rdPtr->errmsg);
			rdPtr->errmsg = NULL;
		}
	}

	// If results already exist, free them now
	if (rdPtr->results != NULL) 
	{
		// free prior result set
		sqldb_free_table(rdPtr->results);
		rdPtr->results = NULL;
		rdPtr->currcol=0;
		rdPtr->currrow=0;
		rdPtr->numcols=0;
		rdPtr->numrows=0;
	}

	// ensure we actually have an SQL statement
	if (p1[0] == '\0')
		return 0;
	else
	{ 

		// execute the SQL storing the results, if any
		if (Global.db != NULL)
		{
			rdPtr->err = sqldb_get_table(
				Global.db,              /* An open database */
				p1,						/* SQL to be executed */
				&rdPtr->results,		/* Result written to a char *[]  that this points to */
				&rdPtr->numrows,		/* Number of result rows written here */
				&rdPtr->numcols,		/* Number of result columns written here */
				&rdPtr->errmsg			/* Error msg written here */
			);
			// REMINDER: must call void sqldb_free_table(char **result) later!

			// initialize current row and column indexes to (0,0) if no data, else (1,1)
			rdPtr->currrow=(rdPtr->numrows>=1);
			rdPtr->currcol=(rdPtr->numcols>=1);

			if ((rdPtr->numrows == 0) && (rdPtr->numcols == 0))
			{
				// there should have been no results from the previous query
				if (rdPtr->results)
					sqldb_free_table(rdPtr->results);
				// This compensates for a funny behavior that seems to exist
				// with SQLDB. If the prior SQL statement did not return any 
				// data (such as an insert), a 2-byte allocation of memory seems to
				// get returns in the results array, and the data in this allocation
				// does not appear to contain anything meaningful. This IF statement
				// ensures the result set is clear when no results are expected. I made
				// an associated change in the SQLDB table.c file to support this.
				rdPtr->results = NULL;

			}
				
		}
	}

	return 0;

}

//----------------------------------------------------------------------------
// SETROW
//
// This function sets the current row index in the result set
//
// INPUT PARAMETERS
//	p1 = row index
//
// RESULT
//  none
//
short WINAPI DLLExport actionSetRow(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->results != NULL)
	{
		// limit  index to current result set size
		if ((param1 <= rdPtr->numrows) &&
			(param1 >= 0))  
		{
			rdPtr->currrow = param1;
		}
		else
			rdPtr->currrow = 1;		// set to 1 if out-of-range
	}
	else
		rdPtr->currrow = 0;		// set to zero if no data

	return 0;

}

//----------------------------------------------------------------------------
// SETCOL
//
// This function sets the current col index in the result set
//
// INPUT PARAMETERS
//	p1 = col index
//
// RESULT
//  none
//
short WINAPI DLLExport actionSetCol(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->results != NULL)
	{
		// limit  index to current result set size
		if ((param1 <= rdPtr->numcols) &&
			(param1 >= 0)) 
		{
			rdPtr->currcol = param1;
		}
		else
			rdPtr->currcol = 1;		// set to 1 if out-of-range
	}
	else
		rdPtr->currcol = 0;		// set to zero if no data

	return 0;

}

//----------------------------------------------------------------------------
// CLEARERR
//
// This function clears the previous SQL execution error
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  none
//
short WINAPI DLLExport actionClearErr(LPRDATA rdPtr, long param1, long param2)
{

	if (rdPtr->err != 0)
	{
		rdPtr->err=0;
		if (rdPtr->errmsg != NULL)
		{
			// error message was allocated and created by SQLDB engine
			sqldb_freemem(rdPtr->errmsg);
			rdPtr->errmsg = NULL;
		}
	}
	return 0;

}

//============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

//----------------------------------------------------------------------------
// DATA
//
// This function returns the data element at the current row and col index
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  string containing contents of result cell, or
//		"SQLDB: No Data Present" if no result set exists
//		"SQLDB: Current indexes not valid" if current object indexes are out-of-whack
//		"\0": If result cell contains empty string or null


long WINAPI DLLExport expressionData(LPRDATA rdPtr, long param1)
{
	// param 1 is not used
	
	rdPtr->rHo.hoFlags |= HOF_STRING;

	long index;

	// if results exist
	if (rdPtr->results != NULL) 
	{
		// verify we have valid indexes
		if ((rdPtr->currrow>=0) && (rdPtr->currcol>0) &&
		    (rdPtr->currrow<=rdPtr->numrows) && (rdPtr->currcol<=rdPtr->numcols))
		{
			// compute index of result data element
			index = (rdPtr->numcols * rdPtr->currrow) + rdPtr->currcol - 1;

			// check if we have result data at the specified index
			if (rdPtr->results[index]!=NULL)
			{
				// we have data, determine the size of the return string
				int size = strlen(rdPtr->results[index]);
				if (size > 0)
				{
					// allocate memory for return string from MMF
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					strcpy(retString,rdPtr->results[index]);
					return (long) retString;
				}
				else
				{
					// nothing to return, string was zero length
					int size = 1;
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					retString[0]='\0';
					return (long) retString;
				}
			}
			else
			{
				// result data was null at specified index,
				int size = 1;
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				retString[0]='\0';
				return (long) retString;
				// result data was null at specified index, return special string
				/*
				int size = strlen("NULL");
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				strcpy(retString,"NULL");
				return (long) retString;
				*/
			}
		}
		else
		{ // we do not have valid indexes, return special string
			int size = strlen("SQLDB: Current indexes not valid");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"SQLDB: Current indexes not valid");
			return (long) retString;
		} // we do not have valid indexes
	}
	else
	{
		// there is no data in the result set, return special string
		int size = strlen("SQLDB: No Data Present");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: No Data Present");
		return (long) retString;
	}

}

//----------------------------------------------------------------------------
// DATACOLNAME
//
// This function obtains an element of the result data set according to the current row, and 
// the column specified by name.
//
// INPUT PARAMETERS
//	p1 = column name
//
// RESULT
//  string containing contents of result cell, or
//		"SQLDB: No Data Present" if no result set exists
//		"SQLDB: Invalid Column Name" if requested column name is not valid
//		"SQLDB: Could not locate column" if the specified column could not be found

long WINAPI DLLExport expressionDataColbyName(LPRDATA rdPtr, long param1)
{
	char * p1=(LPSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// check for valid column name
	if (p1==0)
	{
		// the input column name was NULL
		int size = strlen("SQLDB: Invalid Column Name");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: Invalid Column Name");
		return (long) retString;
	}

	int tmpCol=-1;	// initial column to fetch is not set
	int i=0;		// loop index

	// Attempt to locate the desired column by name
	while (i<=(rdPtr->numcols-1))
	{
		if (_stricmp( rdPtr->results[i], p1 )==0)
		{
			// strings are equal ignoring case, so save this index
			tmpCol=i;
			i=rdPtr->numcols-1;	// force while exit on first match
		}
		i++;
	}

	// see if we could not locate the desired column
	if (tmpCol<0)
	{
		int size = strlen("SQLDB: Could not locate column");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: Could not locate column");
		return (long) retString;

	}
	else // column was found
	{

		// Check if result data set exists
		if (rdPtr->results != NULL) 
		{
			// look up data in current row and specified column
			long index = (rdPtr->numcols * rdPtr->currrow) + tmpCol;

			// ensure we have data at specified index
			if (rdPtr->results[index]!=NULL)
			{
				// check for result string of length > 0 (should be null terminated minimum)
				int size = strlen(rdPtr->results[index]);
				if (size > 0)
				{
					// set return data to contents of result set
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					strcpy(retString,rdPtr->results[index]);
					return (long) retString;
				}
				else
				{	
					// nothing to return, string was zero length
					int size = 1;
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					retString[0]='\0';
					return (long) retString;
				}
			}
			else
			{
				// result data was null at specified index,
				int size = 1;
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				retString[0]='\0';
				return (long) retString;
				// result data was null at specified index, return special string
				/*
				int size = strlen("NULL");
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				strcpy(retString,"NULL");
				return (long) retString;
				*/
			}
		}
		else
		{
			int size = strlen("SQLDB: No Data Present");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"SQLDB: No Data Present");
			return (long) retString;
		}
	} // column was found

}


//----------------------------------------------------------------------------
// DATAROWCOL
//
// This function obtains an element of the result data set according to the specified row and 
// column, both being specified by index
//
// INPUT PARAMETERS
//	p1 = row index
//	p2 = column index
//
// RESULT
//  string containing contents of result cell, or
//		"SQLDB: No Data Present" if no result set exists
//		0 in the case of other errors

long WINAPI DLLExport expressionDataRowCol(LPRDATA rdPtr, long param1)
{
	int p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	int p2=CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// constrain requested row and column indexes to valid range
	if (p1 > rdPtr->numrows)		// row 0-n
		p1=rdPtr->numrows;
	if (p1 <= 0)
		p1=0;
	if (p2 > rdPtr->numcols)		// column 1-m
		p2=rdPtr->numcols;
	if (p2 <= 0)
		p2=1;

	if (rdPtr->results != NULL) 
	{
		long index = (rdPtr->numcols * p1) + p2 - 1;

		if (rdPtr->results[index]!=NULL)
		{
			int size = strlen(rdPtr->results[index]);
			if (size > 0)
			{
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				strcpy(retString,rdPtr->results[index]);
				return (long) retString;
			}
			else
				{	
					// nothing to return, string was zero length
					int size = 1;
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					retString[0]='\0';
					return (long) retString;
				}
		}
		else
			{
				// result data was null at specified index,
				int size = 1;
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				retString[0]='\0';
				return (long) retString;
				// result data was null at specified index, return special string
				/*
				int size = strlen("NULL");
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				strcpy(retString,"NULL");
				return (long) retString;
				*/
			}
	}
	else
	{
		int size = strlen("SQLDB: No Data Present");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: No Data Present");
		return (long) retString;
	}

}

//----------------------------------------------------------------------------
// DATAROWCOLNAME
//
// This function obtains an element of the result data set according to the specified row, and 
// the column specified by name.
//
// INPUT PARAMETERS
//	p1 = row index
//	p2 = column name
//
// RESULT
//  string containing contents of result cell, or
//		"SQLDB: No Data Present" if no result set exists
//		"SQLDB: Invalid Column Name" if requested column name is not valid
//		"SQLDB: Could not locate column" if the specified column could not be found
//		0 in the case of other errors

long WINAPI DLLExport expressionDataRowColbyName(LPRDATA rdPtr, long param1)
{
	int p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	char * p2=(LPSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// constrain requested row index to valid range
	if (p1 > rdPtr->numrows)		// row 0-n
		p1=rdPtr->numrows;
	if (p1 <= 0)
		p1=0;

	// check for valid column name
	if (p2==0)
	{
		// the input column name was NULL
		int size = strlen("SQLDB: Invalid Column Name");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: Invalid Column Name");
		return (long) retString;
	}

	int tmpCol=-1;	// initial column to fetch is not set
	int i=0;		// loop index

	// Attempt to locate the desired column by name
	while (i<=(rdPtr->numcols-1))
	{
		if (_stricmp( rdPtr->results[i], p2 )==0)
		{
			// strings are equal ignoring case, so save this index
			tmpCol=i;
			i=rdPtr->numcols-1;	// force while exit on first match
		}
		i++;
	}

	// see if we could not locate the desired column
	if (tmpCol<0)
	{
		int size = strlen("SQLDB: Could not locate column");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: Could not locate column");
		return (long) retString;

	}
	else // column was found
	{
		// Check if result data set exists
		if (rdPtr->results != NULL) 
		{
			// compute index of desired result data
			long index = (rdPtr->numcols * p1) + tmpCol;

			// ensure we have data at specified index
			if (rdPtr->results[index]!=NULL)
			{
				// check for result string of length > 0 (should be null terminated minimum)
				int size = strlen(rdPtr->results[index]);
				if (size > 0)
				{
					// set return data to contents of result set
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					strcpy(retString,rdPtr->results[index]);
					return (long) retString;
				}
				else
				{	
					// nothing to return, string was zero length
					int size = 1;
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					retString[0]='\0';
					return (long) retString;
				}
			}
			else
			{
				// result data was null at specified index,
				int size = 1;
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				retString[0]='\0';
				return (long) retString;
				// result data was null at specified index, return special string
				/*
				int size = strlen("NULL");
				char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
				strcpy(retString,"NULL");
				return (long) retString;
				*/
			}
		}
		else
		{
			int size = strlen("SQLDB: No Data Present");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"SQLDB: No Data Present");
			return (long) retString;
		}
	} // column was found
}

//----------------------------------------------------------------------------
// COLUMNNAME
//
// This function returns the column name of the current column
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  string containing name of current column
//	"SQLDB: No Columns Present" if no result set exists
//
long WINAPI DLLExport expressionColumnName(LPRDATA rdPtr, long param1)
{

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// make sure we have results
	if (rdPtr->results != NULL) 
	{
		long index;

		// verify we have valid current column
		if ((rdPtr->currcol>0) && (rdPtr->currcol<=rdPtr->numcols))
		{
			// use first row (index = 0) which is column headings
			// column is based on current column
			index = 0 + rdPtr->currcol - 1;
			
			int size = strlen(rdPtr->results[index]);
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,rdPtr->results[index]);
			return (long) retString;
		}
		else
		{
			// column index is not valid, no data to return
			int size = strlen("SQLDB: Bad Current Column Index");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"SQLDB: Bad Current Column Index");
			return (long) retString;
			// This case should not happen, as the component
			// is supposed to always keep the current column index
			// as non-zero when there is a result set.
		}

	}
	else
	// there were no results, return special string
	{
		int size = strlen("SQLDB: No Columns Present");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: No Columns Present");
		return (long) retString;
	}

}

//----------------------------------------------------------------------------
// COLUMNNAMEBYCOL
//
// This function returns the column name of the specified column
//
// INPUT PARAMETERS
//	requested column index to return the name
//
// RESULT
//  string containing name of specified column
//	"SQLDB: No Columns Present" if no result set exists
//
long WINAPI DLLExport expressionColumnNamebyCol(LPRDATA rdPtr, long param1)
{

	int p1=CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	// constrain requested col index to valid range
	if (p1 > rdPtr->numcols)		// col 1-n
		p1=rdPtr->numcols;
	if (p1 <= 0)
		p1=1;

	// make sure we have results
	if (rdPtr->results != NULL) 
	{
		// use first row which is column headings
		// column is based on current column
		long index = 0 + p1 - 1;

		int size = strlen(rdPtr->results[index]);
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,rdPtr->results[index]);
		return (long) retString;
	}
	else
	// there were no results, return special string
	{
		int size = strlen("SQLDB: No Columns Present");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: No Columns Present");
		return (long) retString;
	}

}




//----------------------------------------------------------------------------
// ROWS
//
// This function returns the number of rows in the result set
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  number of rows, may be zero
//
long WINAPI DLLExport expressionRows(LPRDATA rdPtr, long param1)
{
	//char * p1=(LPSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	return rdPtr->numrows;

}


//----------------------------------------------------------------------------
// COLS
//
// This function returns the number of cols in the result set
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  number of cols, may be zero
//
long WINAPI DLLExport expressionCols(LPRDATA rdPtr, long param1)
{

	return rdPtr->numcols;

}

//----------------------------------------------------------------------------
// ERROR
//
// This function returns the error code of the last SQL execute error
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  erorr code
//
long WINAPI DLLExport expressionErr(LPRDATA rdPtr, long param1)
{

	return rdPtr->err;

}

//----------------------------------------------------------------------------
// ERRORMSG
//
// This function returns the error message of the last SQL execute error
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  erorr message
//
long WINAPI DLLExport expressionErrMsg(LPRDATA rdPtr, long param1)
{
	//char * p1=(LPSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	rdPtr->rHo.hoFlags |= HOF_STRING;

	if (rdPtr->errmsg == NULL)
	{
		if (rdPtr->err == 0)
		{
			int size = strlen("No Error");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"No Error");
			return (long) retString;
		}
		else
		{
			int size = strlen("Unspecified Error, is a database open?");
			char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
			strcpy(retString,"Unspecified Error, is a database open?");
			return (long) retString;
		}
	}
	else
	{
		int size = strlen(rdPtr->errmsg);
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,rdPtr->errmsg);
		return (long) retString;
	}
}


//----------------------------------------------------------------------------
// QUOTE
//
// This function returns a processed string suitable for use in a subsequent
// SQL query. Key processing includes replacing single quotes by double-single-quotes
// as required by SQLDB.
//
// INPUT PARAMETERS
//	input string (limited to 1000 characters in length)
//
// RESULT
//  result string 
//
long WINAPI DLLExport expressionQuote(LPRDATA rdPtr, long param1)
{
	char *p1=(LPSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	char **res;				// Results of query
	int cols,rows;
	char *errmsg;
	int err=0;
	char sql[1024] = "SELECT QUOTE(\"";

	rdPtr->rHo.hoFlags |= HOF_STRING;

	strncat( sql, p1, 1000 );
	strncat( sql, "\")", 2 );
	//quote(X)

	errmsg=NULL;
	res=NULL;

	if (p1==0)
	{
		int size = strlen("SQLDB: No String");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"SQLDB: No String");
		return (long) retString;

	}

	// execute the SQL statement to convert the string
	if (Global.db != NULL)
	{
		err = sqldb_get_table(
			Global.db,              /* An open database */
			sql,						/* SQL to be executed */
			&res,		/* Result written to a char *[]  that this points to */
			&rows,		/* Number of result rows written here */
			&cols,		/* Number of result columns written here */
			&errmsg			/* Error msg written here */
		);
	}

	if (errmsg == NULL)
	{
		if (err == 0)
		{
			if (res != NULL)
			{
				if (rows > 0)
				{
					// a valid result is present
					int size = strlen(res[1]);
					char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
					strcpy(retString,res[1]);
					sqldb_free_table(res);
					return (long) retString;
				}
			}
		}
		int size = strlen("Unspecified Error, is a database open?");
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,"Unspecified Error, is a database open?");
		return (long) retString;
	}
	else
	{
		int size = strlen(errmsg);
		char* retString = (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0);
		strcpy(retString,errmsg);
		sqldb_freemem(rdPtr->errmsg);
		return (long) retString;
	}
}

//----------------------------------------------------------------------------
// CURRROW
//
// This function returns the current row in the dataset
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  current row or 0
//
long WINAPI DLLExport expressionCurrRow(LPRDATA rdPtr, long param1)
{

	return rdPtr->currrow;

}
//----------------------------------------------------------------------------
// CURRCOL
//
// This function returns the error code of the last SQL execute error
//
// INPUT PARAMETERS
//	none
//
// RESULT
//  current row or 0
//
long WINAPI DLLExport expressionCurrCol(LPRDATA rdPtr, long param1)
{

	return rdPtr->currcol;

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
	conditionOnSQLError,
	conditionDBOpen,
	0
	};

short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
	{
	actionOpenFile,
	actionOpenFileSelect,
	actionCloseFile,
	actionRunSQL,
	actionSetRow,
	actionSetCol,
	actionClearErr,
	0
	};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) =
	{
	expressionData,
	expressionColumnName, 
	expressionRows,
	expressionCols,
	expressionErr,
	expressionErrMsg,
	expressionDataRowCol,
	expressionDataColbyName,
	expressionDataRowColbyName,
	expressionQuote,
	expressionCurrRow,
	expressionCurrCol,
	0
	};


 