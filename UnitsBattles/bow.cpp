#include "bow.h"
#include "weapon.h"

namespace WeaponSpace {
    bow::bow(std::string name, int damage, int maxda) : weapon(name, damage), maxDamage(maxda) {}

    Grade bow::GetDamage() {
        return grade;
    }

    void bow::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
            maxDamage += 2;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 5;
            maxDamage += 3;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 5;
            maxDamage += 5;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 5;
            maxDamage += 2;
        }
        else {
            damage += 5;
            maxDamage++;
        }
    }
}