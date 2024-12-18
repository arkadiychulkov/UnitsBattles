#include "mage.h"
#include "archer.h"
#include "swordsman.h"

mage::mage(std::string name, std::string weaponName, int weaponDam, int hp, unsigned int mana) : Unit(name, weaponName, weaponDam, hp), mana(mana) {}

void mage::AttakArcher(archer& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at archer " << "\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void mage::AttakMage(mage& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at archer " << "\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void mage::AttakSwordsman(swordsman& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at archer " << "\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void mage::Defence() {
    IsInDefenceó = !IsInDefenceó;
    std::cout << name << "Defence or Undefence\n";
}
