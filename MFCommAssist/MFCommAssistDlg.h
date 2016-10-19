
// MFCommAssistDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Dlg3P.h"
#include "DlgP2P.h"
#include "SerialPort.h"

// CMFCommAssistDlg 对话框
class CMFCommAssistDlg : public CDialogEx
{
// 构造
public:
	CMFCommAssistDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCOMMASSIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
