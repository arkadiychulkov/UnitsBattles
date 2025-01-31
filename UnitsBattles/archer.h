#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"bow.h"

namespace UnintSpace {
    class archer : public Unit {
    private:
        unsigned int arrows;

    public:
        archer(std::string name, WeaponSpace::weapon& weap, int hp, int agility);

        int GetDamag(int damag) override;
        void Attak(Unit& enemy) override;
        void Defence();
    };
}