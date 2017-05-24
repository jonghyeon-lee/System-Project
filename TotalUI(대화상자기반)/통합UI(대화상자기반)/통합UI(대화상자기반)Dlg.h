
// ����UI(��ȭ���ڱ��)Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "ChartView.h"
#include "CodeView.h"
#include "CreateProject.h"
#include "afxwin.h"

// C����UI��ȭ���ڱ��Dlg ��ȭ ����
class C����UI��ȭ���ڱ��Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	
	C����UI��ȭ���ڱ��Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	int checkNum;
	
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	bool project_check;
	CString ProjectName ;
	ChartView m_chart;
	CodeView m_code;
	CWnd* m_pwndShow;

	CTabCtrl m_tabCtrl;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void SetTabIndex(int i){checkNum = i;}
	afx_msg int GetTabIndex(){return checkNum;}
	afx_msg void OnCreateProject();
	afx_msg void OnBnClickedButton1();
	CButton m_button;
};
