// CreateProject.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "CreateProject.h"
#include "afxdialogex.h"


// CreateProject ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CreateProject, CDialogEx)

CreateProject::CreateProject(CWnd* pParent /*=NULL*/)
	: CDialogEx(CreateProject::IDD, pParent)
{

}

CreateProject::~CreateProject()
{
}

void CreateProject::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_project_name);
}


BEGIN_MESSAGE_MAP(CreateProject, CDialogEx)
	ON_BN_CLICKED(IDOK, &CreateProject::OnBnClickedOk)
END_MESSAGE_MAP()


// CreateProject �޽��� ó�����Դϴ�.


void CreateProject::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
	m_project_name.GetWindowText(str);
}
