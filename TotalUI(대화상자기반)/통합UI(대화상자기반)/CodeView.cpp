// CodeView.cpp : 구현 파일입니다.

#include "stdafx.h"
#include "통합UI(대화상자기반).h"
#include "통합UI(대화상자기반)Dlg.h"
#include "CodeView.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

#define DECLARATION 'D'
#define ASSIGNMENT	'A'
#define FOR			'F'
#define WHILE		'W'
#define DO_WHILE	'O'
#define IF			'I'
#define ELSE		'E'
#define SWITCH		'S'
#define CASE		'C'
#define INPUT		'N'
#define OUTPUT		'U'

#define ADDRESS "C:\\Users\\KimHyeJi\\Documents\\생각대로P\\"
#define PATH "PATH=C:\\Program Files\\Microsoft Visual Studio 11.0\\VC\\bin;C:\\Program Files\\Microsoft Visual Studio 11.0\\Common7\\IDE"
#define INCLUDE "INCLUDE=C:\\Program Files\\Microsoft Visual Studio 11.0\\VC\\include;"
#define LIB "LIB=C:\\Program Files\\Microsoft Visual Studio 11.0\\VC\\lib;C:\\Program Files\\Microsoft SDKs\\Windows\\v7.1A\\Lib;"

// CodeView 대화 상자입니다.

IMPLEMENT_DYNAMIC(CodeView, CDialog)

	CodeView::CodeView(CWnd* pParent /*=NULL*/)
	: CDialog(CodeView::IDD, pParent)
	, m_editCtrl()
{
	checkFile = 0;
}

CodeView::~CodeView()
{
}

void CodeView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUILD_BUTTON, m_buildCtrl);
	DDX_Control(pDX, IDC_EDIT1, m_editCtrl);
}


BEGIN_MESSAGE_MAP(CodeView, CDialog)
	ON_BN_CLICKED(IDC_SHOW_BUTTON, &CodeView::OnBnClickedShowButton)
	ON_BN_CLICKED(IDC_BUILD_BUTTON, &CodeView::OnBnClickedBuildButton)
	ON_BN_CLICKED(IDC_DIBUGGING_BUTTON, &CodeView::OnBnClickedDibuggingButton)
END_MESSAGE_MAP()


BOOL CodeView::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	C통합UI대화상자기반Dlg * pDlg = (C통합UI대화상자기반Dlg *)AfxGetMainWnd();
	int a = pDlg->GetTabIndex();
	CString str;

	str.Format(_T("%d") , a);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CodeView::OnBnClickedShowButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	C통합UI대화상자기반Dlg * pDlg = (C통합UI대화상자기반Dlg *)AfxGetMainWnd();
	CString PName = pDlg->ProjectName;

	checkFile = ConvertChart();
	OnInitDialog();
	fstream f;
	f.open(ADDRESS + PName + "\\"+PName+ ".cpp");
	CString temp;
	char s[1000];
	while(!f.eof())
	{
		f.getline(s,100);
		temp = temp + s+"\r\n";
	}
	m_editCtrl.SetWindowText((LPCTSTR)temp);
}

