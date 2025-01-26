#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "sword.h"
#include <iostream>

namespace UnintSpace {

    swordsman::swordsman(std::string name, WeaponSpace::weapon weap, int hp, unsigned int pow) : Unit(name, hp, weap), pow(pow) {
    }

    WeaponSpace::sword weap("stic", 10);
    swordsman::swordsman() : Unit("name", 200, weap), pow(10) {
    }

    void swordsman::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            if (!enemy.GetDef())
            {
                int a = ReturnDamagByGrade(weaponn.GetDamage()) + pow;
                enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()) + pow);
                std::cout << name << "Swordsman atacks " << " damage is " << (ReturnDamagByGrade(weaponn.GetDamage()) + pow) << "\n";
                if (enemy.IsDead())
                {
                    hp += 10;
                    std::cout << "Enemy is dead";
                }
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
