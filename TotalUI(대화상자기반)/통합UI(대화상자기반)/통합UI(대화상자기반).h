
// ����UI(��ȭ���ڱ��).h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// C����UI��ȭ���ڱ��App:
// �� Ŭ������ ������ ���ؼ��� ����UI(��ȭ���ڱ��).cpp�� �����Ͻʽÿ�.
//

class C����UI��ȭ���ڱ��App : public CWinApp
{
public:
	C����UI��ȭ���ڱ��App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern C����UI��ȭ���ڱ��App theApp;