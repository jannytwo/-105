// Main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "ProcessManager.h"
#include "MemoryManager.h"
#include "CoordinateManager.h"
#include "Constants.h"
#include "AddressManager.h"
const float SPEED_MULTIPLIER = 1.0f; // �ƶ��ٶȳ���
const float THRESHOLD = 0.5f; // �������С������ֵ

HANDLE hProcess;
DWORD_PTR addressA, addressB;

void AutoFollowEnemy() {
    float ownX = 0.0f, ownY = 0.0f;
    float enemyX = 0.0f, enemyY = 0.0f;

    DWORD_PTR baseAddress = 0x3F7E2354; // �滻Ϊʵ�ʵĻ�ַ
    SetMemoryAddresses(baseAddress, addressA, addressB); // �����ڴ��ַ

    while (true) {
        // ��ȡ����
        ReadCoordinates(hProcess, ownX, ownY, enemyX, enemyY);



        // ���㷽������
        float deltaX = enemyX - ownX;
        float deltaY = enemyY - ownY;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);


        // ʵʱ��ʾ�ҷ��͵з������Լ�˫������
        std::cout << "�ҷ�����: (" << ownX << ", " << ownY << ")"
            << " | �з�����: (" << enemyX << ", " << enemyY << ")"
            << " | ����: " << distance << std::endl;


        // ���㵥λ��������
        if (distance > THRESHOLD) {
            float directionX = deltaX / distance;
            float directionY = deltaY / distance;

            // ���ݷ�����������aValue��bValue
            float aValue = directionX * SPEED_MULTIPLIER;
            float bValue = directionY * SPEED_MULTIPLIER;

            // д���ڴ���������ƶ�
            WriteMemory(hProcess, addressA, aValue);
            WriteMemory(hProcess, addressB, bValue);
        }

        // ÿ�θ��º�����һ��ʱ�䣬�Ա�ƽ���ƶ�
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    hProcess = GetProcessHandle(L"MEmuHeadless.exe"); // �滻Ϊ��Ľ�������
    if (!hProcess) {
        std::cerr << "�޷���ȡ���̾����" << std::endl;
        return 1;
    }

    AutoFollowEnemy();

    CloseHandle(hProcess);
    return 0;
}
