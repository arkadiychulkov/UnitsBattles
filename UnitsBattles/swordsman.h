#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"sword.h"

class swordsman : public Unit {
private:
    unsigned int pow;

public:
    swordsman(std::string name, sword weap, int hp, unsigned int pow);

    void Attak(Unit& enemy) override;
    void AttakArcher(archer& enemy);
    void AttakMage(mage& enemy);
    void AttakSwordsman(swordsman& enemy);
    void Defence();
};
