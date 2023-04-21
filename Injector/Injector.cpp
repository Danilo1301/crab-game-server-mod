/*
Written by: SaEeD
Modified by: Danilo1301
Description: Automatically injecting Crab Game DLL to Target process

who needs cheat engine
why wasting ~10 clicks just to manually open GrabGame + CheatEngine and test? (multiplied by ~100 tests in a day)
why not just OPEN THE GAME, smh

*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <Windows.h>
#include <tlhelp32.h>
#include <Shlwapi.h>
#include <comdef.h> 
#include <filesystem>

//Library needed by Linker to check file existance
#pragma comment(lib, "Shlwapi.lib")

using namespace std;

int getProcID(const string& p_name);
bool InjectDLL(const int& pid, const string& DLL_Path);

bool injected = false;

int main()
{
	filesystem::path cwd = std::filesystem::current_path() / "CrabGameServerMod.dll";

	while (true)
	{
		if (std::filesystem::exists(cwd))
		{
			int pi = getProcID("Crab Game.exe");

			if (pi != 0)
			{
				if (!injected)
				{
					cout << "Injecting dll" << endl;
					injected = true;

					Sleep(6000);

					InjectDLL(getProcID("Crab Game.exe"), cwd.string());
				}
			} else {
				
				if (injected)
				{
					cout << "Closed. Resetting..." << std::endl;
					injected = false;
				}
				else {
					cout << "Crab Game is not running..." << std::endl;
				}
			}
		} else {
			cout << "Dll not found " << endl;
		}
		Sleep(1000);
	}

	return EXIT_SUCCESS;
}

//-----------------------------------------------------------
// Get Process ID by its name
//-----------------------------------------------------------
int getProcID(const string& p_name)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 structprocsnapshot = { 0 };

	structprocsnapshot.dwSize = sizeof(PROCESSENTRY32);

	if (snapshot == INVALID_HANDLE_VALUE)return 0;
	if (Process32First(snapshot, &structprocsnapshot) == FALSE)return 0;

	while (Process32Next(snapshot, &structprocsnapshot))
	{
		_bstr_t b(structprocsnapshot.szExeFile);

		if (!strcmp(b, p_name.c_str()))
		{
			CloseHandle(snapshot);
			//cout << "[+]Process name is: " << p_name << "\n[+]Process ID: " << structprocsnapshot.th32ProcessID << endl;
			return structprocsnapshot.th32ProcessID;
		}
	}
	CloseHandle(snapshot);
	//cerr << "[!]Unable to find Process ID" << endl;
	return 0;
}

//-----------------------------------------------------------
// Inject DLL to target process
//-----------------------------------------------------------
bool InjectDLL(const int& pid, const string& DLL_Path)
{
	long dll_size = DLL_Path.length() + 1;
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	if (hProc == NULL)
	{
		cerr << "[!]Fail to open target process!" << endl;
		return false;
	}
	cout << "[+]Opening Target Process..." << endl;

	LPVOID MyAlloc = VirtualAllocEx(hProc, NULL, dll_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (MyAlloc == NULL)
	{
		cerr << "[!]Fail to allocate memory in Target Process." << endl;
		return false;
	}

	cout << "[+]Allocating memory in Target Process." << endl;
	int IsWriteOK = WriteProcessMemory(hProc, MyAlloc, DLL_Path.c_str(), dll_size, 0);
	if (IsWriteOK == 0)
	{
		cerr << "[!]Fail to write in Target Process memory." << endl;
		return false;
	}
	cout << "[+]Creating Remote Thread in Target Process" << endl;

	DWORD dWord;
	LPTHREAD_START_ROUTINE addrLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(LoadLibraryA("kernel32"), "LoadLibraryA");
	HANDLE ThreadReturn = CreateRemoteThread(hProc, NULL, 0, addrLoadLibrary, MyAlloc, 0, &dWord);
	if (ThreadReturn == NULL)
	{
		cerr << "[!]Fail to create Remote Thread" << endl;
		return false;
	}

	if ((hProc != NULL) && (MyAlloc != NULL) && (IsWriteOK != ERROR_INVALID_HANDLE) && (ThreadReturn != NULL))
	{
		cout << "[+]DLL Successfully Injected :)" << endl;
		return true;
	}

	return false;
}