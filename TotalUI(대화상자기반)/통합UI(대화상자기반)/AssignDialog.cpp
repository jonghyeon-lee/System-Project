// AssignDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "AssignDialog.h"
#include "afxdialogex.h"


// CAssignDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CAssignDialog, CDialogEx)

CAssignDialog::CAssignDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAssignDialog::IDD, pParent)
{

}

CAssignDialog::~CAssignDialog()
{
}

void CAssignDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAssignDialog, CDialogEx)
END_MESSAGE_MAP()


// CAssignDialog 메시지 처리기입니다.
