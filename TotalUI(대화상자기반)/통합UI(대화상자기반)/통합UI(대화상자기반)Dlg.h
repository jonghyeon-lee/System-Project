
// 통합UI(대화상자기반)Dlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "ChartView.h"
#include "CodeView.h"
#include "CreateProject.h"
#include "afxwin.h"

// C통합UI대화상자기반Dlg 대화 상자
class C통합UI대화상자기반Dlg : public CDialogEx
{
// 생성입니다.
public:
	
	C통합UI대화상자기반Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_UI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	int checkNum;
	
	// 생성된 메시지 맵 함수
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
