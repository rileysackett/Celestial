#include "sackfamutil.hpp"
#include "character.hpp"
#include "enemy.hpp"
#pragma once
using namespace std;

void enemyDamage(Character &character, Enemy &enemy);
void combat(Character character, Enemy enemy);
void playerDamage(Character &character, Enemy &enemy);
bool willCrit(int critChance);

void combat(Character character, Enemy enemy) {
    bool allyTurn = true;
    while(character.hp > 0 && enemy.hp > 0) {
        if(allyTurn) {
            cout << "\nAlly HP: " << character.hp << endl << "Enemy HP: " << enemy.hp << endl << endl;
            sleep(1000);
            playerDamage(character,enemy);
            if(enemy.hp <= 0) {
                cout << "\nYou won!" << endl;
                break;
            }
            allyTurn = false;
        } else {
            cout << "\nAlly HP: " << character.hp << endl << "Enemy HP: " << enemy.hp << endl << endl;
            sleep(1000);
            enemyDamage(character,enemy);
            if(character.hp <= 0) {
                cout << "\nDefeat...!" << endl;
                break;
            }
            allyTurn = true;
        }
    }
}

void enemyDamage(Character &character, Enemy &enemy) {
    int dmg;
    if(willCrit(enemy.crit)) {
        dmg = (enemy.atk)*((100.)/(100+character.def)) * 2;
    } else {
        dmg = (enemy.atk)*((100.)/(100+character.def));
    }
    character.hp -= dmg;
    cout << enemy.name << " dealt " << dmg << " damage!" << endl;

}

void playerDamage(Character &character, Enemy &enemy) {
    int dmg;
    if(willCrit(character.crit)) {
        dmg = (character.atk)*((100.)/(100+enemy.def)) * 2;
    } else {
        dmg = (character.atk)*((100.)/(100+enemy.def));
    }
    enemy.hp -= dmg;
    cout << character.name << " dealt " << dmg << " damage!" << endl;
}

bool willCrit(int critChance) {
    int i = randomRange(0,99);
    if(i < critChance) {
        return true;
    } else {
        return false;
    }
}