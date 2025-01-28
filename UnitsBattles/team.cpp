#include "team.h"
#include "Unit.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

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