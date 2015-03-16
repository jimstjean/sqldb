/*
 *		TigsExt.h
 *
 *		Function prototypes for the Extension SDK (made for the MMFireSDK)
 *		See TigsExt.cpp
 *		Tigerworks, 2003  v1.0
 *		www.tigerworks.co.uk tigerworks@blueyonder.co.uk
 */


#ifndef TIGSEXT	// Escape multiple inclusion
#define TIGSEXT

#include <time.h>

////////////////
// PROTOTYPES //
////////////////
int ErrCheck(int,int,int);			// Error check an integer
float ErrCheck(float,float,float);	// Error check a float
int IsInBounds(int,int,int);		// Integer is between two numbers
int GetIntAltVal(LPRO,int);			// Get integer alterable value
float GetFloatAltVal(LPRO,int);		// Get float alterable value
int FixedVal(LPRO);					// Get fixed value of an object
float GetFloatParam(LPRDATA);		// Get float parameter
void SetReturnString(LPRDATA);		// Set expression to return string
void GenerateEvent(LPRDATA,int);	// Generate event
void PushEvent(LPRDATA,int);		// Push event
void DestroyObject(LPRDATA);		// Destroy the object
void ReHandleObject(LPRDATA);		// Start calling HandleRunObject again
char* GetStringSpace(LPRDATA,int);	// Get temporary string space from MMF
int GetActionLoopCount(LPRDATA);	// Number of times action called by MMF for PARAM_OBJECT (starts at 0)
bool IsLastActionLoop(LPRDATA);		// Is last time action is being called by MMF for PARAM_OBJECT
long GetTimer();					// Timer count, 100 per second
char UpperChar(char);				// Convert a char to uppercase
char LowerChar(char);				// Convert a char to lowercase
int GetDistance(int,int,int,int);	// Distance between two points
int GetAngle(int,int,int,int);		// Angle between two points
int RotateToward(int,int,int,int);	// Rotate towards direction/angle
int AngToDir(LONG);					// Convert angle to direction



// Mathematical macros and definitions
#define RADtoDEG 180/3.14159		// Convert radians to degrees
#define max(a,b)  (((a) > (b)) ? (a) : (b))	// Macros
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#define abs(a)	  (((a) < 0) ? (-a) : (a))
#define dif(a,b)  (max(a,b) - min(a,b))




/////////////////////////////////////
// PARAM_ALTVALUE return structure //
/////////////////////////////////////

// PARAM_ALTVALUE returns a pointer to something (I don't know what)
// If you use it as a pointer to this structure, AltValIndex will hold the value you want
// (the index of the alterable value, 0 = value A, 1 = value B, up to 25)

typedef struct {
	long undefined;			// If you know what this data is for, contact me!
	BYTE AltValIndex;		// The alterable value index (the value you want)
} ParamAltValue;

/* example use
ParamAltValue* AltVal = (ParamAltValue*)param1;	// or CNC_GetParameter(rdPtr);
int AltValIndex = AltVal->AltValIndex;
*/


#endif // TIGSEXT









