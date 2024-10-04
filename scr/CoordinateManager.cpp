// CoordinateManager.cpp
#include "CoordinateManager.h"
#include "MemoryManager.h"
#include "Constants.h"
#include <iostream>

void ReadCoordinates(HANDLE hProcess, float& ownX, float& ownY, float& enemyX, float& enemyY) {
    ReadFloatFromMemory(hProcess, (LPCVOID)(OWN_BASE_ADDRESS - 0x6C), ownX); // �ҷ�X����
    ReadFloatFromMemory(hProcess, (LPCVOID)(OWN_BASE_ADDRESS - 0x64), ownY); // �ҷ�Y����
    ReadFloatFromMemory(hProcess, (LPCVOID)(ENEMY_BASE_ADDRESS - 0x6C), enemyX); // �з�X����
    ReadFloatFromMemory(hProcess, (LPCVOID)(ENEMY_BASE_ADDRESS - 0x64), enemyY); // �з�Y����

    if (ownX == 0.0f && ownY == 0.0f) {
        std::cerr << "�ҷ������ȡʧ�ܣ����³��Զ�ȡ��" << std::endl;
    }
    if (enemyX == 0.0f && enemyY == 0.0f) {
        std::cerr << "�з������ȡʧ�ܣ����³��Զ�ȡ��" << std::endl;
    }
}
