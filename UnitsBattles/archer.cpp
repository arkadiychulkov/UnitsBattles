#include "archer.h"
#include "mage.h"
#include "swordsman.h"
#include "bow.h"

archer::archer(std::string name, bow weap, int hp, unsigned int arrows) : Unit(name, hp), arrows(arrows) {}

void archer::AttakArcher(archer& enemy) {
    if (!IsInDefenceó) {
        if (arrows > 0) {
            --arrows;
            enemy.GetDamag(weaponn.GetDamage());
            std::cout << name << " shoots at archer " << enemy.name << "!\n";
        }
        else {
            std::cout << name << " no arrows.\n";
        }
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void archer::AttakMage(mage& enemy) {
    if (!IsInDefenceó) {
        if (arrows > 0) {
            --arrows;
            enemy.GetDamag(weaponn.GetDamage());
            std::cout << name << " shoots at archer " << "!\n";
        }
        else {
            std::cout << name << " no arrows.\n";
        }
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void archer::AttakSwordsman(swordsman& enemy) {
    if (!IsInDefenceó) {
        if (arrows > 0) {
            --arrows;
            enemy.GetDamag(weaponn.GetDamage());
            std::cout << name << " shoots at archer " << "!\n";
        }
        else {
            std::cout << name << " no arrows.\n";
        }
    }
    else {
        std::cout << name << "InDefence\n";
    }
}

void archer::Defence() {
    IsInDefenceó = !IsInDefenceó;
    std::cout << name << "Defence \n";
}