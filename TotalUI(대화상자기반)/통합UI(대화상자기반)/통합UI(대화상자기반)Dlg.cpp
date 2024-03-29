
// 통합UI(대화상자기반)Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "통합UI(대화상자기반)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C통합UI대화상자기반Dlg 대화 상자



C통합UI대화상자기반Dlg::C통합UI대화상자기반Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C통합UI대화상자기반Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pwndShow = NULL;
	project_check = true;

}

void C통합UI대화상자기반Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
	DDX_Control(pDX, IDC_BUTTON1, m_button);
}

BEGIN_MESSAGE_MAP(C통합UI대화상자기반Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C통합UI대화상자기반Dlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_CREATE_PROJECT, &C통합UI대화상자기반Dlg::OnCreateProject)
	ON_BN_CLICKED(IDC_BUTTON1, &C통합UI대화상자기반Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C통합UI대화상자기반Dlg 메시지 처리기

BOOL C통합UI대화상자기반Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
 //   AfxInitRichEdit();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	CString tabOne = _T("ChartView");
	CString tabTwo = _T("CodeView");
	

		m_tabCtrl.InsertItem(1, tabOne);
		m_tabCtrl.InsertItem(2, tabTwo);

		CRect rect;
		m_tabCtrl.GetClientRect(&rect);

		m_chart.Create(IDD_CHARTVIEW, &m_tabCtrl);
		m_chart.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
		m_pwndShow = &m_chart;

		m_code.Create(IDD_CODEVIEW, &m_tabCtrl);
		m_code.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_NOZORDER);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void C통합UI대화상자기반Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void C통합UI대화상자기반Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR C통합UI대화상자기반Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C통합UI대화상자기반Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if(m_pwndShow != NULL)
	{
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}

	int tabIndex = m_tabCtrl.GetCurSel();

	switch(tabIndex)
	{
	case 0:
		m_chart.ShowWindow(SW_SHOW);
		m_pwndShow = &m_chart;
		SetTabIndex(tabIndex);
		break;
	case 1:
		m_code.ShowWindow(SW_SHOW);
		m_pwndShow = &m_code;
		SetTabIndex(tabIndex);
		
		break;
	}
	
	*pResult = 0;
}




void C통합UI대화상자기반Dlg::OnCreateProject()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CreateProject m_project;
	m_project.DoModal();
	ProjectName = m_project.GetEditString();
	CreateDirectory(_T("C:\\Users\\KimHyeJi\\Documents\\생각대로P"), NULL);
	CreateDirectory(_T("C:\\Users\\KimHyeJi\\Documents\\생각대로P\\"+ProjectName), NULL);
	m_chart.m_convert_botton.EnableWindow(1);
	m_chart.m_start_button.EnableWindow(1);
	project_check = false;

}

void C통합UI대화상자기반Dlg::OnBnClickedButton1()
{

}
