#pragma once


// CForDialog ��ȭ �����Դϴ�.

class CForDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CForDialog)

public:
	CForDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CForDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
