
// MFCommAssistDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Dlg3P.h"
#include "DlgP2P.h"
#include "SerialPort.h"

// CMFCommAssistDlg �Ի���
class CMFCommAssistDlg : public CDialogEx
{
// ����
public:
	CMFCommAssistDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCOMMASSIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CDlg3P m_dlg3p;
	CDlgP2P m_dlgp2p;
	CSerialPort  mSerialPort;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCOM1();
	afx_msg void OnBnClickedCOM2();
	afx_msg void OnBnClickedCOM3();
	afx_msg void OnBnClickedCOM4();
};
