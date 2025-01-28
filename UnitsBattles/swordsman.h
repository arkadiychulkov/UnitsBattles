#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"sword.h"

namespace UnintSpace {
    class swordsman : public Unit {
    private:
        unsigned int pow;

    public:
        swordsman(std::string name, WeaponSpace::sword& weap, int hp, unsigned int pow);
        swordsman();

        void Attak(Unit& enemy) override;
        void Defence();
    };
}