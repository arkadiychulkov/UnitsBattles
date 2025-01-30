#include "bow.h"
#include "weapon.h"
#include<fstream>

namespace WeaponSpace {
    bow::bow(std::string name, int damage, int maxda) : weapon(name, damage), maxDamage(maxda) {}

    Grade bow::GetDamage() {
        return grade;
    }

    void bow::Upgrade() {
        if (grade = Common) {
            grade = Rare;
            damage += 5;
            maxDamage += 2;
        }
        else if (grade = Rare) {
            grade = Epic;
            damage += 5;
            maxDamage += 3;
        }
        else if (grade = Epic) {
            grade = Legendary;
            damage += 5;
            maxDamage += 5;
        }
        else if (grade = Legendary) {
            grade = Myphic;
            damage += 5;
            maxDamage += 2;
        }
        else {
            damage += 5;
            maxDamage++;
        }
    }

        std::ostream& bow::Serialize(std::ostream& output) {
            if (output) {
                output.write(reinterpret_cast<const char*>(&this->grade), sizeof(grade));
                size_t nameLength = name.size();
                output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
                output.write(name.c_str(), nameLength);
                output.write(reinterpret_cast<const char*>(&this->maxDamage), sizeof(maxDamage));
                output.write(reinterpret_cast<const char*>(&this->damage), sizeof(damage));
            }
            else {
                std::cout << "cant open w";
            }
            return output;
        }

        std::istream& bow::Deserialize(std::istream& input) {
            if (input) {
                int nmaxDamage, ndamag;
                size_t nameLength;
                std::string nname;
                Grade ngrade;

                input.read(reinterpret_cast<char*>(&ngrade), sizeof(grade));
                input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
                nname.resize(nameLength);
                input.read(&nname[0], nameLength);
                input.read(reinterpret_cast<char*>(&nmaxDamage), sizeof(maxDamage));
                input.read(reinterpret_cast<char*>(&ndamag), sizeof(damage));

                grade = ngrade;
                name = nname;
                maxDamage = nmaxDamage;
                damage = ndamag;
            }
            else {
                std::cout << "cant open";
            }
            return input;
        }

        std::ostream& bow::Serialize(std::string& path) {
            std::ofstream output(path);
            Serialize(output);
            return output;
        }

        std::istream& bow::Deserialize(std::string& path) {
            std::ifstream input(path);
            Deserialize(input);
            return input;
        }

        std::ostream& bow::Serialize() {
            std::ofstream output("output.txt");
            Serialize(output);
            output.close();
            return output;
        }

        std::istream& bow::Deserialize() {
            std::ifstream input("output.txt");
            Deserialize(input);
            input.close();
            return input;
        }
}