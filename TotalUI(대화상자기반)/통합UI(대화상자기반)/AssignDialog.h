#pragma once


// CAssignDialog ��ȭ �����Դϴ�.

class CAssignDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAssignDialog)

public:
	CAssignDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAssignDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ASSIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
