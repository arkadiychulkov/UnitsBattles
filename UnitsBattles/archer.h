#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"bow.h"
#include"ISerializable.h"

namespace UnintSpace {
    class archer : public Unit, public ISerializable {
    private:
        unsigned int arrows;

    public:
        archer(std::string name, WeaponSpace::weapon& weap, int hp, int agility);

        int GetDamag(int damag) override;
        void Attak(Unit& enemy) override;
        void Defence();

        std::ostream& Serialize(std::ostream& output) override;
        std::istream& Deserialize(std::istream& input) override;
        std::ostream& Serialize(std::string& path) override;
        std::istream& Deserialize(std::string& path) override;
        std::ostream& Serialize() override;
        std::istream& Deserialize() override;
    };
}