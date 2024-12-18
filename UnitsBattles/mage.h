#pragma once
#include "Unit.h"
#include"stick.h"

class mage;
class archer;
class swordsman;

class mage : public Unit {
private:
    unsigned int mana;

public:
    mage(std::string name, stick weap, int hp, unsigned int mana);
    void AttakArcher(archer& enemy);
    void AttakMage(mage& enemy);
    void AttakSwordsman(swordsman& enemy);
    void Defence();
};
