#pragma once
#include "afxwin.h"


// CreateProject 대화 상자입니다.

class CreateProject : public CDialogEx
{
	DECLARE_DYNAMIC(CreateProject)

public:
	CreateProject(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CreateProject();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROJECT_NAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	
	CString str;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void SetEditString(CString s){str = s;}
	afx_msg CString GetEditString(){return str;}
	afx_msg void OnBnClickedOk();
	CEdit m_project_name;
};
