#pragma once


// CInputDialog ��ȭ �����Դϴ�.

class CInputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDialog)

public:
	CInputDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInputDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
