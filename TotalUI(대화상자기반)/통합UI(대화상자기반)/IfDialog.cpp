// IfDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "IfDialog.h"
#include "afxdialogex.h"


// CIfDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CIfDialog, CDialogEx)

CIfDialog::CIfDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIfDialog::IDD, pParent)
{

}

CIfDialog::~CIfDialog()
{
}

void CIfDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CIfDialog, CDialogEx)
END_MESSAGE_MAP()


// CIfDialog 메시지 처리기입니다.
