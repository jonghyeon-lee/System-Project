#pragma once
#include "afxwin.h"


// CreateProject ��ȭ �����Դϴ�.

class CreateProject : public CDialogEx
{
	DECLARE_DYNAMIC(CreateProject)

public:
	CreateProject(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CreateProject();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROJECT_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	
	CString str;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void SetEditString(CString s){str = s;}
	afx_msg CString GetEditString(){return str;}
	afx_msg void OnBnClickedOk();
	CEdit m_project_name;
};
