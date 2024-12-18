#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "stick.h"

mage::mage(std::string name, stick weap, int hp, unsigned int mana) : Unit(name, hp), mana(mana) {}

void mage::AttakArcher(archer& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weaponn.GetDamage());
        std::cout << name << " shoots at archer " << "\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void mage::AttakMage(mage& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weaponn.GetDamage());
        std::cout << name << " shoots at archer " << "\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void mage::AttakSwordsman(swordsman& enemy) {
    if (mana >= 10) {
        mana -= 10;
        enemy.GetDamag(weaponn.GetDamage());
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
