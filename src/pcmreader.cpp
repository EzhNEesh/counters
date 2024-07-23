#include "pcmreader.h"

PCMReader::PCMReader() { }

int PCMReader::getCountOfBreaks(const std::string &filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (file.is_open()) {
        uint32_t num;
        std::vector<uint32_t> prev_nums;
        int curCounter = 0;
        int iNum = 0;
        int CountOfBreaks = 0;

        while (file.read((char*)&num, sizeof(uint32_t))) {
            if (prev_nums.size() == curCounter) {
                prev_nums.push_back(num);
                iNum ++;
            } else if (iNum == 31) {
                prev_nums[curCounter] = num;
                iNum = 0;
                curCounter = (curCounter + 1) % 32;
            } else {
                if (prev_nums[curCounter] + 1 != num) {
                    std::cout << filePath << ' ' << curCounter << ' ' << prev_nums[curCounter] + 1 << ' ' << num << std::endl;
                    CountOfBreaks++;
                }
                prev_nums[curCounter] = num;
                iNum++;
            }
        }
        file.close();
        return CountOfBreaks;
    }
    return -1;
}
