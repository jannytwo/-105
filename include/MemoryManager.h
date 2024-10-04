// MemoryManager.h
#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <windows.h>

void WriteMemory(HANDLE hProcess, DWORD_PTR address, float value);
void ReadFloatFromMemory(HANDLE hProcess, LPCVOID address, float& value);

#endif // MEMORYMANAGER_H
