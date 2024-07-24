#ifndef PCMREADER_H
#define PCMREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

class PCMReader
{
public:
    PCMReader();
    std::tuple <int, std::vector<std::string>> getCountOfBreaks(const std::string &);
};

#endif // PCMREADER_H
