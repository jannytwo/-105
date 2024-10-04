// AddressManager.cpp
#include "AddressManager.h"

void SetMemoryAddresses(DWORD_PTR baseAddress, DWORD_PTR& addressA, DWORD_PTR& addressB) {
    addressA = baseAddress - 0x1C; // 左右值地址
    addressB = baseAddress - 0x18; // 上下值地址
}
