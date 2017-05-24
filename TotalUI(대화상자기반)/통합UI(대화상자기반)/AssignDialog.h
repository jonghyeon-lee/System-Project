#pragma once


// CAssignDialog 대화 상자입니다.

class CAssignDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAssignDialog)

public:
	CAssignDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAssignDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ASSIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
