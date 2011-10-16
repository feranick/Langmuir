// Langmuir.h : main header file for the LANGMUIR application
//

#if !defined(AFX_LANGMUIR_H__4B42BC07_8E9E_48A1_BDCD_1625A0B22B65__INCLUDED_)
#define AFX_LANGMUIR_H__4B42BC07_8E9E_48A1_BDCD_1625A0B22B65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLangmuirApp:
// See Langmuir.cpp for the implementation of this class
//

class CLangmuirApp : public CWinApp
{
public:
	CLangmuirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLangmuirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLangmuirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANGMUIR_H__4B42BC07_8E9E_48A1_BDCD_1625A0B22B65__INCLUDED_)
