#include "sword.h"
#include "weapon.h"
#include<fstream>

namespace WeaponSpace {
    sword::sword(std::string name, unsigned int damage) : weapon(name, damage) {}

    Grade sword::GetDamage() {
        return grade;
    }

    void sword::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 5;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 5;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 5;
        }
        else {
            damage += 5;
        }
    }
    std::ostream& sword::Serialize(std::ostream& output) {
        if (output) {
            output.write(reinterpret_cast<const char*>(&this->grade), sizeof(grade));
            size_t nameLength = name.size();
            output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
            output.write(name.c_str(), nameLength);
            output.write(reinterpret_cast<const char*>(&this->damage), sizeof(damage));
        }
        else {
            std::cout << "cant open w";
        }
        return output;
    }

    std::istream& sword::Deserialize(std::istream& input) {
        if (input) {
            int nmaxDamage, ndamag;
            size_t nameLength;
            std::string nname;
            Grade ngrade;

            input.read(reinterpret_cast<char*>(&ngrade), sizeof(grade));
            input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            nname.resize(nameLength);
            input.read(&nname[0], nameLength);
            input.read(reinterpret_cast<char*>(&ndamag), sizeof(damage));

            grade = ngrade;
            name = nname;
            damage = ndamag;
        }
        else {
            std::cout << "cant open";
        }
        return input;
    }

    std::ostream& sword::Serialize(std::string& path) {
        std::ofstream output(path);
        Serialize(output);
        return output;
    }

    std::istream& sword::Deserialize(std::string& path) {
        std::ifstream input(path);
        Deserialize(input);
        return input;
    }

    std::ostream& sword::Serialize() {
        std::ofstream output("output.txt");
        Serialize(output);
        output.close();
        return output;
    }

    std::istream& sword::Deserialize() {
        std::ifstream input("output.txt");
        Deserialize(input);
        input.close();
        return input;
    }
}