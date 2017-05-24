// ChartView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "����UI(��ȭ���ڱ��).h"
#include "ChartView.h"
#include "afxdialogex.h"

#include "����UI(��ȭ���ڱ��)Dlg.h"

#include "DecDialog.h"
#include "AssignDialog.h"
#include "ForDialog.h"
#include "InputDialog.h"
#include "OutputDialog.h"
#include "SwitchDialog.h"
#include "WhileDialog.h"
#include "IfDialog.h"
#include "BufferDC.h"

#include <iostream>
#include <fstream>
using namespace std;


#define ADDRESS "C:\\Users\\KimHyeJi\\Documents\\�������P\\"

#define PIC_WIDTH 368
#define PIC_HEIGHTH 40

// ChartView ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(ChartView, CDialog)

ChartView::ChartView(CWnd* pParent /*=NULL*/)
	: CDialog(ChartView::IDD, pParent)
	, m_chart(0)
{
	nsdata = new NSData[100];
	count = 0;
	array_count = 0;
}

ChartView::~ChartView()
{
}

void ChartView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHART_CONVERT_BUTTON, m_convert_botton);
	DDX_Control(pDX, IDC_FIRST_VIEW, m_pic);
	DDX_Control(pDX, IDC_START, m_start_button);
	//  DDX_Control(pDX, IDC_DEC, m_dec);
	DDX_Control(pDX, IDC_ASSIGN, m_assign_button);
	DDX_Control(pDX, IDC_DEC, m_dec_button);
	DDX_Control(pDX, IDC_FOR, m_for_button);
	DDX_Control(pDX, IDC_WHILE, m_while_button);
	DDX_Control(pDX, IDC_IF, m_if_button);
	DDX_Control(pDX, IDC_SWITCH, m_switch_button);
	DDX_Control(pDX, IDC_INPUT, m_input_button);
	DDX_Control(pDX, IDC_OUTPUT, m_output_button);
	DDX_Control(pDX, IDC_END, m_end_button);
}


BEGIN_MESSAGE_MAP(ChartView, CDialog)
	ON_BN_CLICKED(IDC_CHART_CONVERT_BUTTON, &ChartView::OnBnClickedChartConvertButton)
	ON_BN_CLICKED(IDC_DEC, &ChartView::OnBnClickedDec)
	ON_BN_CLICKED(IDC_ASSIGN, &ChartView::OnBnClickedAssign)
	ON_BN_CLICKED(IDC_FOR, &ChartView::OnBnClickedFor)
	ON_BN_CLICKED(IDC_WHILE, &ChartView::OnBnClickedWhile)
	ON_BN_CLICKED(IDC_IF, &ChartView::OnBnClickedIf)
	ON_BN_CLICKED(IDC_SWITCH, &ChartView::OnBnClickedSwitch)
	ON_BN_CLICKED(IDC_INPUT, &ChartView::OnBnClickedInput)
	ON_BN_CLICKED(IDC_OUTPUT, &ChartView::OnBnClickedOutput)
//	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_START, &ChartView::OnBnClickedStart)
	ON_BN_CLICKED(IDC_END, &ChartView::OnBnClickedEnd)
//	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// ChartView �޽��� ó�����Դϴ�.


void ChartView::OnBnClickedChartConvertButton()
{
	
	C����UI��ȭ���ڱ��Dlg * pDlg = (C����UI��ȭ���ڱ��Dlg *)AfxGetMainWnd();
	CString PName = pDlg->ProjectName;
	
	ofstream of;
	of.open(ADDRESS + PName + "\\"+PName+ ".dat");

	for(int i = 0; i < array_count; i++)
	{
		CString type = nsdata[i].GetDataType();
		CString next_type = nsdata[i+1].GetDataType();
		CString v_type = nsdata[i].GetDecValtype();
		CString v_name = nsdata[i].GetDecValName();
		CString v_default = nsdata[i].GetDecValDefault();
	
//		AfxMessageBox(type + " " + next_type + " " + v_type + " " + v_name + " " + v_default);
		
		 of << type << " "
			<< next_type << " "
			<< v_type << " "
			<< v_name << " " 
			<< v_default << endl;
			
	}
		of.close();

}


void ChartView::OnBnClickedDec()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CDecDialog dec;
	dec.DoModal();

	bool ok = dec.ok_check;

	if(ok == false)
	{
		count++;
		CDC* pic = m_pic.GetWindowDC();
		pic->Rectangle(0, PIC_HEIGHTH*(count-1), PIC_WIDTH, PIC_HEIGHTH*count);
		pic->TextOutA(10, PIC_HEIGHTH*(count-1)+10, dec.v_type + " " + dec.v_name + " = " + dec.v_default);
		nsdata[array_count].SetDecValtype(dec.v_type);
		nsdata[array_count].SetDecValName(dec.v_name);
		nsdata[array_count].SetDecValDefault(dec.v_default);
		nsdata[array_count].SetDataType("D");

		array_count++;
		m_pic.ReleaseDC(pic);
	//	Invalidate();

	}
}


void ChartView::OnBnClickedAssign()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CAssignDialog assign;
	assign.DoModal();

