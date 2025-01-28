//#include "Battle.h"
//#include"team.h"
//#include<vector>
//void Battle::Stop()
//{
//
//}
//
//Battle::BattleTeam& Battle::GetRandomTeam()
//{
//	int rand_index;
//	do
//	{
//		rand_index = rand() % teams.size();
//	} while (teams[rand_index].team->isDead() && !teams[rand_index].haveatakted);
//
//	return teams[rand_index];
//}
//
//Battle::Battle()
//	: max_teams(2), turns_count(20)
//{
//
//}
//
//Battle::Battle(std::initializer_list<Team> list)
//{
//	const Team* begin = list.begin();
//	for (size_t i = 0; i < list.size(); i++)
//	{
//		teams.push_back(BattleTeam(const_cast<Team*>(begin), i));
//	}
//	max_teams = list.size();
//	turns_count = 20;
//}
//
//void Battle::Append(const Team& team)
//{
//	if (teams.size() == max_teams)
//		throw std::exception("Max teams");
//	teams.push_back(BattleTeam(const_cast<Team*>(&team), teams.back().team_id + 1));
//}
//
//void Battle::Start()
//{
//	BattleTeam& firstTeam = GetRandomTeam();
//	team* target;
//
//	/*std::vector<BattleTeam> targets;
//	for (size_t i = 0; i < teams.size(); i++)
//	{
//		if (teams[i].team_id != firstTeam.team_id)
//		{
//			targets.push_back(std::move(teams[i]));
//		}
//	}*/
//
//	while (true) {
//		for (size_t i = 0; i < teams.size(); i++)
//		{
//			if (firstTeam.team_id != teams[i].team_id)
//			{
//				if (firstTeam.CanTurn())
//				{
//					target = teams[i].team;
//					firstTeam.team->Attack(*teams[i].team);
//					firstTeam.Turn();
//					if (true)
//					{
//
//					}
//				}
//
//			}
//		}
//
//		firstTeam.haveatakted = false;
//
//		firstTeam = this->GetRandomTeam();
//	}
//}
//
//Battle::BattleTeam::BattleTeam(team* team, int team_id)
//	: team(team), team_id(team_id)
//{
//}
//
//void Battle::BattleTeam::Turn() {
//	
//}