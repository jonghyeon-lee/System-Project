// InputDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "InputDialog.h"
#include "afxdialogex.h"


// CInputDialog ��ȭ �����Դϴ�.

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


// CInputDialog �޽��� ó�����Դϴ�.
