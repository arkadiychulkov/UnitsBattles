#pragma once
#include "Unit.h"
#include"stick.h"

class mage;
class archer;
class swordsman;

namespace UnintSpace {
    class mage : public Unit {
    private:
        unsigned int mana;

    public:
        mage(std::string name, WeaponSpace::stick& weap, int hp, unsigned int mana);
        mage();

        void Attak(Unit& enemy) override;
        void Defence();
    };
}