#include "Unit.h"
#include "weapon.h"

Unit::Unit(std::string name, int hp) : name(name), hp(hp), speed(0), IsInDefenceó(false) {
}

void Unit::Attak(Unit& enemy) {
    if (!IsInDefenceó) {
        enemy.hp -= weaponn.GetDamage();
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

void Unit::GetDamag(int damag) {
    this->hp -= damag;
    std::cout << name << "Ouch!\n";
}

std::ostream& operator<<(std::ostream& os, const Unit& unit) {
    os << "Name: " << unit.name << " HP: " << unit.hp << " Speed: " << unit.speed << std::endl;
    if (unit.hp <= 0)
        std::cout << "Dead";
    return os;
}