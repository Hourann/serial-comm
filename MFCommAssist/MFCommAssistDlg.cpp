
// MFCommAssistDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCommAssist.h"
#include "MFCommAssistDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCommAssistDlg �Ի���



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


// CMFCommAssistDlg ��Ϣ�������

BOOL CMFCommAssistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tab.InsertItem(0, TEXT("��Ե�"));
	m_tab.InsertItem(1, TEXT("����"));

	m_dlgp2p.Create(IDD_P2P, GetDlgItem(IDC_TAB));
	m_dlg3p.Create(IDD_3P, GetDlgItem(IDC_TAB));
	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 1;
	rs.bottom -= 150;
	rs.left += 1;
	rs.right -= 2;
	//�����ӿ�ߴ粢�ƶ���ָ��λ��
	m_dlgp2p.MoveWindow(&rs);
	m_dlg3p.MoveWindow(&rs);

	//�ֱ��������غ���ʾ
	m_dlgp2p.ShowWindow(false);
	m_dlg3p.ShowWindow(true);

	//����Ĭ��ѡ�
	m_tab.SetCurSel(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCommAssistDlg::OnPaint()
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
HCURSOR CMFCommAssistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCommAssistDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!mSerialPort.InitPort(1))
		MessageBox(TEXT("�˿ڳ�ʼʧ�ܣ���ѡ�������˿�"), TEXT("�˿ڴ���"), MB_ICONERROR);
	
}


void CMFCommAssistDlg::OnBnClickedCOM2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!mSerialPort.InitPort(2))
		MessageBox(TEXT("�˿ڳ�ʼʧ�ܣ���ѡ�������˿�"), TEXT("�˿ڴ���"), MB_ICONERROR);

}


void CMFCommAssistDlg::OnBnClickedCOM3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!mSerialPort.InitPort(3))
		MessageBox(TEXT("�˿ڳ�ʼʧ�ܣ���ѡ�������˿�"), TEXT("�˿ڴ���"), MB_ICONERROR);
}


void CMFCommAssistDlg::OnBnClickedCOM4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!mSerialPort.InitPort(4))
		MessageBox(TEXT("�˿ڳ�ʼʧ�ܣ���ѡ�������˿�"), TEXT("�˿ڴ���"), MB_ICONERROR);
	else {
		CWnd * m_coms[4] = { GetDlgItem(IDC_COM1),GetDlgItem(IDC_COM2),GetDlgItem(IDC_COM3),GetDlgItem(IDC_COM4) };
		for each (auto com in m_coms)
		{
			com->EnableWindow(false);
		}
		MessageBox(TEXT("�˿����óɹ�������ı�˿����������г���"), TEXT("�ɹ�"), 0);

	}
}



