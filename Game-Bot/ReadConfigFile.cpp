#include "ReadConfigFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "MovPrefix.h"
#include "c_log.h"


bool ReadPrefixConfigFile::ParseConfig() {
    c_log::Start("ReadPrefixConfigFile", c_log::Magenta, "              | [Funktion]", c_log::White, "Parent", c_log::LBlue, "InitializeMovPrefix");
    std::ifstream file(filename_);
    if (!file.is_open()) {
        c_log::Info("Fehler beim �ffnen der Datei:  ", c_log::LGreen, filename_);
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("[{") != std::string::npos) {
            ParseBlock(file);
        }
    }

    file.close();
    PrintData();
    c_log::End("ReadPrefixConfigFile", c_log::Magenta, "              | [Funktion]", c_log::White, "Parent", c_log::LBlue, "InitializeMovPrefix");
    return true;
}

void ReadPrefixConfigFile::PrintData() {
   /* for (const auto& entry : AssignPrefix::assignPrefix) {
        c_log::Info("CaseName: ", c_log::LGreen, entry.tagOfCase);
        c_log::Info("Items: ", c_log::LGreen, entry.prefix.nameOfItems[0]);
        for (uint16_t i = 1; i < entry.prefix.nameOfItems.size(); i++) {
            c_log::Raw("                   ", c_log::LGreen, entry.prefix.nameOfItems[i]);
        }
        std::cout << std::endl;
    }*/
}

void ReadPrefixConfigFile::ParseBlock(std::ifstream& file) {
    AssignPrefix assingPrefix_temp;

    std::string line;
    bool newBlock = true;

    while (std::getline(file, line)) {
        if (line.find("}]") != std::string::npos) {
            // Blockende erreicht, f�ge die assingPrefix_temp zur Liste hinzu
            AssignPrefix::assignPrefix.push_back(assingPrefix_temp);

            newBlock = true;
            break;
        }

        // Beginn eines neuen Blocks
        if (newBlock == true) {
            size_t startPos = line.find("\"") + 1;
            size_t endPos = line.find("\"", startPos);

            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string ID = line.substr(startPos, endPos - startPos);
                assingPrefix_temp.IdMov = std::stoi(ID);
                newBlock = false;
            }
        }
        else {
            size_t startPos = line.find("(") + 1;
            size_t endPos = line.find("\"", startPos);

            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string itemName = line.substr(startPos, endPos - startPos);
                assingPrefix_temp.NameOfItem = itemName;

                // Weiter zum n�chsten Wert (MinHp)
                startPos = endPos + 3; // �berspringe '", "' zwischen Name und MinHp
                endPos = line.find("\"", startPos);

                if (startPos != std::string::npos && endPos != std::string::npos) {
                    std::string minHpStr = line.substr(startPos, endPos - startPos);
                    assingPrefix_temp.MinHp = std::stoi(minHpStr);
                }
            }
        }
    }
}

