
// MFCommAssist.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCommAssistApp: 
// �йش����ʵ�֣������ MFCommAssist.cpp
//

class CMFCommAssistApp : public CWinApp
{
public:
	CMFCommAssistApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCommAssistApp theApp;