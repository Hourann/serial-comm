#pragma once


// CDlgP2P �Ի���

class CDlgP2P : public CDialog
{
	DECLARE_DYNAMIC(CDlgP2P)

public:
	CDlgP2P(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgP2P();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P2P };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
