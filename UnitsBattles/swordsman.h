#pragma once
#include "Unit.h"
#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include"sword.h"
#include"ISerializable.h"

namespace UnintSpace {
    class swordsman : public Unit, public ISerializable {
    private:
        unsigned int pow;

    public:
        swordsman(std::string name, WeaponSpace::sword& weap, int hp, unsigned int pow);
        swordsman();

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