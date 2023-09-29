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
    c_log::End("ReadPrefixConfigFile", c_log::Magenta, "              | [Funktion]", c_log::White, "Parent", c_log::LBlue, "InitializeMovPrefix");
    return true;
}

void ReadPrefixConfigFile::PrintData() {
    for (AssignPrefix entry : AssignPrefix::assignPrefix_vec) {
        c_log::Info("IDMov: ", c_log::LGreen, entry.IdMov);
        c_log::Info("Item:  ", c_log::LGreen, entry.NameOfItem);
        c_log::Info("MinHP: ", c_log::LGreen, entry.MinHp);
        c_log::Info("BuyQuantity: ", c_log::LGreen, entry.BuyQuantity);
        std::cout << std::endl;
    }
}

void ReadPrefixConfigFile::ParseBlock(std::ifstream& file) {
    AssignPrefix assingPrefix_temp;

    std::string line;
    bool newBlock = true;

    while (std::getline(file, line)) {
        if (line.find("}]") != std::string::npos) {
            // Blockende erreicht, füge die assingPrefix_temp zur Liste hinzu
            newBlock = true;
        }

        // Beginn eines neuen Blocks
        if (newBlock == true) {
            size_t startPos = line.find("\"") + 1;
            size_t endPos = line.find("\"", startPos);

            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string ID = line.substr(startPos, endPos - startPos);
                //cout << ID << endl;
                assingPrefix_temp.IdMov = std::stoi(ID);
                newBlock = false;
            }
        }
        else {
            size_t startPos = line.find("\"") + 1;
            size_t endPos = line.find("\"", startPos);

            if (startPos != std::string::npos && endPos != std::string::npos) {
                std::string itemName = line.substr(startPos, endPos - startPos);
                // Entferne führende und abschließende Anführungszeichen, falls vorhanden
                if (!itemName.empty() && itemName.front() == '"') {
                    itemName.erase(0, 1);
                }
                if (!itemName.empty() && itemName.back() == '"') {
                    itemName.pop_back();
                }
                //cout << itemName << endl;
                assingPrefix_temp.NameOfItem = itemName;

                // Weiter zum nächsten Wert (MinHp)
                std::getline(file, line); // Die nächste Zeile enthält den Wert in Anführungszeichen
                if (!line.empty()) {
                    size_t startPos = line.find("\"") + 1;
                    size_t endPos = line.find("\"", startPos);

                    if (startPos != std::string::npos && endPos != std::string::npos) {
                        std::string minHpStr = line.substr(startPos, endPos - startPos);
                        // Entferne führende und abschließende Anführungszeichen, falls vorhanden
                        if (!minHpStr.empty() && minHpStr.front() == '"') {
                            minHpStr.erase(0, 1);
                        }
                        if (!minHpStr.empty() && minHpStr.back() == '"') {
                            minHpStr.pop_back();
                        }
                        //cout << minHpStr << endl;
                        assingPrefix_temp.MinHp = std::stoi(minHpStr);


                        std::getline(file, line); // Die nächste Zeile enthält den Wert in Anführungszeichen
                        if (!line.empty()) {
                            size_t startPos = line.find("\"") + 1;
                            size_t endPos = line.find("\"", startPos);

                            if (startPos != std::string::npos && endPos != std::string::npos) {
                                std::string buyQuantity = line.substr(startPos, endPos - startPos);
                                // Entferne führende und abschließende Anführungszeichen, falls vorhanden
                                if (!buyQuantity.empty() && buyQuantity.front() == '"') {
                                    buyQuantity.erase(0, 1);
                                }
                                if (!buyQuantity.empty() && buyQuantity.back() == '"') {
                                    buyQuantity.pop_back();
                                }
                                //cout << minHpStr << endl;
                                assingPrefix_temp.BuyQuantity = std::stoi(buyQuantity);

                                AssignPrefix::assignPrefix_vec.push_back(assingPrefix_temp);
                            }
                        }
                    }
                }
            }
        }
    }
}