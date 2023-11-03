#include <string>
#pragma once

class Enemy {
    public:
    std::string name;
    int hp;
    int atk;
    int def;
    int crit;
    Enemy(std::string name, int hp, int atk, int def, int crit) {
        this->name = name;
        this->hp = hp;
        this->atk = atk;
        this->def = def;
        this->crit = crit;
    }
    Enemy() = default;
};