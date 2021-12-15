#pragma once



#include "ForestChunk.h"



#include <thread>



// Результат поиска по участку леса

struct SearchTaskResult

{

    // Найден ли Винни Пух в участке

    bool WinnyPoohFound = false;

};



// Задача поиска в участке леса 

class SearchTask

{

    // Участок леса

    ForestChunk chunk;

public:

    // Конструктор задачи поиска

    SearchTask(const ForestChunk& chunk)

        : chunk(chunk)

    {



    }



    // Запуск поиска

    SearchTaskResult Run()

    {

        std::this_thread::sleep_for(chunk.timeToSearch);

        return SearchTaskResult{ chunk.containsWinnyPooh };

    }

};