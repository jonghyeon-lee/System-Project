// WhileDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "WhileDialog.h"
#include "afxdialogex.h"


// CWhileDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CWhileDialog, CDialogEx)

CWhileDialog::CWhileDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWhileDialog::IDD, pParent)
{

}

CWhileDialog::~CWhileDialog()
{
}

void CWhileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWhileDialog, CDialogEx)
END_MESSAGE_MAP()


// CWhileDialog 메시지 처리기입니다.
