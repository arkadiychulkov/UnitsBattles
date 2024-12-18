#include "weapon.h"
weapon::weapon(std::string name, unsigned int damage)
    : name(name), damage(damage), grade(Common) {
}

weapon::weapon()
    : name("weapon"), damage(10), grade(Common) {
}

weapon::weapon(std::string name)
    : name(name), damage(10), grade(Common) {
}

unsigned int weapon::GetDamage() {
    return damage;
}

void weapon::UpGreade() {
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
 
Grade weapon::GetGrade() {
    return grade;
}
