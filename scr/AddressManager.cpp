// AddressManager.cpp
#include "AddressManager.h"

void SetMemoryAddresses(DWORD_PTR baseAddress, DWORD_PTR& addressA, DWORD_PTR& addressB) {
    addressA = baseAddress - 0x1C; // ����ֵ��ַ
    addressB = baseAddress - 0x18; // ����ֵ��ַ
}
