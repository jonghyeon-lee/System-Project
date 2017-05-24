// ForDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "ForDialog.h"
#include "afxdialogex.h"


// CForDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CForDialog, CDialogEx)

CForDialog::CForDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CForDialog::IDD, pParent)
{

}

CForDialog::~CForDialog()
{
}

void CForDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CForDialog, CDialogEx)
END_MESSAGE_MAP()


// CForDialog 메시지 처리기입니다.
