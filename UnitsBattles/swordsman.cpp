#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "sword.h"
#include <iostream>

namespace UnintSpace {

    swordsman::swordsman(std::string name, WeaponSpace::sword weap, int hp, unsigned int pow) : Unit(name, hp), pow(pow) {
    }

    void swordsman::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            if (!enemy.GetDef())
            {
                enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()) + pow);
                std::cout << name << "Swordsman atacks " << " damage is " << (ReturnDamagByGrade(weaponn.GetDamage()) + pow) << "\n";
            }
        }
        else {
            std::cout << name << "InDefence\n";
        }
    }

    void swordsman::Defence() {
        IsInDefenceó = !IsInDefenceó;
        weaponn.UpGreade();
        std::cout << name << "Defence or Undefence\n";
    }
}
