#pragma once
#include "afxwin.h"


// CDlg3P �Ի���

class CDlg3P : public CDialog
{
	DECLARE_DYNAMIC(CDlg3P)

public:
	CDlg3P(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg3P();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_3P };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_rec;
	CEdit m_snd;
	bool crc_on;
	afx_msg void OnBnClickedClr();
	afx_msg void OnBnClickedSend();
	CString csData;
};
