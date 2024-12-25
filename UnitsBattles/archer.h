#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"bow.h"

class archer : public Unit {
private:
    unsigned int arrows;

public:
    archer(std::string name, bow weap, int hp, unsigned int arrows);

    void Attak(Unit& enemy) override;
    void AttakArcher(archer& enemy);
    void AttakMage(mage& enemy);
    void AttakSwordsman(swordsman& enemy);
    void Defence();
};
