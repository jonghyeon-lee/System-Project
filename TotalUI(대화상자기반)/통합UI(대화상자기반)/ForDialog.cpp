// ForDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "ForDialog.h"
#include "afxdialogex.h"


// CForDialog ��ȭ �����Դϴ�.

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


// CForDialog �޽��� ó�����Դϴ�.
