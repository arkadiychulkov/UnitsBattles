#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "sword.h"
#include <iostream>

swordsman::swordsman(std::string name, std::string weaponName, int hp, unsigned int pow, int weaponDamag) : Unit(name, weaponName, weaponDamag, hp), pow(pow) {
}

void swordsman::AttakArcher(archer& enemy) {
    if (!IsInDefence�) {
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " atacks " << " damage is " << (weapon.GetDamage()+pow) << "\n";
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void swordsman::AttakMage(mage& enemy) {
    if (!IsInDefence�) {
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " atacks " << " damage is " << (weapon.GetDamage() + pow) << "\n";
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void swordsman::AttakSwordsman(swordsman& enemy) {
    if (!IsInDefence�) {
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " atacks " << " damage is " << (weapon.GetDamage() + pow) << "\n";
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void swordsman::Defence() {
    IsInDefence� = !IsInDefence�;
    std::cout << name << "Defence or Undefence\n";
}
