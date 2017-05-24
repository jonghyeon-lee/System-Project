#pragma once


// COutputDialog 대화 상자입니다.

class COutputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(COutputDialog)

public:
	COutputDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COutputDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_OUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
