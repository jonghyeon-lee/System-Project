#pragma once
#include "afxwin.h"
#include <string>
using namespace std;


// CodeView ��ȭ �����Դϴ�.

class CodeView : public CDialog
{
	DECLARE_DYNAMIC(CodeView)

public:
	CodeView(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CodeView();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CODEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
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
