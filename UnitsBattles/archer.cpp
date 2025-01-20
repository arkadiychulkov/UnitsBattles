#include "archer.h"
#include "mage.h"
#include "swordsman.h"
#include "bow.h"

archer::archer(std::string name, bow weap, int hp, unsigned int arrows) : Unit(name, hp), arrows(arrows) {}

void archer::Attak(Unit& enemy) {
    if (!IsInDefenceó) {
        if (!enemy.GetDef())
        {
            if (arrows > 0) {
                --arrows;
                enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()));
                std::cout << name << "Archer atacks " << " damage is " << (ReturnDamagByGrade(weaponn.GetDamage())) << "\n";
            }
            else {
                std::cout << name << " no arrows.\n";
            }
        }
        else
        {
            std::cout << "in defence enemy";
        }
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void archer::Defence() {
    IsInDefenceó = !IsInDefenceó;
    weaponn.UpGreade();
    std::cout << name << "Defence \n";
    arrows++;
}