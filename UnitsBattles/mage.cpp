#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "stick.h"
#include<fstream>

namespace UnintSpace {
    mage::mage(std::string name, WeaponSpace::stick& weap, int hp, unsigned int mana) : Unit(name, hp, weap), mana(mana) {}

    WeaponSpace::stick weap("stic", 10, 10);
    mage::mage() : Unit("Mage", 200, weap), mana(100) {}

    void mage::Attak(Unit& enemy) {
        if (!IsInDefenceó)
        {
            if (!enemy.GetDef()) {
                if (mana >= 10) {
                    mana -= 10;
                    enemy.GetDamag(ReturnDamagByGrade(weaponn->GetDamage()));
                    std::cout << name << "Mage atacks " << " damage is " << (ReturnDamagByGrade(weaponn->GetDamage())) << "\n";
                    if (enemy.IsDead())
                    {
                        mana += 25;
                        std::cout << "Enemy is dead";
                    }
                }
                else {
                    std::cout << name << " no mana.\n";
                }
            }
        }
        else
            std::cout << "In Defence";
    }

    void mage::Defence() {
        IsInDefenceó = !IsInDefenceó;
        weaponn->Upgrade();
        std::cout << name << "Defence or Undefence\n";
    }

    int mage::GetDamag(int damag) {
        int trud = hp - damag;
        this->hp -= damag;
        std::cout << name << hp << "Ouch!\n";
        return trud;
    }

    std::ostream& mage::Serialize(std::ostream& output) {
        if (output) {
            output.write(reinterpret_cast<const char*>(&this->IsInDefenceó), sizeof(IsInDefenceó));
            size_t nameLength = name.size();
            output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            output.write(name.c_str(), nameLength);
            output.write(reinterpret_cast<const char*>(&this->speed), sizeof(speed));
            output.write(reinterpret_cast<const char*>(&this->hp), sizeof(hp));
            output.write(reinterpret_cast<const char*>(&this->mana), sizeof(mana));
            weaponn->Serialize(output);
        }
        else {
            std::cout << "cant open w";
        }
        return output;
    }

    std::istream& mage::Deserialize(std::istream& input) {
        if (input) {
            bool nIsInDefenceó;
            int nspeed, nhp, nmana;
            size_t nameLength;
            std::string nname;
            WeaponSpace::weapon* nweaponn = new WeaponSpace::stick("", 0, 0);

            input.read(reinterpret_cast<char*>(&nIsInDefenceó), sizeof(IsInDefenceó));
            input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            nname.resize(nameLength);
            input.read(&nname[0], nameLength);
            input.read(reinterpret_cast<char*>(&nspeed), sizeof(speed));
            input.read(reinterpret_cast<char*>(&nhp), sizeof(hp));
            input.read(reinterpret_cast<char*>(&nmana), sizeof(mana));
            nweaponn->Deserialize(input);

            weaponn = nweaponn;
            name = nname;
            speed = nspeed;
            hp = nhp;
            mana = nmana;
            IsInDefenceó = nIsInDefenceó;
        }
        else {
            std::cout << "cant open";
        }
        return input;
    }

    std::ostream& mage::Serialize(std::string& path) {
        std::ofstream output(path);
        Serialize(output);
        return output;
    }

    std::istream& mage::Deserialize(std::string& path) {
        std::ifstream input(path);
        Deserialize(input);
        return input;
    }

    std::ostream& mage::Serialize() {
        std::ofstream output("output.txt");
        Serialize(output);
        output.close();
        return output;
    }

    std::istream& mage::Deserialize() {
        std::ifstream input("output.txt");
        Deserialize(input);
        input.close();
        return input;
    }
}