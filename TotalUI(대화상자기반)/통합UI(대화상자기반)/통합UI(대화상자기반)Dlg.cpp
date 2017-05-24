
// ����UI(��ȭ���ڱ��)Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "����UI(��ȭ���ڱ��)Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// C����UI��ȭ���ڱ��Dlg ��ȭ ����



C����UI��ȭ���ڱ��Dlg::C����UI��ȭ���ڱ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����UI��ȭ���ڱ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pwndShow = NULL;
	project_check = true;

}

void C����UI��ȭ���ڱ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
	DDX_Control(pDX, IDC_BUTTON1, m_button);
}

BEGIN_MESSAGE_MAP(C����UI��ȭ���ڱ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C����UI��ȭ���ڱ��Dlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_CREATE_PROJECT, &C����UI��ȭ���ڱ��Dlg::OnCreateProject)
	ON_BN_CLICKED(IDC_BUTTON1, &C����UI��ȭ���ڱ��Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C����UI��ȭ���ڱ��Dlg �޽��� ó����

BOOL C����UI��ȭ���ڱ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
 //   AfxInitRichEdit();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

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


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void C����UI��ȭ���ڱ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void C����UI��ȭ���ڱ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR C����UI��ȭ���ڱ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����UI��ȭ���ڱ��Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
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




void C����UI��ȭ���ڱ��Dlg::OnCreateProject()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CreateProject m_project;
	m_project.DoModal();
	ProjectName = m_project.GetEditString();
	CreateDirectory(_T("C:\\Users\\KimHyeJi\\Documents\\�������P"), NULL);
	CreateDirectory(_T("C:\\Users\\KimHyeJi\\Documents\\�������P\\"+ProjectName), NULL);
	m_chart.m_convert_botton.EnableWindow(1);
	m_chart.m_start_button.EnableWindow(1);
	project_check = false;

}

void C����UI��ȭ���ڱ��Dlg::OnBnClickedButton1()
{

}
