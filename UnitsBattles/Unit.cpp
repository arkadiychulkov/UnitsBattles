#include "Unit.h"
Unit::Unit(std::string name, std::string weaponName, int weaponDam, int hp) : name(name), hp(hp), speed(0), IsInDefenceó(false), weapon(weaponName, weaponDam) {
}

void Unit::Attak(Unit& enemy) {
    if (!IsInDefenceó) {
        enemy.hp -= weapon.GetDamage();
        std::cout << name << " atacks " << enemy.name << " damage is " << weapon.GetDamage() << "\n";
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
    os << "Name: " << unit.name << " HP: " << unit.hp << " Speed: " << unit.speed;
    return os;
}