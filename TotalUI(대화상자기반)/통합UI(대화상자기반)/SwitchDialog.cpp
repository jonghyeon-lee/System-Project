// SwitchDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "SwitchDialog.h"
#include "afxdialogex.h"


// CSwitchDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSwitchDialog, CDialogEx)

CSwitchDialog::CSwitchDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSwitchDialog::IDD, pParent)
{

}

CSwitchDialog::~CSwitchDialog()
{
}

void CSwitchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSwitchDialog, CDialogEx)
END_MESSAGE_MAP()


// CSwitchDialog 메시지 처리기입니다.
