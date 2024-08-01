#include "gtest/gtest.h"
#include <vector>
#include <filesystem>

#include "../src/pcmreader.h"
#include "../src/pcmreader.cpp"

TEST(PCMReader_Group, BreaksDontExist_Test) {
    std::string directoryPath = "data_raw_32_rand_ch_offs";
    PCMReader pcmReader;

    std::filesystem::directory_iterator dirIterator;
    dirIterator = std::filesystem::directory_iterator{directoryPath};

    for (auto &file : dirIterator) {
        std::string filePath = file.path().string();
        std::vector<std::string> breaksBuf;
        int countOfBreaks;
        std::tie(countOfBreaks, breaksBuf) = pcmReader.getCountOfBreaks(filePath);

        ASSERT_EQ(0, countOfBreaks);
    }
}

TEST(PCMReader_Group, BreaksExist_Test) {
    std::string directoryPath = "data_raw_32_rand_ch_offs_break";
    PCMReader pcmReader;

    std::filesystem::directory_iterator dirIterator;
    dirIterator = std::filesystem::directory_iterator{directoryPath};

    for (auto &file : dirIterator) {
        std::string filePath = file.path().string();
        std::vector<std::string> breaksBuf;
        int countOfBreaks;
        std::tie(countOfBreaks, breaksBuf) = pcmReader.getCountOfBreaks(filePath);

        ASSERT_EQ(128, countOfBreaks);
    }
}
