#pragma once



#include "ForestChunk.h"



#include <random>

#include <ctime>



// Генератор участков леса для поиска

class ForestChunkGenerator

{

    // Вероятность найти Винни Пуха в участке леса

    const float winnyPoohProbability;

    // Генератор случайных чисел

    std::default_random_engine generator;

    // Генератор вероятности [0.0; 1.0]

    std::uniform_real_distribution<float> probabilityRandomGenerator;

    // Генератор времени поиска [min, max]

    std::uniform_int_distribution<unsigned int> timeRandomGenerator;



public:

    // Конструктор генератора

    ForestChunkGenerator(

        float winnyPoohProbability, std::chrono::milliseconds minSearchTime, std::chrono::milliseconds maxSearchTime

    )

        : winnyPoohProbability(winnyPoohProbability), generator(time(nullptr))

    {

        timeRandomGenerator = std::uniform_int_distribution<unsigned int>(minSearchTime.count(), maxSearchTime.count());

    }



    // сгенерировать участок леса

    ForestChunk Generate()

    {

        ForestChunk result;

        result.containsWinnyPooh = (probabilityRandomGenerator(generator) < winnyPoohProbability);

        result.timeToSearch = std::chrono::milliseconds(timeRandomGenerator(generator));

        return result;

    }



};