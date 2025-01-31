#include "team.h"
#include "Unit.h"
#include <cstdlib>
#include"swordsman.h"
#include <ctime>
#include"sword.h"
#include <iostream>
#include<fstream>
#include<vector>

using UnintSpace::Unit;

bool team::isFirst = true;

Unit& team::GetTarget(team& trgs) {
    int rand_index = rand() % trgs.units.size();
    while (trgs.units[rand_index]->IsDead()) {
        rand_index = rand() % trgs.units.size();
    }
    return *trgs.units[rand_index];
}

team::team() {
    if (isFirst) {
        isFirst = false;
        srand(static_cast<unsigned int>(time(0)));
    }
}

void team::show() {
    for (size_t i = 0; i < units.size(); i++) {
        std::cout << *units[i];
    }
}

//team::team(const std::initializer_list<Unit*>& list) {
//    for (auto unit : list) {
//        units.push_back(unit);
//    }
//}

void team::Append(Unit* unit) {
    units.push_back(unit);
}

void team::Attack(team& enem) {
    for (size_t i = 0; i < units.size(); i++) {
        if (enem.isDead())
            break;
        auto& target = GetTarget(enem);
        units[i]->Attak(target);
        std::cout << name;
    }
}

void team::SetName(std::string a) {
    name = a;
}

std::string& team::GetName() {
    return name;
}

bool team::isDead() {
    for (auto unit : units) {
        if (!unit->IsDead()) {
            return false;
        }
    }
    return true;
}

int team::Size() {
    return units.size();
}

int team::Alive() {
    int count = 0;
    for (size_t i = 0; i < units.size(); i++)
    {
        if (!units[i]->IsDead()) {
            count++;
        }
    }
    return count;
}

std::ostream& team::Serialize(std::ostream& output) {
    if (output) {
        output.write(reinterpret_cast<const char*>(&this->isFirst), sizeof(isFirst));
        size_t nameLength = name.size();
        output.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        output.write(name.c_str(), nameLength);
        output.write(reinterpret_cast<const char*>(&this->haveatakted), sizeof(haveatakted));
        size_t uns = units.size();
        output.write(reinterpret_cast<const char*>(&uns), sizeof(uns));
        for (size_t i = 0; i < units.size(); i++)
        {
            units[i]->Serialize(output);
        }
    }
    else {
        std::cout << "cant open w";
    }
    return output;
}

std::istream& team::Deserialize(std::istream& input) {
    if (input) {
        bool nhaveatakted, nisFirst;
        size_t nameLength;
        std::string nname;
        std::vector<Unit*> nunits;

        input.read(reinterpret_cast<char*>(&nisFirst), sizeof(isFirst));
        input.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        nname.resize(nameLength);
        input.read(&nname[0], nameLength);
        input.read(reinterpret_cast<char*>(&nhaveatakted), sizeof(haveatakted));
        
        size_t unitsSize = 0;
        input.read(reinterpret_cast<char*>(&unitsSize), sizeof(unitsSize));
        for (size_t i = 0; i < unitsSize; i++) {
            WeaponSpace::sword Sword(" ", 0);
            Unit* tun = new UnintSpace::swordsman(" ", Sword, 0, 0);;
            tun->Deserialize(input);
            nunits.push_back(tun);
        }

        isFirst = nisFirst;
        name = nname;
        haveatakted = nhaveatakted;
        units = nunits;
    }
    else {
        std::cout << "cant open";
    }
    return input;
}

std::ostream& team::Serialize(std::string& path) {
    std::ofstream output(path);
    Serialize(output);
    return output;
}

std::istream& team::Deserialize(std::string& path) {
    std::ifstream input(path);
    Deserialize(input);
    return input;
}

std::ostream& team::Serialize() {
    std::ofstream output("output.txt");
    Serialize(output);
    output.close();
    return output;
}

std::istream& team::Deserialize() {
    std::ifstream input("output.txt");
    Deserialize(input);
    input.close();
    return input;
}