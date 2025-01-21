#include "sword.h"
#include "weapon.h"

namespace WeaponSpace {
    sword::sword(std::string name, unsigned int damage) : weapon(name, damage) {}

    Grade sword::GetDamage() {
        return grade;
    }

    void sword::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 5;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 5;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 5;
        }
        else {
            damage += 5;
        }
    }
}