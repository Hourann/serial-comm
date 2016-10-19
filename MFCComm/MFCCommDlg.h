
// MFCCommDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CMFCCommDlg 对话框
class CMFCCommDlg : public CDialogEx
{
// 构造
public:
	CMFCCommDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCOMM_DIALOG };
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
	BOOL CMFCCommDlg::PreTranslateMessage(MSG* pMsg)
	{
		if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) return TRUE;
		if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) return TRUE;
		else
			return CDialog::PreTranslateMessage(pMsg);
	}
public:
	CTabCtrl m_tab;
	CDialog m_dlg_p2p, m_dlg_mp;
	afx_msg void OnCbnSetfocusComboCom();
};
