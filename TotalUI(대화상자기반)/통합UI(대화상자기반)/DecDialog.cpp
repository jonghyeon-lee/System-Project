// DecDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "통합UI(대화상자기반)Dlg.h"
#include "DecDialog.h"
#include "afxdialogex.h"



// CDecDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDecDialog, CDialogEx)

CDecDialog::CDecDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDecDialog::IDD, pParent)
{
	ok_check = true;
}

CDecDialog::~CDecDialog()
{
}

void CDecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_DEC_NAME, m_value_name);
	DDX_Control(pDX, IDC_DEC_NAME, m_value_name);
	DDX_Control(pDX, IDC_DEC_DEFAULT, m_value_default);
	DDX_Control(pDX, IDC_DEC_TYPE, m_value_type);
}


BEGIN_MESSAGE_MAP(CDecDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDecDialog::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_DEC_TYPE, &CDecDialog::OnCbnSelchangeDecType)
END_MESSAGE_MAP()


// CDecDialog 메시지 처리기입니다.


void CDecDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true);
//	CString s;
//	ChartView *chart_view = (ChartView *)AfxGetApp();
//	CButton b = chart_view->m_start_button;
//	chart_view->m_start_button.SetWindowTextA(s);
//	AfxMessageBox(s);
//	CDC* pic = chart_view->m_pic.GetWindowDC();
//	pic->Rectangle(0, 0, 368, 40);

//	chart_view->m_pic.ReleaseDC(pic);
	/*
	CString s;
	GetDlgItemText(IDC_DEC_NAME, s);
	MessageBoxA(s);
	C통합UI대화상자기반Dlg *t = (C통합UI대화상자기반Dlg *)AfxGetMainWnd();
	t->m_button.SetWindowTextA(s);
	*/

	m_value_name.GetWindowTextA(v_name);
	m_value_default.GetWindowTextA(v_default);

	ok_check = false;
	CDialogEx::OnOK();
}


void CDecDialog::OnCbnSelchangeDecType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index;
	index = m_value_type.GetCurSel();
	m_value_type.GetLBText(index, v_type);
	SetDlgItemText(IDC_DEC_TYPE, v_type);
}
