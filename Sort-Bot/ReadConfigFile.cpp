#include "ReadConfigFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "MovPrefix.h"

bool ReadPrefixConfigFile::ParseConfig() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << filename_ << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("[{") != std::string::npos) {
            ParseBlock(file);
        }
    }

    file.close();
    return true;
}

void ReadPrefixConfigFile::PrintData() {
    for (const auto& entry : AssignPrefix::assignPrefix) {
        std::cout << "CaseName: " << entry.tagOfCase << std::endl;
        std::cout << "ItemVector: \n";
        for (const auto& item : entry.prefix.nameOfItems) {
            std::cout << item << "\n";
        }
        std::cout << std::endl;
    }
}

void ReadPrefixConfigFile::ParseBlock(std::ifstream& file) {
    AssignPrefix assingPrefix_temp;
    Prefix prefix;

    std::string caseName;

    std::string line;
    bool newBlock = true;
    prefix.isFull = false;
    prefix.nameOfItems = {};
    while (std::getline(file, line)) {
        if (line.find("}]") != std::string::npos) {
            assingPrefix_temp.prefix = prefix;
            assingPrefix_temp.tagOfCase = caseName;
            AssignPrefix::assignPrefix.push_back(assingPrefix_temp);

            newBlock = true;
            prefix.isFull = false;
            prefix.nameOfItems = {};
            break;
        }

        size_t startPos = line.find("\"") + 1;
        size_t endPos = line.find("\"", startPos);

        if (newBlock == true) {
            if (startPos != std::string::npos && endPos != std::string::npos)
                caseName = line.substr(startPos, endPos - startPos);
            newBlock = false;
        }
        else {
            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string itemName = line.substr(startPos, endPos - startPos);
                prefix.nameOfItems.push_back(itemName);
            }
        }
    }
}

