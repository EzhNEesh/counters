#include <iostream>
#include <filesystem>
#include <future>
#include "pcmreader.h"

int main()
{
    std::vector<std::string> filesPaths;
    std::vector<std::future<std::tuple<int, std::vector<std::string>>>> futures;

    for (auto & file : std::filesystem::directory_iterator("data_raw_32_rand_ch_offs")) {
        std::string filePath = file.path().string();
        futures.push_back(async(&PCMReader::getCountOfBreaks, PCMReader(), filePath));
        filesPaths.push_back(filePath);
    }

    std::vector<int> countOfBreaks;
    for (unsigned int i = 0; i < filesPaths.size(); i++) {
        int countOfBreaksInFile;
        std::vector<std::string> breaks;
        std::tie(countOfBreaksInFile, breaks) = futures[i].get();
        for (auto it = breaks.begin(); it != breaks.end(); it++) {
            std::cout << *it;
        }
        countOfBreaks.push_back(countOfBreaksInFile);
    }

    for (unsigned int i = 0; i < countOfBreaks.size(); i++) {
        std::cout << "Count of breaks of file " << filesPaths[i] << ": " << countOfBreaks[i] << std::endl;
    }
    // thread t1(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[0]);
    // thread t2(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[1]);
    // thread t3(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[2]);
    // thread t4(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[3]);
    // thread t5(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[4]);
    // thread t6(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[5]);
    // thread t7(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[6]);
    // thread t8(&PCMReader::getCountOfBreaks, PCMReader(), filesPaths[7]);
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();
    // t7.join();
    // t8.join();
    return 0;
}
