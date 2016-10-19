
// MFCCommDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCComm.h"
#include "MFCCommDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCommDlg �Ի���



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


// CMFCCommDlg ��Ϣ�������

BOOL CMFCCommDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0, _T("��Ե�"));
	m_tab.InsertItem(1, _T("���"));

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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCCommDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCCommDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCommDlg::OnCbnSetfocusComboCom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
