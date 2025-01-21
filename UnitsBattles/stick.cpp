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
            charges++;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 6;
            charges++;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 4;
            charges++;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 10;
            charges++;
        }
        else {
            damage += 5;
        }
    }
}