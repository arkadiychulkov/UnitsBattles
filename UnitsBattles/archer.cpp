#include "archer.h"
#include "mage.h"
#include "swordsman.h"
#include "bow.h"

namespace UnintSpace {
    archer::archer(std::string name, WeaponSpace::weapon& weap, int hp, int agility) : Unit(name, hp, weap), arrows(agility) {}

    void archer::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            if (!enemy.GetDef())
            {
                if (arrows > 0) {
                    --arrows;
                    enemy.GetDamag(ReturnDamagByGrade(weaponn->GetDamage()));
                    std::cout << name << "Archer atacks " << " damage is " << (ReturnDamagByGrade(weaponn->GetDamage())) << "\n";
                    if (enemy.IsDead())
                    {
                        arrows += 5;
                        std::cout << "Enemy is dead";
                    }
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
        weaponn->Upgrade();
        std::cout << name << "Defence \n";
        arrows++;
    }

    int archer::GetDamag(int damag) {
        int trud = hp - damag;
        this->hp -= damag;
        std::cout << name << hp << "Ouch!\n";
        return trud;
    }
}