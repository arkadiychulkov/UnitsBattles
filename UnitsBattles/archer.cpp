#include "archer.h"
#include "mage.h"
#include "swordsman.h"

archer::archer(std::string name, std::string weaponName, int weaponDam, int hp, unsigned int arrows) : Unit(name, weaponName, weaponDam, hp), arrows(arrows) {}

void archer::AttakArcher(archer& enemy) {
    if (arrows > 0) {
        --arrows;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at archer " << enemy.name << "!\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void archer::AttakMage(mage& enemy) {
    if (arrows > 0) {
        --arrows;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at mage " << "!\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void archer::AttakSwordsman(swordsman& enemy) {
    if (arrows > 0) {
        --arrows;
        enemy.GetDamag(weapon.GetDamage());
        std::cout << name << " shoots at swordsman " << "!\n";
    }
    else {
        std::cout << name << " no arrows.\n";
    }
}

void archer::Defence() {
    IsInDefence� = !IsInDefence�;
    std::cout << name << "Defence \n";
}