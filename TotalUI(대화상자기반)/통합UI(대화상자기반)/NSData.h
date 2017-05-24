#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class NSData
{
private:
	CString type;

	CString dec_value_type;
	CString dec_value_name;
	CString dec_value_default;
public:
	NSData(){}
	~NSData(){}

	void SetDataType(CString s){type = s;}
	void SetDecValName(CString s){dec_value_name = s;}
	void SetDecValtype(CString s){dec_value_type = s;}
	void SetDecValDefault(CString s){dec_value_default = s;}

	CString GetDataType(){return type;}
	CString GetDecValName(){return dec_value_name;}
	CString GetDecValtype(){return dec_value_type;}
	CString GetDecValDefault(){return dec_value_default;}

};