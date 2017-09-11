#include<iostream>
#include<Windows.h>
using namespace std;
int main(){
	int newValue = 300;
	int readTest = 0;

	HWND hwnd = FindWindowA(NULL, "Window Name");//Set window name
	if (hwnd == NULL){
		cout << "Cannot find window." << endl;
		Sleep(3000);
		exit(-1);
	}
	else{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (procID == NULL){
			cout << "Cannot obtain process." << endl;
			Sleep(3000);
			exit(-1);
		}
		else{
			/*cout << "Process: " << procID << endl;*/
			for (;;){
				if (GetAsyncKeyState(VK_F1)){
					WriteProcessMemory(handle, (LPVOID)0x0E88AEF0, &newValue, sizeof(newValue), 0);//Set memory address
					newValue++;
					cout << newValue << endl;
				}
				Sleep(1);
			}
			/*ReadProcessMemory(handle, (PBYTE*)0x0E88AEF0, &readTest, sizeof(readTest), 0);
			cout << readTest << endl;
			Sleep(10000);*/
		}}
	return 0;
}
