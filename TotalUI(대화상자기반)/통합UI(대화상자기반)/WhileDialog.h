#pragma once


// CWhileDialog ��ȭ �����Դϴ�.

class CWhileDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CWhileDialog)

public:
	CWhileDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CWhileDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WHILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
