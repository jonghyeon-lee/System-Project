#pragma once


// COutputDialog ��ȭ �����Դϴ�.

class COutputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(COutputDialog)

public:
	COutputDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COutputDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OUTPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
