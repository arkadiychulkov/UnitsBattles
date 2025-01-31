#pragma once
#include "Unit.h"
#include"stick.h"
#include"ISerializable.h"

class mage;
class archer;
class swordsman;

namespace UnintSpace {
    class mage : public Unit, public ISerializable {
    private:
        unsigned int mana;

    public:
        mage(std::string name, WeaponSpace::stick& weap, int hp, unsigned int mana);
        mage();

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