/////////////////////////////////////////////////////////////////////////////
// MooseCoreLib.h
//

#pragma once

#if defined(MOOSECORELIB_DLL_EXPORTS)

/* Compiling MooseCoreLib as a Windows DLL - export classes, functions, and globals */
#define MOOSECORELIB_CPP_CLASS __declspec(dllexport)
#define MOOSECORELIB_CPP_FUNCTION __declspec(dllexport)
#define MOOSECORELIB_CPP_DATA __declspec(dllexport)

#define MOOSECORELIB_C_FUNCTION extern "C" __declspec(dllexport)

#else

/* Using MooseCoreLib as a Windows DLL - import classes, functions, and globals */
#define MOOSECORELIB_CPP_CLASS __declspec(dllimport)
#define MOOSECORELIB_CPP_FUNCTION __declspec(dllimport)
#define MOOSECORELIB_CPP_DATA __declspec(dllimport)

#define MOOSECORELIB_C_FUNCTION extern "C" __declspec(dllimport)

#include "MooseCoreLibLinkingPragmas.h"

#endif


/////////////////////////////////////////////////////////////////////////////
// C++ exports

MOOSECORELIB_CPP_FUNCTION
void MooseSdkPrint( const wchar_t* str );

MOOSECORELIB_CPP_FUNCTION
double MooseSdkSum( double a, double b );

MOOSECORELIB_CPP_FUNCTION
ON_UUID MooseSdkAddPoint( const ON_3dPoint& point );


/////////////////////////////////////////////////////////////////////////////
// .NET Exports

struct ON_3DPOINT_STRUCT
{ 
  double val[3]; 
};


MOOSECORELIB_C_FUNCTION
void MoosePrint( const wchar_t* str );

MOOSECORELIB_C_FUNCTION
double MooseSum( double a, double b );

MOOSECORELIB_C_FUNCTION
ON_UUID MooseAddPoint( ON_3DPOINT_STRUCT point );

MOOSECORELIB_C_FUNCTION
int MooseFunction(const ON_Brep* pConstBrep, int x, int y, ON_3dPointArray* pPoints, ON_SimpleArray<ON_Line>* pLines);
