#pragma once
#include<vector>
#include"team.h"
#include<initializer_list>

class Battle
{
    struct BattleTeam
    {
        team* team;
        int team_id;
        bool haveatakted = false;
        BattleTeam(::team* teamm, int team_id, int maxturncounts);
    };
private:
    std::vector<BattleTeam> teams;
    int max_teams;
    int turns_count;
    void Stop();
    BattleTeam& GetRandomTeam();
public:
    Battle();
    Battle(std::initializer_list<team> list);
    void Append(const team& team);
    void Start();
    void Turn();
};