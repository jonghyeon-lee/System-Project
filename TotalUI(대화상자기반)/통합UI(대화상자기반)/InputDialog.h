#pragma once


// CInputDialog 대화 상자입니다.

class CInputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDialog)

public:
	CInputDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInputDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
