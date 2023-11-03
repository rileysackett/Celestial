#include <fstream>
#include <vector>
#include "character.hpp"
#pragma once

std::vector<char> openSaveFile();
void saveFile();

std::vector<char> openSaveFile() {
    std::ifstream savefile("save.txt");
    char c;
    std::vector<char> saveData;
    while(savefile.get(c)) {
        saveData.push_back(c);
    }
    return saveData;
}

void save(Character player) {
    std::ofstream savefile("save.txt");
    savefile << player.getSaveData();
    savefile.close();
}