#pragma once

#include "ForestChunk.h"

#include <random>
#include <ctime>

// ��������� �������� ���� ��� ������
class ForestChunkGenerator
{
    // ����������� ����� ����� ���� � ������� ����
    const float winnyPoohProbability;
    // ��������� ��������� �����
    std::default_random_engine generator;
    // ��������� ����������� [0.0; 1.0]
    std::uniform_real_distribution<float> probabilityRandomGenerator;
    // ��������� ������� ������ [min, max]
    std::uniform_int_distribution<unsigned int> timeRandomGenerator;

public:
    // ����������� ����������
    ForestChunkGenerator(
        float winnyPoohProbability, std::chrono::milliseconds minSearchTime, std::chrono::milliseconds maxSearchTime
    )
        : winnyPoohProbability(winnyPoohProbability), generator(time(nullptr))
    {
        timeRandomGenerator = std::uniform_int_distribution<unsigned int>(minSearchTime.count(), maxSearchTime.count());
    }

    // ������������� ������� ����
    ForestChunk Generate()
    {
        ForestChunk result;
        result.containsWinnyPooh = (probabilityRandomGenerator(generator) < winnyPoohProbability);
        result.timeToSearch = std::chrono::milliseconds(timeRandomGenerator(generator));
        return result;
    }

};