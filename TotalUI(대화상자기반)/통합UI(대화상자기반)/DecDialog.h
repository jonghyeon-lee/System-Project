#pragma once
#include "afxwin.h"


// CDecDialog 대화 상자입니다.

class CDecDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDecDialog)

public:
	CDecDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDecDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DEC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_value_name;
	CString v_name;
	CString v_type;
	CString v_default;



	bool ok_check;

//	afx_msg bool GetOkCheck(){return ok_check;}
	afx_msg void OnBnClickedOk();
	CEdit m_value_name;
	CEdit m_value_default;
	CComboBox m_value_type;
	afx_msg void OnCbnSelchangeDecType();
};
