#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "stick.h"

mage::mage(std::string name, stick weap, int hp, unsigned int mana) : Unit(name, hp), mana(mana) {}

void mage::Attak(Unit& enemy) {
    if (!IsInDefenceó)
    {
        if (!enemy.GetDef()) {
            if (mana >= 10) {
                mana -= 10;
                enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()));
                std::cout << name << "Mage atacks " << " damage is " << (ReturnDamagByGrade(weaponn.GetDamage())) << "\n";
            }
            else {
                std::cout << name << " no arrows.\n";
            }
        }
    }
    else
        std::cout << "In Defence";
}

void mage::Defence() {
    IsInDefenceó = !IsInDefenceó;
    weaponn.UpGreade();
    std::cout << name << "Defence or Undefence\n";
}
