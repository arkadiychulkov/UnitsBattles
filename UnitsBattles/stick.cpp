#include "weapon.h"
#include "stick.h"

namespace WeaponSpace {
    stick::stick(std::string name, unsigned int damage, int chargs) : weapon(name, damage), charges(chargs) {}

    Grade stick::GetDamage() {
        this->charges--;
        return grade;
    }

    void stick::AddCharges(int add) {
        this->charges += add;
    }

    void stick::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
            charges += 2;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 6;
            charges += 3;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 4;
            charges += 3;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 10;
            charges += 6;
        }
        else {
            damage += 5;
        }
    }
}