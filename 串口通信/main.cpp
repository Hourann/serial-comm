#include "SerialPort.h"
#include <iostream>
int main() {
	using namespace std;
	CSerialPort mySerialPort;
	char received;
	if (!mySerialPort.InitPort(3)) {
		cout << "initPort fail!" << endl;
	}
	else {
		cout << "initPort success!" << endl;
	}
	if (!mySerialPort.OpenListenThread()) {
		cout << "OpenListenThread fail!" << endl;
	}
	else {
		cout << "OpenListenTread success!" << endl;
		while (1) {
			mySerialPort.ReadChar(received);
			cout << received;
		}
	}
	system("pause");
	return 0;
}