// Main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "ProcessManager.h"
#include "MemoryManager.h"
#include "CoordinateManager.h"
#include "Constants.h"
#include "AddressManager.h"
const float SPEED_MULTIPLIER = 1.0f; // 移动速度乘数
const float THRESHOLD = 0.5f; // 跟随的最小距离阈值

HANDLE hProcess;
DWORD_PTR addressA, addressB;

void AutoFollowEnemy() {
    float ownX = 0.0f, ownY = 0.0f;
    float enemyX = 0.0f, enemyY = 0.0f;

    DWORD_PTR baseAddress = 0x3F7E2354; // 替换为实际的基址
    SetMemoryAddresses(baseAddress, addressA, addressB); // 设置内存地址

    while (true) {
        // 读取坐标
        ReadCoordinates(hProcess, ownX, ownY, enemyX, enemyY);



        // 计算方向向量
        float deltaX = enemyX - ownX;
        float deltaY = enemyY - ownY;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);


        // 实时显示我方和敌方坐标以及双方距离
        std::cout << "我方坐标: (" << ownX << ", " << ownY << ")"
            << " | 敌方坐标: (" << enemyX << ", " << enemyY << ")"
            << " | 距离: " << distance << std::endl;


        // 计算单位方向向量
        if (distance > THRESHOLD) {
            float directionX = deltaX / distance;
            float directionY = deltaY / distance;

            // 根据方向向量计算aValue和bValue
            float aValue = directionX * SPEED_MULTIPLIER;
            float bValue = directionY * SPEED_MULTIPLIER;

            // 写入内存控制人物移动
            WriteMemory(hProcess, addressA, aValue);
            WriteMemory(hProcess, addressB, bValue);
        }

        // 每次更新后休眠一点时间，以便平滑移动
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    hProcess = GetProcessHandle(L"MEmuHeadless.exe"); // 替换为你的进程名称
    if (!hProcess) {
        std::cerr << "无法获取进程句柄。" << std::endl;
        return 1;
    }

    AutoFollowEnemy();

    CloseHandle(hProcess);
    return 0;
}
