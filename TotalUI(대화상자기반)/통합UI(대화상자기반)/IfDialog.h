#pragma once


// CIfDialog ��ȭ �����Դϴ�.

class CIfDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CIfDialog)

public:
	CIfDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CIfDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
