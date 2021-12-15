#pragma once

#include "ForestChunk.h"

#include <thread>

// ��������� ������ �� ������� ����
struct SearchTaskResult
{
    // ������ �� ����� ��� � �������
    bool WinnyPoohFound = false;
};

// ������ ������ � ������� ���� 
class SearchTask
{
    // ������� ����
    ForestChunk chunk;
public:
    // ����������� ������ ������
    SearchTask(const ForestChunk& chunk)
        : chunk(chunk)
    {

    }

    // ������ ������
    SearchTaskResult Run()
    {
        std::this_thread::sleep_for(chunk.timeToSearch);
        return SearchTaskResult{ chunk.containsWinnyPooh };
    }
};