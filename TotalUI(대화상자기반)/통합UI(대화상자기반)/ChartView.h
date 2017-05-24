#pragma once
#include "CodeView.h"
#include "afxwin.h"

#include "NSData.h"

// ChartView 대화 상자입니다.

class ChartView : public CDialog
{
	DECLARE_DYNAMIC(ChartView)

public:
	ChartView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ChartView();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHARTVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	NSData* nsdata;

	int count;
	int array_count;

	CString test;
	 void SetTest(CString t){test = t;}
	 CString GetTest(){return test;}
	CodeView code;
	int m_chart;
	afx_msg void OnBnClickedChartConvertButton();
	CButton m_convert_botton;
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedAssign();
	afx_msg void OnBnClickedFor();
	afx_msg void OnBnClickedWhile();
	afx_msg void OnBnClickedIf();
	afx_msg void OnBnClickedSwitch();
	afx_msg void OnBnClickedInput();
	afx_msg void OnBnClickedOutput();
//	afx_msg void OnPaint();
	afx_msg void OnBnClickedStart();
	CStatic m_pic;
	CButton m_start_button;
//	CButton m_dec;
	CButton m_assign_button;
	CButton m_dec_button;
	CButton m_for_button;
	CButton m_while_button;
	CButton m_if_button;
	CButton m_switch_button;
	CButton m_input_button;
	CButton m_output_button;
	CButton m_end_button;

	
	CString p_msg;
	CPoint p_point;
	afx_msg void DrawImage(CDC* pDC);
	afx_msg void OnBnClickedEnd();
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnPaint();
};
