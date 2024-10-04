// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

void WriteMemory(HANDLE hProcess, DWORD_PTR address, float value) {
    SIZE_T bytesWritten;
    if (!WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(address), &value, sizeof(value), &bytesWritten)) {
        std::cerr << "д���ڴ�ʧ�ܣ���ַ: " << std::hex << address << " ������: " << GetLastError() << std::endl;
    }
}

void ReadFloatFromMemory(HANDLE hProcess, LPCVOID address, float& value) {
    SIZE_T bytesRead;
    if (!ReadProcessMemory(hProcess, address, &value, sizeof(float), &bytesRead)) {
        std::cerr << "��ȡ�ڴ�ʧ�ܣ���ַ: " << std::hex << address << " ������: " << GetLastError() << std::endl;
    }
    else {
        std::cout << "��ȡ�ڴ��ַ: " << std::hex << address << " | ֵ: " << value << std::endl;
    }
}
