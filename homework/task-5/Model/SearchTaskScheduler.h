#pragma once

#include "SearchTask.h"
#include "ForestChunkGenerator.h"

#include <atomic>

// результат поиска по участку леса
struct ForestChunkSearchResult
{
    constexpr static size_t CHUNK_IGNORED_INDEX = -1;

    size_t chunkIndex = CHUNK_IGNORED_INDEX;
    size_t beeGroupId = 0;
    std::chrono::milliseconds timeSpent = 0ms;
    bool winnyPoohFound = false;
};

// организатор задач поиска по лесу
class SearchTaskScheduler
{
    // Количество групп пчел
    size_t beeGroupCount;
    // Генератор участков леса
    ForestChunkGenerator generator;
    // Список участков леса
    std::vector<ForestChunk> forestChunks;
    // Результаты поиска в участках леса
    std::vector<ForestChunkSearchResult> chunkResults;
    // Группы пчел в виде потоков
    std::vector<std::thread> beeGroups;
    // Индекс следующего доступного участка для поиска
    std::atomic<size_t> availableChunkIndex;

    // Возвращает конечный индекс доступных участков (задача завершена)
    size_t GetEndChunkIndex() const
    {
        return forestChunks.size();
    }

    // возвращает ближайший доступный индекс участка (инкрементирует индекс для следующих обращений)
    size_t GetAvailableChunkIndex()
    {
        return availableChunkIndex++;
    }

    // Уведомить все группы пчел, что Винни Пух найден
    void NotifyWinnyPoohFound()
    {
        availableChunkIndex = GetEndChunkIndex();
    }

    // Получить участок леса по индексу
    ForestChunk GetForestChunk(size_t index)
    {
        return forestChunks[index];
    }

    // Уведомить, что участок леса обыскан и записать результат поиска
    void NotifyChunkSearched(size_t index, ForestChunkSearchResult result)
    {
        chunkResults[index] = result;
    }

    // Функция поиска группой пчел (функция, исполняемая рабочим потоком)
    static void BeeGroupThreadFunc(SearchTaskScheduler& scheduler, size_t groupIndex)
    {
        while (true)
        {
            size_t chunkIndex = scheduler.GetAvailableChunkIndex();
            if (chunkIndex < scheduler.GetEndChunkIndex())
            {
                ForestChunk chunk = scheduler.GetForestChunk(chunkIndex);
                SearchTask task(chunk);
                SearchTaskResult result = task.Run();
                if (result.WinnyPoohFound)
                    scheduler.NotifyWinnyPoohFound();

                ForestChunkSearchResult searchResult{ 
                    chunkIndex, 
                    groupIndex,
                    chunk.timeToSearch, 
                    result.WinnyPoohFound 
                };
                scheduler.NotifyChunkSearched(chunkIndex, searchResult);
            }
            else break;
        }
    }

public:
    // Конечные результаты поиска группами пчел
    struct SearchResults
    {
        // Общее число обысканых участков (может быть меньше общего числа участков, если Винни Пуха нашли вначале поиска)
        size_t totalChunks = 0;
        // Список результатов поиска по участкам леса
        std::vector<ForestChunkSearchResult> logEntries;
    };

    // Конструктор огранизатора поиска
    SearchTaskScheduler(size_t beeGroupCount, ForestChunkGenerator generator)
        : beeGroupCount(beeGroupCount), generator(std::move(generator))
    {

    }

    // Запуск поиска по участкам леса
    void Run()
    {
        while (true)
        {
            ForestChunk chunk = generator.Generate();
            forestChunks.push_back(chunk);
            if (chunk.containsWinnyPooh)
                break;
        }
        std::random_shuffle(forestChunks.begin(), forestChunks.end());
        chunkResults.resize(forestChunks.size());

        for (size_t i = 0; i < beeGroupCount; i++)
        {
            beeGroups.push_back(std::thread([this, i]() { BeeGroupThreadFunc(*this, i); }));
        }
        for (size_t i = 0; i < beeGroupCount; i++)
        {
            beeGroups[i].join();
        }

        while (!chunkResults.empty() && chunkResults.back().chunkIndex == ForestChunkSearchResult::CHUNK_IGNORED_INDEX)
            chunkResults.pop_back();
    }

    // Получить результаты поиска по участкам леса
    const SearchResults GetSearchResults() const
    {
        return SearchResults{ forestChunks.size(), chunkResults };
    }
};