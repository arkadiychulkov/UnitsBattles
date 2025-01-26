#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include "Unit.h"
using UnintSpace::Unit;
class team {
private:
    std::vector<Unit*> units;
    static bool isFirst;
    std::string name;
public:
    team();
    //team(const std::initializer_list<Unit*>& list);
    void SetName(std::string a);
    void Attack(team& enemys);
    void Append(Unit* unit);
    bool isDead();
    Unit& GetTarget(team& trgs);
    std::string& GetName();
};
