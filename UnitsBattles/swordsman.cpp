#include "mage.h"
#include "archer.h"
#include "swordsman.h"
#include "sword.h"
#include <iostream>
#include <fstream>

namespace UnintSpace {

    swordsman::swordsman(std::string name, WeaponSpace::sword& weap, int hp, unsigned int pow) : Unit(name, hp, weap), pow(pow) {
    }

    WeaponSpace::sword weap("stic", 10);
    swordsman::swordsman() : Unit("name", 200, weap), pow(10) {
    }

    void swordsman::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            if (!enemy.GetDef())
            {
                int a = ReturnDamagByGrade(weaponn->GetDamage()) + pow;
                enemy.GetDamag(ReturnDamagByGrade(weaponn->GetDamage()) + pow);
                std::cout << name << "Swordsman atacks " << " damage is " << (ReturnDamagByGrade(weaponn->GetDamage()) + pow) << "\n";
                if (enemy.IsDead())
                {
                    hp += 10;
                    std::cout << "Enemy is dead";
                }
            }
        }
        else {
            std::cout << name << "InDefence\n";
        }
    }

    void swordsman::Defence() {
        IsInDefenceó = !IsInDefenceó;
        weaponn->Upgrade();
        std::cout << name << "Defence or Undefence\n";
    }

    int swordsman::GetDamag(int damag) {
        int trud = hp - damag;
        this->hp -= damag;
        std::cout << name << hp << "Ouch!\n";
        return trud;
    }

    std::ostream& swordsman::Serialize(std::ostream& output) {
        if (output) {
            output.write(reinterpret_cast<const char*>(&this->IsInDefenceó), sizeof(IsInDefenceó));
            size_t nameLength = name.size();
            output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            output.write(name.c_str(), nameLength);
            output.write(reinterpret_cast<const char*>(&this->speed), sizeof(speed));
            output.write(reinterpret_cast<const char*>(&this->hp), sizeof(hp));
            output.write(reinterpret_cast<const char*>(&this->pow), sizeof(pow));
            weaponn->Serialize(output);
        }
        else {
            std::cout << "Cant open";
        }
        return output;
    }

    std::istream& swordsman::Deserialize(std::istream& input) {
        if (input) {
            bool nIsInDefenceó;
            int nspeed, nhp, npow;
            size_t nameLength;
            std::string nname;
            WeaponSpace::weapon* nweaponn = new WeaponSpace::sword("", 0);

            input.read(reinterpret_cast<char*>(&nIsInDefenceó), sizeof(IsInDefenceó));
            input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            nname.resize(nameLength);
            input.read(&nname[0], nameLength);
            input.read(reinterpret_cast<char*>(&nspeed), sizeof(speed));
            input.read(reinterpret_cast<char*>(&nhp), sizeof(hp));
            input.read(reinterpret_cast<char*>(&npow), sizeof(pow));
            nweaponn->Deserialize(input);

            weaponn = nweaponn;
            name = nname;
            speed = nspeed;
            hp = nhp;
            pow = npow;
            IsInDefenceó = nIsInDefenceó;
        }
        else {
            std::cout << "Cant open";
        }
        return input;
    }

    std::ostream& swordsman::Serialize(std::string& path) {
        std::ofstream output(path);
        Serialize(output);
        output.close();
        
        return output;
    }

    std::istream& swordsman::Deserialize(std::string& path) {
        std::ifstream input(path);
        Deserialize(input);
        input.close();
        return input;
    }

    std::ostream& swordsman::Serialize() {
        std::ofstream output("output.txt");
        Serialize(output);
        output.close();
        return output;
    }

    std::istream& swordsman::Deserialize() {
        std::ifstream input("output.txt");
        Deserialize(input);
        input.close();
        return input;
    }
}
