#include<iostream>
#include<Windows.h>

using namespace std; // Standered Library 
int main()
{
	DWORD ProcId;
	int CMD; // The CMD Input
	DWORD ammoAddr = 0x0113A758; //A Ammo Addr
 	DWORD ammoValue = 999; // Desired AmmoValue
	SetConsoleTitleA("Lumio [Assault Cube] - KingEzz"); // ConsoleWindowName
	HWND AC = FindWindowA(NULL, "AssaultCube"); // HWND = Handle to a window 
	if (AC == FALSE) { // If Check
		cout << "Unable To Obtain Process [1].." << endl;
		getchar(); // getchar
	}
	else
	{
		cout << "Found Process.. Obtaining ProcessID" << endl; // 
		// ProcId = GetProcessId(AC);
		DWORD MSN = GetWindowThreadProcessId(AC, &ProcId);
		cout << MSN << endl;
	}
	cout << "Opening Process" << endl;
	HANDLE ACprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcId); // Needs permsiions in this case ALL access
	if (ACprocess == FALSE)
	{
		cout << "Unable To Obtain Process [2].. " << endl;
		getchar();
	}
	cout << "Please Enter A Command!" << endl;
	cout << "1 - Ammo" << endl;
	cin >> CMD; // takes in input
	if (CMD == 1)
	{
		WriteProcessMemory(ACprocess, (LPVOID)ammoAddr, &ammoValue, sizeof(int), 0); // Changes Value! 
	}
	Sleep(1000);
}