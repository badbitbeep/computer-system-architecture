#pragma once

#include <chrono>

using namespace std::literals;

// Участок леса
struct ForestChunk
{
    // Время, необходимое для поиска в участке
    std::chrono::milliseconds timeToSearch = 0ms;
    // Находится ли Винни Пух в участке
    bool containsWinnyPooh = false;
};