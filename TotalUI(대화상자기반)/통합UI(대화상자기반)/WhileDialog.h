#pragma once


// CWhileDialog 대화 상자입니다.

class CWhileDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CWhileDialog)

public:
	CWhileDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CWhileDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WHILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
