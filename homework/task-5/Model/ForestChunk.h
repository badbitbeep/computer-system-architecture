#pragma once

#include <chrono>

using namespace std::literals;

// ������� ����
struct ForestChunk
{
    // �����, ����������� ��� ������ � �������
    std::chrono::milliseconds timeToSearch = 0ms;
    // ��������� �� ����� ��� � �������
    bool containsWinnyPooh = false;
};