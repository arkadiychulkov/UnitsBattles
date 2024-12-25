#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "sword.h"
#include <iostream>

swordsman::swordsman(std::string name, sword weap, int hp, unsigned int pow) : Unit(name, hp), pow(pow) {
}

void swordsman::Attak(Unit& enemy) {
    if (!IsInDefenceó) {
        enemy.GetDamag(weaponn.GetDamage());
        std::cout << name << " atacks " << " damage is " << (weaponn.GetDamage() + pow) << "\n";
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void swordsman::AttakArcher(archer& enemy) {
    Attak(enemy);
}

void swordsman::AttakMage(mage& enemy) {
    Attak(enemy);
}

void swordsman::AttakSwordsman(swordsman& enemy) {
    Attak(enemy);
}

void swordsman::Defence() {
    IsInDefenceó = !IsInDefenceó;
    std::cout << name << "Defence or Undefence\n";
}
