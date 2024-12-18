#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"

class archer : public Unit {
private:
    unsigned int arrows;

public:
    archer(std::string name, std::string weaponName, int weaponDam, int hp, unsigned int arrows);
    void AttakArcher(archer& enemy);
    void AttakMage(mage& enemy);
    void AttakSwordsman(swordsman& enemy);
    void Defence();
};
