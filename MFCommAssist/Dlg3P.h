#pragma once
#include "afxwin.h"


// CDlg3P 对话框

class CDlg3P : public CDialog
{
	DECLARE_DYNAMIC(CDlg3P)

public:
	CDlg3P(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg3P();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_3P };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_rec;
	CEdit m_snd;
	bool crc_on;
	afx_msg void OnBnClickedClr();
	afx_msg void OnBnClickedSend();
	CString csData;
};
