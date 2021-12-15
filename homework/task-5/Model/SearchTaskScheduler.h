#pragma once

#include "SearchTask.h"
#include "ForestChunkGenerator.h"

#include <atomic>

// ��������� ������ �� ������� ����
struct ForestChunkSearchResult
{
    constexpr static size_t CHUNK_IGNORED_INDEX = -1;

    size_t chunkIndex = CHUNK_IGNORED_INDEX;
    size_t beeGroupId = 0;
    std::chrono::milliseconds timeSpent = 0ms;
    bool winnyPoohFound = false;
};

// ����������� ����� ������ �� ����
class SearchTaskScheduler
{
    // ���������� ����� ����
    size_t beeGroupCount;
    // ��������� �������� ����
    ForestChunkGenerator generator;
    // ������ �������� ����
    std::vector<ForestChunk> forestChunks;
    // ���������� ������ � �������� ����
    std::vector<ForestChunkSearchResult> chunkResults;
    // ������ ���� � ���� �������
    std::vector<std::thread> beeGroups;
    // ������ ���������� ���������� ������� ��� ������
    std::atomic<size_t> availableChunkIndex;

    // ���������� �������� ������ ��������� �������� (������ ���������)
    size_t GetEndChunkIndex() const
    {
        return forestChunks.size();
    }

    // ���������� ��������� ��������� ������ ������� (�������������� ������ ��� ��������� ���������)
    size_t GetAvailableChunkIndex()
    {
        return availableChunkIndex++;
    }

    // ��������� ��� ������ ����, ��� ����� ��� ������
    void NotifyWinnyPoohFound()
    {
        availableChunkIndex = GetEndChunkIndex();
    }

    // �������� ������� ���� �� �������
    ForestChunk GetForestChunk(size_t index)
    {
        return forestChunks[index];
    }

    // ���������, ��� ������� ���� ������� � �������� ��������� ������
    void NotifyChunkSearched(size_t index, ForestChunkSearchResult result)
    {
        chunkResults[index] = result;
    }

    // ������� ������ ������� ���� (�������, ����������� ������� �������)
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
    // �������� ���������� ������ �������� ����
    struct SearchResults
    {
        // ����� ����� ��������� �������� (����� ���� ������ ������ ����� ��������, ���� ����� ���� ����� ������� ������)
        size_t totalChunks = 0;
        // ������ ����������� ������ �� �������� ����
        std::vector<ForestChunkSearchResult> logEntries;
    };

    // ����������� ������������ ������
    SearchTaskScheduler(size_t beeGroupCount, ForestChunkGenerator generator)
        : beeGroupCount(beeGroupCount), generator(std::move(generator))
    {

    }

    // ������ ������ �� �������� ����
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

    // �������� ���������� ������ �� �������� ����
    const SearchResults GetSearchResults() const
    {
        return SearchResults{ forestChunks.size(), chunkResults };
    }
};