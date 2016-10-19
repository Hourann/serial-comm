#pragma once


// CDlgP2P 对话框

class CDlgP2P : public CDialog
{
	DECLARE_DYNAMIC(CDlgP2P)

public:
	CDlgP2P(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgP2P();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P2P };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
