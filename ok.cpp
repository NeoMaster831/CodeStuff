#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>

using namespace std;
int main() {

    string target = "notepad.exe";

	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 entry; entry.dwSize = sizeof(entry);
	for (bool valid = Process32First(snap, &entry); valid; valid = Process32Next(snap, &entry)) {
		
        if (!stricmp(target.c_str(), (const char*)entry.szExeFile)) {
            cout << "success " << entry.th32ProcessID << '\n';
        }
        //cout << entry.szExeFile << '\n';
	}
}