#include "archer.h"
#include "mage.h"
#include "swordsman.h"
#include "bow.h"
#include<fstream>

namespace UnintSpace {
    archer::archer(std::string name, WeaponSpace::weapon& weap, int hp, int agility) : Unit(name, hp, weap), arrows(agility) {}

    void archer::Attak(Unit& enemy) {
        if (!IsInDefenceó) {
            if (!enemy.GetDef())
            {
                if (arrows > 0) {
                    --arrows;
                    enemy.GetDamag(ReturnDamagByGrade(weaponn->GetDamage()));
                    std::cout << name << "Archer atacks " << " damage is " << (ReturnDamagByGrade(weaponn->GetDamage())) << "\n";
                    if (enemy.IsDead())
                    {
                        arrows += 5;
                        std::cout << "Enemy is dead";
                    }
                }
                else {
                    std::cout << name << " no arrows.\n";
                }
            }
            else
            {
                std::cout << "in defence enemy";
            }
        }
        else {
            std::cout << name << "InDefence\n";
        }
    }

    void archer::Defence() {
        IsInDefenceó = !IsInDefenceó;
        weaponn->Upgrade();
        std::cout << name << "Defence \n";
        arrows++;
    }

    int archer::GetDamag(int damag) {
        int trud = hp - damag;
        this->hp -= damag;
        std::cout << name << hp << "Ouch!\n";
        return trud;
    }

    std::ostream& archer::Serialize(std::ostream& output) {
        if (output) {
            output.write(reinterpret_cast<const char*>(&this->IsInDefenceó), sizeof(IsInDefenceó));
            size_t nameLength = name.size();
            output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            output.write(name.c_str(), nameLength);
            output.write(reinterpret_cast<const char*>(&this->speed), sizeof(speed));
            output.write(reinterpret_cast<const char*>(&this->hp), sizeof(hp));
            output.write(reinterpret_cast<const char*>(&this->arrows), sizeof(arrows));
            weaponn->Serialize(output);
        }
        else {
            std::cout << "cant open w";
        }
        return output;
    }

    std::istream& archer::Deserialize(std::istream& input) {
        if (input) {
            bool nIsInDefenceó;
            int nspeed, nhp, narrows;
            size_t nameLength;
            std::string nname;
            WeaponSpace::weapon* nweaponn = new WeaponSpace::bow("", 0, 0);

            input.read(reinterpret_cast<char*>(&nIsInDefenceó), sizeof(IsInDefenceó));
            input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            nname.resize(nameLength);
            input.read(&nname[0], nameLength);
            input.read(reinterpret_cast<char*>(&nspeed), sizeof(speed));
            input.read(reinterpret_cast<char*>(&nhp), sizeof(hp));
            input.read(reinterpret_cast<char*>(&narrows), sizeof(arrows));
            nweaponn->Deserialize(input);

            weaponn = nweaponn;
            name = nname;
            speed = nspeed;
            hp = nhp;
            arrows = narrows;
            IsInDefenceó = nIsInDefenceó;
        }
        else {
            std::cout << "cant open";
        }
        return input;
    }

    std::ostream& archer::Serialize(std::string& path) {
        std::ofstream output(path);
        Serialize(output);
        return output;
    }

    std::istream& archer::Deserialize(std::string& path) {
        std::ifstream input(path);
        Deserialize(input);
        return input;
    }

    std::ostream& archer::Serialize() {
        std::ofstream output("output.txt");
        Serialize(output);
        output.close();
        return output;
    }

    std::istream& archer::Deserialize() {
        std::ifstream input("output.txt");
        Deserialize(input);
        input.close();
        return input;
    }
}