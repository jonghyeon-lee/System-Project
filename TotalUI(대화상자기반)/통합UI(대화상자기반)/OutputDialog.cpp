// OutputDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "OutputDialog.h"
#include "afxdialogex.h"


// COutputDialog ��ȭ �����Դϴ�.

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


// COutputDialog �޽��� ó�����Դϴ�.
