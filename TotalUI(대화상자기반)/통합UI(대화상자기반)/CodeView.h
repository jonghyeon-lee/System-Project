#pragma once
#include "afxwin.h"
#include <string>
using namespace std;


// CodeView 대화 상자입니다.

class CodeView : public CDialog
{
	DECLARE_DYNAMIC(CodeView)

public:
	CodeView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CodeView();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CODEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	afx_msg int ConvertChart();
	int checkFile;
	DECLARE_MESSAGE_MAP()
public:
	CString test;

	afx_msg void SetString(CString parm_string);
	CButton m_buildCtrl;
	CEdit m_editCtrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedShowButton();
	afx_msg void OnBnClickedBuildButton();
	afx_msg void OnBnClickedDibuggingButton();
};
