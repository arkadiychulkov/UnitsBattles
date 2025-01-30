#include "weapon.h"
#include "stick.h"
#include<fstream>

namespace WeaponSpace {
    stick::stick(std::string name, unsigned int damage, int chargs) : weapon(name, damage), charges(chargs) {}

    Grade stick::GetDamage() {
        this->charges--;
        return grade;
    }

    void stick::AddCharges(int add) {
        this->charges += add;
    }

    void stick::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
            charges += 2;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 6;
            charges += 3;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 4;
            charges += 3;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 10;
            charges += 6;
        }
        else {
            damage += 5;
        }
    }


    std::ostream& stick::Serialize(std::ostream& output) {
        if (output) {
            output.write(reinterpret_cast<const char*>(&this->grade), sizeof(grade));
            size_t nameLength = name.size();
            output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            output.write(name.c_str(), nameLength);
            output.write(reinterpret_cast<const char*>(&this->charges), sizeof(charges));
            output.write(reinterpret_cast<const char*>(&this->damage), sizeof(damage));
        } else {
            std::cout << "cant open w";
        }
        return output;
    }

    std::istream& stick::Deserialize(std::istream& input) {
        if (input) {
            int ncharges, ndamag;
            size_t nameLength;
            std::string nname;
            Grade ngrade;

            input.read(reinterpret_cast<char*>(&ngrade), sizeof(grade));
            input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            nname.resize(nameLength);
            input.read(&nname[0], nameLength);
            input.read(reinterpret_cast<char*>(&ncharges), sizeof(charges));
            input.read(reinterpret_cast<char*>(&ndamag), sizeof(damage));

            grade = ngrade;
            name = nname;
            charges = ncharges;
            damage = ndamag;
        } else {
            std::cout << "cant open";
        }
        return input;
    }

    std::ostream& stick::Serialize(std::string& path) {
        std::ofstream output(path);
        Serialize(output);
        return output;
    }

    std::istream& stick::Deserialize(std::string& path) {
        std::ifstream input(path);
        Deserialize(input);
        return input;
    }

    std::ostream& stick::Serialize() {
        std::ofstream output("output.txt");
        Serialize(output);
        output.close();
        return output;
    }

    std::istream& stick::Deserialize() {
        std::ifstream input("output.txt");
        Deserialize(input);
        input.close();
        return input;
    }
}