
// MFCCommDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCComm.h"
#include "MFCCommDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCommDlg 对话框



CMFCCommDlg::CMFCCommDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCOMM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCommDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCCommDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SETFOCUS(IDC_COMBO_COM, &CMFCCommDlg::OnCbnSetfocusComboCom)
END_MESSAGE_MAP()


// CMFCCommDlg 消息处理程序

BOOL CMFCCommDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.InsertItem(0, _T("点对点"));
	m_tab.InsertItem(1, _T("多点"));

	m_dlg_mp.Create(IDD_MULP, GetDlgItem(IDD_MFCCOMM_DIALOG));
	m_dlg_p2p.Create(IDD_P2P, GetDlgItem(IDD_MFCCOMM_DIALOG));

	CRect rs;
	rs.top -= 60;
	rs.bottom -= 300;
	m_tab.GetClientRect(&rs);
	m_dlg_p2p.MoveWindow(&rs);
	m_dlg_mp.MoveWindow(&rs);

	m_dlg_p2p.ShowWindow(true);
	m_dlg_mp.ShowWindow(false);

	m_tab.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCommDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCCommDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCommDlg::OnCbnSetfocusComboCom()
{
	// TODO: 在此添加控件通知处理程序代码
	BYTE i = 0;
	CString str;
	str.Empty();
	((CComboBox *)GetDlgItem(IDC_COMBO_COM))->ResetContent();
	for (i = 0; i < 255; i++) {
		if (mSerialPort.InitPort(i)) {
			mSerialPort.~CSerialPort();
			str.AppendFormat(_T("COM%d"), i);
			((CComboBox *)GetDlgItem(IDC_COMBO_COM))->AddString(str);
			str.Empty();
		}
	}
}
