
// MFCommAssistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCommAssist.h"
#include "MFCommAssistDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCommAssistDlg 对话框



CMFCommAssistDlg::CMFCommAssistDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCOMMASSIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCommAssistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CMFCommAssistDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CMFCommAssistDlg::OnTcnSelchangeTab)
	ON_BN_CLICKED(IDC_COM1, &CMFCommAssistDlg::OnBnClickedCOM1)
	ON_BN_CLICKED(IDC_COM2, &CMFCommAssistDlg::OnBnClickedCOM2)
	ON_BN_CLICKED(IDC_COM3, &CMFCommAssistDlg::OnBnClickedCOM3)
	ON_BN_CLICKED(IDC_COM4, &CMFCommAssistDlg::OnBnClickedCOM4)
END_MESSAGE_MAP()


// CMFCommAssistDlg 消息处理程序

BOOL CMFCommAssistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.InsertItem(0, TEXT("点对点"));
	m_tab.InsertItem(1, TEXT("三点"));

	m_dlgp2p.Create(IDD_P2P, GetDlgItem(IDC_TAB));
	m_dlg3p.Create(IDD_3P, GetDlgItem(IDC_TAB));
	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 1;
	rs.bottom -= 150;
	rs.left += 1;
	rs.right -= 2;
	//设置子框尺寸并移动到指定位置
	m_dlgp2p.MoveWindow(&rs);
	m_dlg3p.MoveWindow(&rs);

	//分别设置隐藏和显示
	m_dlgp2p.ShowWindow(false);
	m_dlg3p.ShowWindow(true);

	//设置默认选项卡
	m_tab.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCommAssistDlg::OnPaint()
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
HCURSOR CMFCommAssistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCommAssistDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int iCurSel = m_tab.GetCurSel();
	switch (iCurSel)
	{
	case 0:
		m_dlg3p.ShowWindow(true);
		m_dlgp2p.ShowWindow(false);
		break;
	case 1:
		m_dlg3p.ShowWindow(false);
		m_dlgp2p.ShowWindow(true);
	default:
		break;
	}
	*pResult = 0;
}


void CMFCommAssistDlg::OnBnClickedCOM1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!mSerialPort.InitPort(1))
		MessageBox(TEXT("端口初始失败，请选择其他端口"), TEXT("端口错误"), MB_ICONERROR);
	
}


void CMFCommAssistDlg::OnBnClickedCOM2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!mSerialPort.InitPort(2))
		MessageBox(TEXT("端口初始失败，请选择其他端口"), TEXT("端口错误"), MB_ICONERROR);

}


void CMFCommAssistDlg::OnBnClickedCOM3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!mSerialPort.InitPort(3))
		MessageBox(TEXT("端口初始失败，请选择其他端口"), TEXT("端口错误"), MB_ICONERROR);
}


void CMFCommAssistDlg::OnBnClickedCOM4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!mSerialPort.InitPort(4))
		MessageBox(TEXT("端口初始失败，请选择其他端口"), TEXT("端口错误"), MB_ICONERROR);
	else {
		CWnd * m_coms[4] = { GetDlgItem(IDC_COM1),GetDlgItem(IDC_COM2),GetDlgItem(IDC_COM3),GetDlgItem(IDC_COM4) };
		for each (auto com in m_coms)
		{
			com->EnableWindow(false);
		}
		MessageBox(TEXT("端口设置成功，如需改变端口请重新运行程序"), TEXT("成功"), 0);

	}
}



