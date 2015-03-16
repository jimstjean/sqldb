/*
 *		TigsExt.cpp
 *
 *		Function definitions for the Extension SDK (made for the MMFireSDK)
 *		Included by TigsExt.h
 *		Tigerworks, 2003  v1.0
 *		www.tigerworks.co.uk tigerworks@blueyonder.co.uk
 */

// Common include
#include "common.h"

///////////////////
// MISCELLANEOUS //
///////////////////

// ErrCheck:  Returns an integer limited by the given bounds
// int number:  number you wish to check
// int min: minimum value for this number
// int max: maximum value for this number
// Example:  int myvalue = ErrCheck(Value, 0, 25);
int ErrCheck(int number, int min, int max)
{
	if (number > max) number = max;
	if (number < min) number = min;
	return number;
}

// Float version
float ErrCheck(float number, float min, float max)
{
	if (number > max) number = max;
	if (number < min) number = min;
	return number;
}

// IsInBounds:  returns TRUE if the given value is between the two given numbers
int IsInBounds(int number, int min, int max)
{
	if (number < min || number > max)
		return FALSE;
	else return TRUE;
}


// GetIntAltVal:  Get integer alterable value from object LPRO
// LPRO object:  the object LPRO that you want to retrieve the alterable value from
// int ValNum:  alterable value index to retrieve:  0 is value A, 1 is value B, up to 25
int GetIntAltVal(LPRO object, int ValNum)
{
	if (!IsInBounds(ValNum,0,25))
		return 0;

	if (object->rov.rvValuesType[ValNum] == 0)			// Is integer alterable value
		return object->rov.rvValues[ValNum].longValue;	// Return that value
	if (object->rov.rvValuesType[ValNum] == 2)			// Is float alterable value
		return (int)object->rov.rvValues[ValNum].floatValue;	// Convert to int and return

	return 0; // should be impossible
}

// Float version
float GetFloatAltVal(LPRO object, int ValNum)
{
	if (!IsInBounds(ValNum,0,25))
		return 0;

	if (object->rov.rvValuesType[ValNum] == 0)			// Is integer alterable value
		return (float)object->rov.rvValues[ValNum].longValue;	// Convert to float and return
	if (object->rov.rvValuesType[ValNum] == 2)			// Is float alterable value
		return object->rov.rvValues[ValNum].floatValue;	// Return that float

	return 0; // should be impossible
}

// FixedVal(Object):  Returns the fixed value of the given object LPRO
int FixedVal(LPRO object)
{ return ((object->roHo.hoCreationId << 16) + object->roHo.hoNumber); }



////////////////
// PARAMETERS //
////////////////

// Get float parameter for actions/conditions
float GetFloatParam(LPRDATA rdPtr)
{
	long tmpf = CNC_GetFloatParameter(rdPtr);
	float param = *(float*)&tmpf;
	return param;
}

// SetReturnString:  Tells MMF that the current expression is going to return a string
void SetReturnString(LPRDATA rdPtr)
{	rdPtr->rHo.hoFlags |= HOF_STRING;	}



///////////////////////
// RUNTIME FUNCTIONS //
///////////////////////

// GenerateEvent:  *instantly* generates an event
void GenerateEvent(LPRDATA rdPtr, int EventID)
{	callRunTimeFunction(rdPtr,RFUNCTION_GENERATEEVENT,EventID,0); }

// PushEvent:  same as GenerateEvent, but the event is only generated at the end of MMF's event loop
void PushEvent(LPRDATA rdPtr, int EventID)
{	callRunTimeFunction(rdPtr,RFUNCTION_PUSHEVENT,EventID,0); }

// DestroyObject:  destroys your object like the Destroy action (will call DestroyRunObject etc. etc.)
void DestroyObject(LPRDATA rdPtr)
{	callRunTimeFunction(rdPtr,RFUNCTION_DESTROY,0,0);	}

// ReHandleObject:  start calling HandleRunObject() again
void ReHandleObject(LPRDATA rdPtr)
{	callRunTimeFunction(rdPtr,RFUNCTION_REHANDLE,0,0);	}

// GetStringSpace:  gets some string space for an expression to return a string with.
// returns a pointer to your new memory.  MMF will automatically free this memory soon after your expression routine finishes
char* GetStringSpace(LPRDATA rdPtr, int size)
{	return (char *)callRunTimeFunction(rdPtr,RFUNCTION_GETSTRINGSPACE,size,0); }

