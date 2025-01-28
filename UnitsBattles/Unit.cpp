#include "Unit.h"
#include "weapon.h"

namespace UnintSpace {
    Unit::Unit(std::string name, int hp) : name(name), hp(hp), speed(0), IsInDefenceó(false) {
    }

    Unit::Unit(std::string name, int hp, WeaponSpace::weapon weap) : name(name), hp(hp), speed(0), IsInDefenceó(false), weaponn(weap) {
    }

    int Unit::ReturnDamagByGrade(WeaponSpace::Grade gd) {
        int cof = 0;
        if (weaponn.GetDamage() == WeaponSpace::Common) {
            cof = 1;
        }
        else if (weaponn.GetDamage() == WeaponSpace::Rare) {
            cof = 2;
        }
        else if (weaponn.GetDamage() == WeaponSpace::Epic) {
            cof = 3;
        }
        else if (weaponn.GetDamage() == WeaponSpace::Legendary) {
            cof = 5;
        }
        return weaponn.GetUron() * cof;
    }

    bool Unit::GetDef() {
        return IsInDefenceó;
    }

    void Unit::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            enemy.GetDamag(ReturnDamagByGrade(weaponn.GetDamage()));
            std::cout << name << " atacks " << enemy.name << " damage is " << weaponn.GetDamage() << "\n";
        }
        else {
            std::cout << name << "InDefence\n";
        }
    }

    void Unit::Defence() {
        IsInDefenceó = !IsInDefenceó;
        std::cout << name << "Defence or Undefence\n";
    }

    int Unit::GetDamag(int damag) {
        int trud = hp - damag;
        this->hp -= damag;
        std::cout << name << hp << "Ouch!\n";
        return trud;
    }

    bool Unit::IsDead() {
        return hp <= 0;
    }

    std::ostream& operator<<(std::ostream& os, const Unit& unit) {
        os << "Name: " << unit.name << " HP: " << unit.hp << " Speed: " << unit.speed << std::endl;
        if (unit.hp <= 0)
            std::cout << "Dead";
        return os;
    }
}