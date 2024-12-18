#pragma once
#include "Unit.h"
class mage;
class archer;
class swordsman;

class mage : public Unit {
private:
    unsigned int mana;

public:
    mage(std::string name, std::string weaponName, int weaponDam, int hp, unsigned int mana);
    void AttakArcher(archer& enemy);
    void AttakMage(mage& enemy);
    void AttakSwordsman(swordsman& enemy);
    void Defence();
};
