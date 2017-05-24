#pragma once


// CIfDialog 대화 상자입니다.

class CIfDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CIfDialog)

public:
	CIfDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CIfDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
