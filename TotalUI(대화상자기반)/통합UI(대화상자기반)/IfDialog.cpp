// IfDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "IfDialog.h"
#include "afxdialogex.h"


// CIfDialog ��ȭ �����Դϴ�.

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


// CIfDialog �޽��� ó�����Դϴ�.
