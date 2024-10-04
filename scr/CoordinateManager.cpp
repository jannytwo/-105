// CoordinateManager.cpp
#include "CoordinateManager.h"
#include "MemoryManager.h"
#include "Constants.h"
#include <iostream>

void ReadCoordinates(HANDLE hProcess, float& ownX, float& ownY, float& enemyX, float& enemyY) {
    ReadFloatFromMemory(hProcess, (LPCVOID)(OWN_BASE_ADDRESS - 0x6C), ownX); // 我方X坐标
    ReadFloatFromMemory(hProcess, (LPCVOID)(OWN_BASE_ADDRESS - 0x64), ownY); // 我方Y坐标
    ReadFloatFromMemory(hProcess, (LPCVOID)(ENEMY_BASE_ADDRESS - 0x6C), enemyX); // 敌方X坐标
    ReadFloatFromMemory(hProcess, (LPCVOID)(ENEMY_BASE_ADDRESS - 0x64), enemyY); // 敌方Y坐标

    if (ownX == 0.0f && ownY == 0.0f) {
        std::cerr << "我方坐标读取失败，重新尝试读取。" << std::endl;
    }
    if (enemyX == 0.0f && enemyY == 0.0f) {
        std::cerr << "敌方坐标读取失败，重新尝试读取。" << std::endl;
    }
}
