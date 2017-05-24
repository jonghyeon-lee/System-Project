// CreateProject.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "CreateProject.h"
#include "afxdialogex.h"


// CreateProject 대화 상자입니다.

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


// CreateProject 메시지 처리기입니다.


void CreateProject::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
	m_project_name.GetWindowText(str);
}
