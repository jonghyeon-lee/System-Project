#pragma once


// CSwitchDialog ��ȭ �����Դϴ�.

class CSwitchDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSwitchDialog)

public:
	CSwitchDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSwitchDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SWITCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
