#pragma once
#include <string>

class ReadPrefixConfigFile {
public:
    ReadPrefixConfigFile(const std::string& filename) : filename_(filename) {}

    bool ParseConfig();

    void PrintData();

private:
    void ParseBlock(std::ifstream& file);

    std::string filename_;
};