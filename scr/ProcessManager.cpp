// ProcessManager.cpp
#include "ProcessManager.h"
#include <tlhelp32.h>
#include <iostream>

HANDLE GetProcessHandle(const wchar_t* processName) {
    HANDLE hProcess = NULL;
    PROCESSENTRY32 pe32 = { sizeof(pe32) };
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return NULL;
    }

    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (!_wcsicmp(pe32.szExeFile, processName)) {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
                break;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return hProcess;
}
