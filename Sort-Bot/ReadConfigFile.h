#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ReadPrefixConfigFile {
public:
    ReadPrefixConfigFile(const std::string& filename) : filename_(filename) {}

    bool ParseConfig() {
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

    void PrintData() {
        for (const auto& entry : data_) {
            std::cout << "CaseName: " << entry.first << std::endl;
            std::cout << "ItemVector: \n";
            for (const auto& item : entry.second) {
                std::cout << item << "\n";
            }
            std::cout << std::endl;
        }
    }

private:
    void ParseBlock(std::ifstream& file) {
        std::string caseName;
        std::vector<std::string> itemVector;

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("}]") != std::string::npos) {
                // Ende des Blocks erreicht
                data_.emplace_back(std::make_pair(caseName, itemVector));
                break;
            }

            size_t startPos = line.find("\"") + 1;
            size_t endPos = line.find("\"", startPos); 

            size_t nameStartPos = line.find("[{") + 1;
            size_t nameEndPos = line.find("},", nameStartPos);

            if (nameStartPos != std::string::npos && nameEndPos != std::string::npos) {
                caseName = line.substr(nameStartPos, nameEndPos - nameStartPos);
            }
            else if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string itemName = line.substr(startPos, endPos - startPos);
                itemVector.push_back(itemName);
            }
        }
    }

    std::string filename_;
    std::vector<std::pair<std::string, std::vector<std::string>>> data_;
};