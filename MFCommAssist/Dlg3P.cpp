// Dlg3P.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCommAssist.h"
#include "Dlg3P.h"
#include "afxdialogex.h"


// CDlg3P 对话框

IMPLEMENT_DYNAMIC(CDlg3P, CDialog)

CDlg3P::CDlg3P(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_3P, pParent)
{

}

CDlg3P::~CDlg3P()
{
}

void CDlg3P::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_rec);
	DDX_Control(pDX, IDC_EDIT1, m_snd);
}


BEGIN_MESSAGE_MAP(CDlg3P, CDialog)
	ON_BN_CLICKED(IDC_CLR, &CDlg3P::OnBnClickedClr)
	ON_BN_CLICKED(IDC_SEND, &CDlg3P::OnBnClickedSend)
END_MESSAGE_MAP()


// CDlg3P 消息处理程序


void CDlg3P::OnBnClickedClr()
{
	// TODO: 在此添加控件通知处理程序代码
	m_rec.SetWindowTextW(TEXT(""));
}


void CDlg3P::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
	m_snd.GetWindowTextW(this->csData);
	CString csOldData;
	m_rec.GetWindowTextW(csOldData);
	if
	m_rec.SetWindowTextW(csOldData + "\r\n" + this->csData);
}
