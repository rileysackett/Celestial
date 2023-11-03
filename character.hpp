#include "ability.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "sackfamutil.hpp"
#pragma once
using namespace std;

class Character {
    public:
    std::string name;
    int hp;
    int maxhp;
    int atk;
    int def;
    int divinity;
    int maxdivinity;
    int xp;
    int level;
    int crit;
    Ability ability;
    int gameCheckpoint;
    
    Character(std::string name, int maxhp, int atk, int def, int maxdivinity, int level, int crit) {
        this->name = name;
        this->hp = maxhp;
        this->maxhp = maxhp;
        this->atk = atk;
        this->def = def;
        this->divinity = maxdivinity;
        this->maxdivinity = maxdivinity;
        this->xp = 0;
        this->level = level;
        this->crit = crit;
        this->gameCheckpoint = 0;
    }
    Character() = default;

    void addXP(int xp) {
        int level_threshold = pow(level,2) + 10;
        this->xp += xp;
        while(this->xp >= level_threshold) {
            this->xp = xp - level_threshold;
            level++;
            level_threshold = pow(level,2) + 10;
        }
    }
    void addLevel(int levels) {
        this->level += levels;
    }

    void clear() {system("clear");}

    void printStats() {
        clear();
        int level_threshold = pow(level,2) + 10;
        std::cout << "--------" << name << "--------\n" << std::endl;
        std::cout << "Level: " << level << " (" << xp << "/" << level_threshold << ")" << "\nAttack: " << atk << "\nHealth: " << hp << "/" << maxhp << "\nDefense: " << 
        def << "\nDivinity: " << divinity << "/" << maxdivinity << std::endl << std::endl << "Press enter to exit" << std::endl;
        std::cin.ignore();
    }

    std::string getSaveData() {
        std::string data = "";
        data += name;
        data += "|";
        data += to_string(hp);
        data += "|";
        data += to_string(maxhp);
        data += "|";
        data += to_string(atk);
        data += "|";
        data += to_string(def);
        data += "|";
        data += to_string(divinity);
        data += "|";
        data += to_string(maxdivinity);
        data += "|";
        data += to_string(xp);
        data += "|";
        data += to_string(level);
        data += "|";
        data += to_string(crit);
        data += "|";
        data += to_string(gameCheckpoint);
        return data;
    }

    void loadSaveData() {
        std::ifstream savefile("save.txt");
        std::vector<std::string> data;
        std::string s;
        while(getline(savefile,s,'|')) {
            data.push_back(s);
        }
        this->name = data.at(0);
        this->hp = stoi(data.at(1));
        this->maxhp = stoi(data.at(2));
        this->atk = stoi(data.at(3));
        this->def = stoi(data.at(4));
        this->divinity = stoi(data.at(5));
        this->maxdivinity = stoi(data.at(6));
        this->xp = stoi(data.at(7));
        this->level = stoi(data.at(8));
        this->crit = stoi(data.at(9));
        this->gameCheckpoint = stoi(data.at(10));
    }

};