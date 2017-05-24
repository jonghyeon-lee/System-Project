#pragma once


// CForDialog 대화 상자입니다.

class CForDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CForDialog)

public:
	CForDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CForDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
