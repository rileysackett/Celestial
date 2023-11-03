#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "character.hpp"
#include "enemy.hpp"
#include "sackfamutil.hpp"
#include "combat.hpp"
#include "savefiles.hpp"
using namespace std;

void start();
void intro();
void setup();
Character player;

int main() {
    
    Character test = Character("Abeeb", 100, 10, 10, 5, 1, 0);
    player = test;
    Character test2 = Character("Riley", 9,9,9,9,9,9);
    test2.printStats();
    test2.loadSaveData();
    test.printStats();
    return 0;
}

void start() {
    clear();
    char sfq;
    ifstream saveFile;
    cout << "Load save file (Y/N)" << endl;
    cin >> sfq;
    if(sfq == 'N') {
        return;
    } else {
        saveFile.open("save.txt");
    }
}

void intro() {

}

void setup() {

}