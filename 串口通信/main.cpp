#include "SerialPort.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	CSerialPort mySerialPort;

	char lpComm[5];
	cout << "�����ö˿ںţ����֣���";
	string sData;
	int iComm;
	cin >> iComm;
	sprintf(lpComm, "com%d", iComm);	//���˿ںŸ���szComm
	cout << "������ģʽ����(r)|д(w)����";
	char cMode;
	cin >> cMode;
	if (!mySerialPort.InitPort(iComm)) {
		cout << "�˿ڴ�ʧ��" << endl;
		system("pause");
		return 1;
	}
	if (cMode == 'r') {			//��ģʽ
		mySerialPort.OpenListenThread();
		cout << "���������˿ڣ�����������밴q�˳�";
		system("pause");
	}
	else if (cMode == 'w') {	//дģʽ
		while (1) {
			cin >> sData;
			mySerialPort.WriteData((unsigned char *)sData.c_str(), sData.length());
		}

	}
	return 0;
}