// GetActionLoopCount(rdPtr): if you use PARAM_OBJECT as your first parameter, MMF will repeat your action
// for every one of those objects that met the event.  This will return the index of the action repetition
// e.g. 0 is the first run of the action, 1 is the next, etc.
int GetActionLoopCount(LPRDATA rdPtr)
{	return rdPtr->rHo.hoAdRunHeader->rh2.rh2ActionLoopCount; }

// IsLastActionLoop:  As above, when MMF is looping your action for objects, this will return
// TRUE the LAST time MMF is running the action for you.
bool IsLastActionLoop(LPRDATA rdPtr)
{
	if (rdPtr->rHo.hoAdRunHeader->rh2.rh2ActionLoop == 0)
		return TRUE;
	else return FALSE;
}

//////////////////////
// TIMING FUNCTIONS //
//////////////////////

// This value starts at 0 when the frame begins and counts up 100 every 1 second, constantly
long GetTimer()
{	return (clock() / 10);	}

//////////////////////
// STRING FUNCTIONS //
//////////////////////


// Convert character to uppercase
char UpperChar(char ch)
{
	// If in the range of a lowercase char
	if ((ch > 96) && (ch < 123))
		ch -= 32;	// Subtract down to range of an uppercase char

	return ch;
}

// Convert a character to lowercase
char LowerChar(char ch)
{
	// If in the range of an uppercase char
	if ((ch > 64) && (ch < 91))
		ch += 32;	// Add up to lowercase char

	return ch;
}


// Angle between two points
int GetAngle(int x1, int y1, int x2, int y2)
{
	double answer = (atan2(((double)y2 - (double)y1),((double)x2 - (double)x1)) * RADtoDEG) * -1 + 450;

	// Convert to integer
	return ((int)answer) % 360;
}

// Distance between 2 points
int GetDistance(int xp, int yp, int xp2, int yp2)
{
	// Allow decimal calculation
	double x = xp;
	double y = yp;
	double x2 = xp2;
	double y2 = yp2;

	return (int)sqrt((dif(x,x2) * dif(x,x2))+(dif(y,y2) * dif(y,y2)));
}

// RotateToward():  Direction-calculator style rotate towards direction.  Works in 360 degrees too.
// int CurAngle:  Current angle/direction
// int TargetAngle:  Angle/direction you want to rotate towards
// int RotateAmt:  Amount of directions to rotate (e.g. 4 will rotate 4 degrees a time in 360 directions
// int Directions:  use 32 for 32 direction rotation, or 360 for 360 degree rotation, or even a custom amount (e.g. 8 will still work in 8-dirs)
int RotateToward(int CurAngle, int TargetAngle, int RotateAmt, int Directions)
{
	LONG rightdist = (Directions + (CurAngle - TargetAngle)) % Directions;
	LONG leftdist  = (Directions + (TargetAngle - CurAngle)) % Directions;

	// Distance right is shorter, AND distance right is greater than rotate amount
	if ((rightdist <= leftdist) && (rightdist >= RotateAmt))
		return (Directions + (CurAngle - RotateAmt)) % Directions;		// Rotate by amount

	// Distance right is shorter AND distance right is less than rotate amount
	if ((rightdist <= leftdist) && (rightdist < RotateAmt))
		return (Directions + TargetAngle) % Directions;		// Target direction can be reached immediately

	// Left distance is shorter AND distance left is greater than rotate amount
	if ((rightdist > leftdist) && (leftdist >= RotateAmt))
		return (Directions + (CurAngle + RotateAmt)) % Directions;		// Rotate by amount

	if ((rightdist > leftdist) && (leftdist < RotateAmt))
		return (Directions + TargetAngle) % Directions;		// Target direction can be reached immediately

	// (Unreachable)
	return 0;

}

// Convert angle to direction
int AngToDir(LONG Angle)
{
	// Allow decimal calculations
	Angle = (Angle - 90) % 360;
	double Ang = (double)Angle;

	double Dir = (Ang + 95.625) / 11.25;

	LONG NewDir = (LONG)(32 + Dir);
	
	return NewDir % 32;
}
