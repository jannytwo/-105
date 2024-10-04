// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

void WriteMemory(HANDLE hProcess, DWORD_PTR address, float value) {
    SIZE_T bytesWritten;
    if (!WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(address), &value, sizeof(value), &bytesWritten)) {
        std::cerr << "Ð´ÈëÄÚ´æÊ§°Ü£¬µØÖ·: " << std::hex << address << " ´íÎóÂë: " << GetLastError() << std::endl;
    }
}

void ReadFloatFromMemory(HANDLE hProcess, LPCVOID address, float& value) {
    SIZE_T bytesRead;
    if (!ReadProcessMemory(hProcess, address, &value, sizeof(float), &bytesRead)) {
        std::cerr << "¶ÁÈ¡ÄÚ´æÊ§°Ü£¬µØÖ·: " << std::hex << address << " ´íÎóÂë: " << GetLastError() << std::endl;
    }
    else {
        std::cout << "¶ÁÈ¡ÄÚ´æµØÖ·: " << std::hex << address << " | Öµ: " << value << std::endl;
    }
}
