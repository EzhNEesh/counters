#ifndef PCMREADER_H
#define PCMREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class PCMReader
{
public:
    PCMReader();
    int getCountOfBreaks(const std::string &);
private:
    std::string filePath;
};

#endif // PCMREADER_H
