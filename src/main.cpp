#include <iostream>
#include <filesystem>
#include <future>
#include "pcmreader.h"

using namespace std;

int main()
{
    vector<string> filesPaths;
    vector<future<int>> futures;

    for (auto & file : filesystem::directory_iterator("data_raw_32_rand_ch_offs_break")) {
        string filePath = file.path().string();
        futures.push_back(async(&PCMReader::getCountOfBreaks, PCMReader(), filePath));
        filesPaths.push_back(filePath);
    }
    for (unsigned int i = 0; i < filesPaths.size(); i++) {
        cout << "Count of breaks of file " << filesPaths[i] << ": " << futures[i].get() << endl;
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
