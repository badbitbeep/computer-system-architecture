#include "Model/SearchTaskScheduler.h"



#include <iostream>



int main(int argc, char* argv[])

{

    if (argc != 5)

    {

        std::cout << "usage: task5 [1] [2] [3] [4]\n";

        std::cout << "[1] - Winny Pooh probability per forest chunk (0.0 - 1.0]\n";

        std::cout << "[2] - min time to search a forest chunk (> 0)\n";

        std::cout << "[3] - max time to search a forest chunk (> 0)\n";

        std::cout << "[4] - bee group count (> 0)\n";

        return 1;

    }



    float probability = std::atof(argv[1]);

    int minTime = std::atoi(argv[2]);

    int maxTime = std::atoi(argv[3]);

    int groups = std::atoi(argv[4]);



    if (probability <= 0.0 || probability > 1.0)

    {

        std::cout << "invalid probability: " << probability;

        return 1;

    }

    if (minTime <= 0 || maxTime <= 0 || groups <= 0)

    {

        std::cout << "min time, max time and group count must be positive";

        return 1;

    }





    ForestChunkGenerator generator(probability, std::chrono::milliseconds(minTime), std::chrono::milliseconds(maxTime));

    SearchTaskScheduler scheduler(groups, generator);

    scheduler.Run();

    auto& results = scheduler.GetSearchResults();

    for (const auto& entry : results.logEntries)

    {

        std::cout << "bee group #" << entry.beeGroupId << " searched chunk #" << entry.chunkIndex;

        std::cout << " for " << entry.timeSpent.count() << "ms";

        if (entry.winnyPoohFound)

            std::cout << "| Winny Pooh was found and punished!";



        std::cout << std::endl;

    }

    std::cout << "there were " << results.totalChunks << " chunks in total" << std::endl;

    return 0;

}