int CodeView::ConvertChart()
{
	fstream f;
	ofstream of;

	C통합UI대화상자기반Dlg * pDlg = (C통합UI대화상자기반Dlg *)AfxGetMainWnd();
	CString PName = pDlg->ProjectName;


	f.open(ADDRESS + PName + "\\"+PName+ ".dat");
	of.open(ADDRESS + PName + "\\"+PName+ ".cpp");
	if(of == NULL)
		checkFile = 1;
	else
	{
		string str;
		char s[1000];
		string one, type, next_type, info1, info2, info3;
		int type_size = 0;
		int next_type_size = 0;

		int count = 0;		//반복,조건문 count
		int t_count = 0;	//type_count

		char* temp;
		of << "#include <iostream>" << endl;
		of << "#include <string>" << endl;
		of << "using namespace std;" << endl;
		of << endl;
		of << "int main(){" << endl;

		while(!f.eof())
		{
			of << "\t" ;
			f.getline(s,100);

			type = strtok_s (s, " ", &temp);
			next_type = strtok_s(NULL, " ",&temp);
			type_size = type.size();
			next_type_size = next_type.size();

			for(int i = 0; i < type_size-1; i++)
			{
				of << "\t" ;
			}
			//선언문
			if(type.at(t_count) == DECLARATION)
			{
				info1 = strtok_s(NULL, " ",&temp);
				info2 = strtok_s(NULL, " ",&temp);
				info3 = strtok_s(NULL, " ",&temp);
				of << info1 << " " 
					<< info2 << " = "
					<< info3 << ";" << endl;
			}
			//while문
			else if(type.at(t_count) == WHILE)
			{
				info1 = strtok_s(NULL, " ",&temp);
				of << "while( " << info1 << " ){" << endl;
				count++;
			}
			//대입문
			else if(type.at(t_count) == ASSIGNMENT)
			{
				info1 = strtok_s(NULL, " ",&temp);
				info2 = strtok_s(NULL, " ",&temp);
				of << info1 << " = "
					<< info2 << ";" << endl;
			}
			//if문
			else if(type.at(t_count) == IF)
			{
				info1 = strtok_s(NULL, " ",&temp);
				of << "if( " << info1 << " ){" << endl;
			}
			//else문
			else if(type.at(t_count) == ELSE)
			{
				of << "}else{" << endl;
				count++;
			}
			//출력문
			else if(type.at(t_count) == OUTPUT)
			{
				info1 = strtok_s(NULL, " ",&temp);
				info2 = strtok_s(NULL, " ",&temp);
				if(info1 == "string")
					of << "cout << \" " << info2 << " \" << endl;" << endl;
				else
					of << "cout << " << info2 << " << endl;" << endl;

			}
			//입력문
			else if(type.at(t_count) == INPUT)
			{
				info1 = strtok_s(NULL, " ",&temp);
				of << "cin >> " << info1 << " ;" << endl;
			}
			//분기문_switch
			else if(type.at(t_count) == SWITCH)
			{
				info1 = strtok_s(NULL, " ",&temp);
				of << "switch( " << info1 << " ){" << endl;
			}
			//분기문_case||default
			else if(type.at(t_count) == CASE)
			{
				info1 = strtok_s(NULL, " ",&temp);
				if(info1 == "default")
					of << "default:" << endl;
				else
					of << "case " << info1 << ":" << endl;
			}
			// '}' 언제 닫는가
			if(type.at(0) != DECLARATION && type.at(0) != OUTPUT )
			{
				if(type.at(0) == WHILE || type.at(0) == ELSE )
				{
					if(next_type == "null")
					{
						for(int i = 0; i < count-1; i++)
						{
							of << "\t" ;
						}
						of << "\t}" << endl;
						count--;
					}
					if(type_size > next_type_size)
					{
						if(t_count > 0 && type.at(t_count-1) == IF)
						{
						}
						else
						{
							int c = type_size - next_type_size ;
							for(int i = 0; i < c; i++)
							{
								for(int i = 0; i < count-1; i++)
								{
									of << "\t" ;
								}
								of << "\t}" << endl;
								count--;
							}
						}
					}
				}
			}
			if(next_type != "null")
			{
				if(type_size - next_type_size == 1 || next_type_size - type_size == 1)
				{
					if(type_size < next_type_size && type.at(t_count) == next_type.at(t_count) )
						t_count++;

					if(type_size > next_type_size)
						t_count--;
				}
				else
				{
					t_count = next_type_size - 1;
				}
			}
			else
			{
				if(type.at(0) == WHILE )
				{
					of << "\t}" << endl;
					break;
				}
				else if( type.length() > 2 && type.at(0) == ELSE)
				{
					of << "\t}" << endl;
				}
				break;
			}
		}
		of << "}" << endl;
		f.close();
	}
		of.close();

	return checkFile;
}

void CodeView::OnBnClickedBuildButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	C통합UI대화상자기반Dlg * pDlg = (C통합UI대화상자기반Dlg *)AfxGetMainWnd();
	CString PName = pDlg->ProjectName;

	_putenv(PATH);
	_putenv(INCLUDE);
	_putenv(LIB);
	CString temp = "cl C:\\Users\\KimHyeJi\\Documents\\생각대로P\\" + PName + "\\"+PName+ ".cpp";
	system(temp);
	temp = ADDRESS + PName + "\\"+PName+ ".exe";
	system(temp);
	system("pause");
}

void CodeView::OnBnClickedDibuggingButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
