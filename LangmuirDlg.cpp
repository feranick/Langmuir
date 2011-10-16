// LangmuirDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Langmuir.h"
#include "LangmuirDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLangmuirDlg dialog

CLangmuirDlg::CLangmuirDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLangmuirDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLangmuirDlg)
m_displang = _T("");
	m_pressure = _T("1.0e-7");
	m_seconds = _T("60.0");
	m_mbar = TRUE;
	m_torr = FALSE;
	mbartotorr=0.7500638;
	Lconst=1.0E-6;
	m_displang= "4.5";
	m_minutes = _T("1.0");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLangmuirDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLangmuirDlg)
	DDX_Text(pDX, IDC_DISPLANG, m_displang);
	DDX_Text(pDX, IDC_PRESSURE, m_pressure);
	DDX_Text(pDX, IDC_SECONDS, m_seconds);
	DDX_Check(pDX, IDC_MBAR, m_mbar);
	DDX_Check(pDX, IDC_TORR, m_torr);
	DDX_Text(pDX, IDC_MINUTES, m_minutes);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLangmuirDlg, CDialog)
	//{{AFX_MSG_MAP(CLangmuirDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUTBTN, OnAboutbtn)
	ON_EN_CHANGE(IDC_PRESSURE, OnChangePressure)
	ON_EN_CHANGE(IDC_SECONDS, OnChangeSeconds)
	ON_EN_CHANGE(IDC_MINUTES, OnChangeMinutes)
	ON_EN_CHANGE(IDC_DISPLANG, OnChangeDisplang)
	ON_BN_CLICKED(IDC_MBAR, OnMbar)
	ON_BN_CLICKED(IDC_TORR, OnTorr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLangmuirDlg message handlers

BOOL CLangmuirDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLangmuirDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLangmuirDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLangmuirDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLangmuirDlg::OnAboutbtn() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg Dlg3;
	Dlg3.DoModal();
}

void CLangmuirDlg::OnChangePressure() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	

	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);

	UpdateData(true);
if(m_mbar==true)
{result=(pressure*mbartotorr)*seconds/Lconst;
m_seconds.Format("%.1f", minutes*60.0);
m_displang.Format("%.2f", result);
UpdateData(false);
}


if(m_torr==true)
{	result=(pressure)*seconds/Lconst;
m_seconds.Format("%.1f", minutes*60.0);
m_displang.Format("%.2f", result);
UpdateData(false);
}
}

void CLangmuirDlg::OnChangeSeconds() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	

	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);


	UpdateData(true);
if(m_mbar==true)
{result=(pressure*mbartotorr)*seconds/Lconst;
m_minutes.Format("%.1f", seconds/60);
m_displang.Format("%.2f", result);
UpdateData(false);
}


if(m_torr==true)
{	result=(pressure)*seconds/Lconst;
m_displang.Format("%.2f", result);
m_minutes.Format("%.1f", seconds/60);
UpdateData(false);
}
}

void CLangmuirDlg::OnChangeMinutes() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
float minutes, seconds, pressure, displang;
	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);


	UpdateData(true);
if(m_mbar==true)
{result=(pressure*mbartotorr)*seconds/Lconst;
m_seconds.Format("%.1f", minutes*60.0);
m_displang.Format("%.2f", result);
UpdateData(false);
}


if(m_torr==true)
{	result=(pressure)*seconds/Lconst;
m_displang.Format("%.2f", result);
m_seconds.Format("%.1f", minutes/60.0);
UpdateData(false);
}
}

void CLangmuirDlg::OnChangeDisplang() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	float minutes, seconds, pressure, displang;

	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);

	UpdateData(true);
if(m_mbar==true)
{result=displang*Lconst/(pressure*mbartotorr);
m_minutes.Format("%.1f", result/60);
m_seconds.Format("%.2f", result);
UpdateData(false);
}


if(m_torr==true)
{	result=displang*Lconst/pressure;
m_minutes.Format("%.1f", result/60);
m_seconds.Format("%.2f", result);
UpdateData(false);
}
}

void CLangmuirDlg::OnMbar() 
{
	// TODO: Add your control notification handler code here
		UpdateData(true); 
	if( m_mbar==true )
		{m_torr=false;
		UpdateData(false);}
		else
		{UpdateData(false);}



	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);


	UpdateData(true);
if(m_mbar==true)
{result=(pressure*mbartotorr)*seconds/Lconst;
m_minutes.Format("%.1f", seconds/60);
m_displang.Format("%.2f", result);
UpdateData(false);
}
}
void CLangmuirDlg::OnTorr() 
{
	// TODO: Add your control notification handler code here
UpdateData(true); 
	if( m_torr==true )
		{m_mbar=false;
		UpdateData(false);}
		else
		{UpdateData(false);}



	UpdateData();

	// Evaluate the content of each operand edit box
	if( m_minutes.IsEmpty() )
		minutes = 0;
	else
		minutes = atof(m_minutes);

	if( m_seconds.IsEmpty() )
		seconds= 0;
	else
		seconds = atof(m_seconds);

	if( m_pressure.IsEmpty() )
		pressure = 0;
	else
		pressure = atof(m_pressure);
	if( m_displang.IsEmpty() )
		displang = 0;
	else
		displang = atof(m_displang);


	UpdateData(true);
if(m_mbar==true)
{result=(pressure*mbartotorr)*seconds/Lconst;
m_minutes.Format("%.1f", seconds/60);
m_displang.Format("%.2f", result);
UpdateData(false);	
}
}