#pragma once
#include "afxwin.h"


// CDecDialog ��ȭ �����Դϴ�.

class CDecDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDecDialog)

public:
	CDecDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDecDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DEC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
