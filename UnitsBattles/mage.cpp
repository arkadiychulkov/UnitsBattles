#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "stick.h"

mage::mage(std::string name, stick weap, int hp, unsigned int mana) : Unit(name, hp), mana(mana) {}

void mage::Attak(Unit& enemy) {
    if (!IsInDefenceó)
    {
        if (mana >= 10) {
            mana -= 10;
            enemy.GetDamag(weaponn.GetDamage());
            std::cout << name << " shoots at archer " << "\n";
        }
        else {
            std::cout << name << " no arrows.\n";
        }
    }
    else
        std::cout << "In Defence";
}

void mage::AttakArcher(archer& enemy) {
    Attak(enemy);
}

void mage::AttakMage(mage& enemy) {
    Attak(enemy);
}

void mage::AttakSwordsman(swordsman& enemy) {
    Attak(enemy);
}

void mage::Defence() {
    IsInDefenceó = !IsInDefenceó;
    std::cout << name << "Defence or Undefence\n";
}
