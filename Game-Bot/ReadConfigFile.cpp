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
        c_log::Info("Fehler beim Öffnen der Datei:  ", c_log::LGreen, filename_);
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
    for (const auto& entry : AssignPrefix::assignPrefix) {
        c_log::Info("CaseName: ", c_log::LGreen, entry.IdMov);
        c_log::Info("Item: ", c_log::LGreen, entry.NameOfItem);
        c_log::Info("MinHP: ", c_log::LGreen, entry.MinHp);
        std::cout << std::endl;
    }
}

void ::ParseBlock(std::ifstream& file) { // TODO: Fix error when reading minHpStr and itemName
    AssignPrefix assingPrefix_temp;

    std::string line;
    bool newBlock = true;

    while (std::getline(file, line)) {
        if (line.find("}]") != std::string::npos) {
            // Blockende erreicht, füge die assingPrefix_temp zur Liste hinzu
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
                cout << ID << endl;
                assingPrefix_temp.IdMov = std::stoi(ID);
                newBlock = false;
            }
        }
        else {
            size_t startPos = line.find("(") + 1;
            size_t endPos = line.find("\"", startPos);

            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string itemName = line.substr(startPos, endPos - startPos);
                cout << itemName << endl;
                assingPrefix_temp.NameOfItem = itemName;

                // Weiter zum nächsten Wert (MinHp)
                startPos = endPos + 3; // Überspringe '", "' zwischen Name und MinHp
                endPos = line.find("\"", startPos);

                if (startPos != std::string::npos && endPos != std::string::npos) {
                    std::string minHpStr = line.substr(startPos, endPos - startPos);
                    cout << minHpStr << endl;
                    assingPrefix_temp.MinHp = std::stoi(minHpStr);
                }
            }
        }
    }
}

