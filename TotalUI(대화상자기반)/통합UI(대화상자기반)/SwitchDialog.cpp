// SwitchDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "SwitchDialog.h"
#include "afxdialogex.h"


// CSwitchDialog ��ȭ �����Դϴ�.

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


// CSwitchDialog �޽��� ó�����Դϴ�.
