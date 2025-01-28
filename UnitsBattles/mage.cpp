#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "stick.h"

namespace UnintSpace {
    mage::mage(std::string name, WeaponSpace::weapon weap, int hp, unsigned int mana) : Unit(name, hp, weap), mana(mana) {}

    WeaponSpace::stick weap("stic", 10, 10);
    mage::mage() : Unit("Mage", 200, weap), mana(100) {}

    void mage::Attak(Unit& enemy) {
        if (!IsInDefenceó)
        {
            if (!enemy.GetDef()) {
                if (mana >= 10) {
                    mana -= 10;
                    enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()));
                    std::cout << name << "Mage atacks " << " damage is " << (ReturnDamagByGrade(weaponn.GetDamage())) << "\n";
                    if (enemy.IsDead())
                    {
                        mana += 25;
                        std::cout << "Enemy is dead";
                    }
                }
                else {
                    std::cout << name << " no mana.\n";
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
}