//	bool ok = assign.ok_check;

/*	if(ok == false)
	{
		CDC* pic = m_pic.GetWindowDC();
		pic->Rectangle(0, PIC_HEIGHTH, PIC_WIDTH, PIC_HEIGHTH*2);
		//pic->TextOutA(10, PIC_HEIGHTH+10, assign.v_type + " " + dec.v_name + " = " + dec.v_default);
		
		m_pic.ReleaseDC(pic);
	}
	*/
}


void ChartView::OnBnClickedFor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CForDialog f;
	f.DoModal();
}


void ChartView::OnBnClickedWhile()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CWhileDialog w;
	w.DoModal();
}


void ChartView::OnBnClickedIf()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CIfDialog i;
	i.DoModal();
}


void ChartView::OnBnClickedSwitch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CSwitchDialog s;
	s.DoModal();
}


void ChartView::OnBnClickedInput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CInputDialog input;
	input.DoModal();
}


void ChartView::OnBnClickedOutput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	COutputDialog output;
	output.DoModal();
	/*
	bool ok = output.ok_check;

	if(ok == false)
	{
		count++;
		CDC* pic = m_pic.GetWindowDC();
		pic->Rectangle(0, PIC_HEIGHTH*(count-1), PIC_WIDTH, PIC_HEIGHTH*count);
		pic->TextOutA(10, PIC_HEIGHTH*(count-1)+10, dec.v_type + " " + dec.v_name + " = " + dec.v_default);
		nsdata[array_count].SetDecValtype(dec.v_type);
		nsdata[array_count].SetDecValName(dec.v_name);
		nsdata[array_count].SetDecValDefault(dec.v_default);
		nsdata[array_count].SetDataType("D");

		array_count++;
		m_pic.ReleaseDC(pic);*/
	//	Invalidate();

	//}
}


//void ChartView::OnPaint()
//{
//	
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
//
//	CPaintDC dc(this); // device context for painting
//	CDC* pDC = GetWindowDC();
//	
//	CRect rect;
//
//	SetRect(&rect,p_point.x+20,p_point.y+20,p_point.x+200,p_point.y+40);
//	pDC->Rectangle(&rect);
//	
//}

void ChartView::DrawImage(CDC* pDC)
{
	RECT rect;

	SetRect(&rect,p_point.x+20,p_point.y+20,p_point.x+200,p_point.y+40);
	pDC->Rectangle(&rect);
}


void ChartView::OnBnClickedStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	CRect rc;
//	GetDlgItem(IDC_FIRST_VIEW)->GetWindowRect(&rc);
//	ScreenToClient(&rc);

	
	m_dec_button.EnableWindow(1);
	m_assign_button.EnableWindow(1);
	m_for_button.EnableWindow(1);
	m_while_button.EnableWindow(1);
	m_if_button.EnableWindow(1);
	m_input_button.EnableWindow(1);
	m_output_button.EnableWindow(1);
	m_switch_button.EnableWindow(1);
	m_end_button.EnableWindow(1);

	m_start_button.EnableWindow(0);

	count++;
	CDC* pic = m_pic.GetWindowDC();
	pic->Rectangle(0, PIC_HEIGHTH*(count-1), PIC_WIDTH, PIC_HEIGHTH*count);
	pic->TextOutA(10, PIC_HEIGHTH*(count-1)+10, "START");

	m_pic.ReleaseDC(pic);

	
//	m_pic.adjustBorder();
//	m_pic.Invalidate();
//	CRect rClip(0, 0, PIC_WIDTH, PIC_HEIGHTH);
//	m_pic.GetClientRect(rClip);
//	m_pic.ScrollWindow(10, 10, 0, &rClip);
}


void ChartView::OnBnClickedEnd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	nsdata[array_count].SetDataType("null");
	count++;
	CDC* pic = m_pic.GetWindowDC();
	pic->Rectangle(0, PIC_HEIGHTH*(count-1), PIC_WIDTH, PIC_HEIGHTH*count);
	pic->TextOutA(10, PIC_HEIGHTH*(count-1)+10, "END");

	m_pic.ReleaseDC(pic);

	
	m_dec_button.EnableWindow(0);
	m_assign_button.EnableWindow(0);
	m_for_button.EnableWindow(0);
	m_while_button.EnableWindow(0);
	m_if_button.EnableWindow(0);
	m_input_button.EnableWindow(0);
	m_output_button.EnableWindow(0);
	m_switch_button.EnableWindow(0);
	m_end_button.EnableWindow(0);

	m_start_button.EnableWindow(0);

}


//void ChartView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	p_msg.Format(_T("X=%d , Y=%d"),point.x,point.y);
//	p_point = point;
//	Invalidate();
//	CDialog::OnMouseMove(nFlags, point);
//}

/*
BOOL ChartView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return TRUE;
//	return CDialog::OnEraseBkgnd(pDC);
}
*/

//void ChartView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
//
//	
//	CDC* pDC = GetDC();
//	RECT rect;
//
//	SetRect(&rect,p_point.x+20,p_point.y+20,p_point.x+200,p_point.y+40);
//	pDC->Rectangle(&rect);
//}
