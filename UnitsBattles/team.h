#pragma once
#include <vector>
#include <string>
#include <initializer_list>
#include "Unit.h"
#include"ISerializable.h"

using UnintSpace::Unit;

class team : ISerializable {
private:
    std::vector<Unit*> units;
    static bool isFirst;
    std::string name;
    bool haveatakted = false;
public:
    team();
    //team(const std::initializer_list<Unit*>& list);
    void SetName(std::string a);
    void Attack(team& enemys);
    void Append(Unit* unit);
    void show();
    void ResetAfterBattle();

    bool isDead();

    Unit& GetTarget(team& trgs);
    std::string& GetName();

    int Size();
    int Alive();

    std::ostream& Serialize(std::ostream& output) override;
    std::istream& Deserialize(std::istream& input) override;
    std::ostream& Serialize(std::string& path) override;
    std::istream& Deserialize(std::string& path) override;
    std::ostream& Serialize() override;
    std::istream& Deserialize() override;
};
