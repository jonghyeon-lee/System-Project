// InputDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "InputDialog.h"
#include "afxdialogex.h"


// CInputDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInputDialog, CDialogEx)

CInputDialog::CInputDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDialog::IDD, pParent)
{

}

CInputDialog::~CInputDialog()
{
}

void CInputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInputDialog, CDialogEx)
END_MESSAGE_MAP()


// CInputDialog 메시지 처리기입니다.
