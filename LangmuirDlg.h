// LangmuirDlg.h : header file
//

#if !defined(AFX_LANGMUIRDLG_H__EF54314D_F638_4A12_898F_A33807075878__INCLUDED_)
#define AFX_LANGMUIRDLG_H__EF54314D_F638_4A12_898F_A33807075878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLangmuirDlg dialog

class CLangmuirDlg : public CDialog
{
// Construction
public:
	CLangmuirDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLangmuirDlg)
	enum { IDD = IDD_LANGMUIR_DIALOG };
	CString	m_displang;
	CString	m_pressure;
	CString	m_seconds;
	BOOL	m_mbar;
	BOOL	m_torr;
	CString	m_minutes;
		float minutes, seconds, pressure, displang, result;
	float mbartotorr;
	float Lconst;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLangmuirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLangmuirDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAboutbtn();
	afx_msg void OnChangePressure();
	afx_msg void OnChangeSeconds();
	afx_msg void OnChangeMinutes();
	afx_msg void OnChangeDisplang();
	afx_msg void OnMbar();
	afx_msg void OnTorr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LANGMUIRDLG_H__EF54314D_F638_4A12_898F_A33807075878__INCLUDED_)
