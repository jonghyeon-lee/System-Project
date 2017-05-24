// OutputDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "OutputDialog.h"
#include "afxdialogex.h"


// COutputDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(COutputDialog, CDialogEx)

COutputDialog::COutputDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(COutputDialog::IDD, pParent)
{

}

COutputDialog::~COutputDialog()
{
}

void COutputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutputDialog, CDialogEx)
END_MESSAGE_MAP()


// COutputDialog 메시지 처리기입니다.
