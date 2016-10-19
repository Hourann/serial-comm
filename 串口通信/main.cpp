#include "SerialPort.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	CSerialPort mySerialPort;

	char lpComm[5];
	cout << "请设置端口号（数字）：";
	string sData;
	int iComm;
	cin >> iComm;
	sprintf(lpComm, "com%d", iComm);	//将端口号赋给szComm
	cout << "请设置模式【读(r)|写(w)】：";
	char cMode;
	cin >> cMode;
	if (!mySerialPort.InitPort(iComm)) {
		cout << "端口打开失败" << endl;
		system("pause");
		return 1;
	}
	if (cMode == 'r') {			//读模式
		mySerialPort.OpenListenThread();
		cout << "正在侦听端口，如需结束，请按q退出";
		system("pause");
	}
	else if (cMode == 'w') {	//写模式
		while (1) {
			cin >> sData;
			mySerialPort.WriteData((unsigned char *)sData.c_str(), sData.length());
		}

	}
	return 0;
}